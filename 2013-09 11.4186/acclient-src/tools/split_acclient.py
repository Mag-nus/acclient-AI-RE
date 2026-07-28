import pickle,re,os,collections
import sys
HERE=os.path.dirname(os.path.abspath(__file__))
ROOT=os.path.dirname(HERE)+"/.."          # the 11.4186 folder
ROOT=os.path.abspath(ROOT)
OUT=os.path.abspath(os.path.join(HERE,os.pardir))
raw=pickle.load(open(os.path.join(HERE,'pdb_symbols.pkl'),'rb'))
mods=raw['mods']
byva={p[0]:p for p in raw['procs']}
pubva=collections.defaultdict(list)
for name,va in raw['pubs'].items(): pubva[va].append(name)


# ---------------------------------------------------------------------------
# MSVC compiler-generated names are emitted by Hex-Rays with backtick/apostrophe
# decoration, e.g.  `scalar deleting destructor'.  The backtick is not a C token
# and the apostrophe opens a character literal that never closes, which makes
# every editor and IntelliSense engine mis-parse the rest of the line and often
# the lines after it.  Rewrite them to plain identifiers.
#
# The transform is purely textual and fully reversible:
#     `some name'  ->  some_name        (spaces to underscores)
#     `2'          ->  _2               (leading digit gets an underscore)
# It only fires on a backtick and a closing apostrophe on the SAME line with no
# intervening quote, so byte 0x60 appearing inside string literals (the GUID
# initialisers) is left alone.
MANGLED = re.compile(r"`([^`'\n]{0,60})'")
def sanitize(text):
    def rep(m):
        n = m.group(1).replace(' ', '_')
        return ('_' + n) if (n and n[0].isdigit()) else n
    return MANGLED.sub(rep, text)

def modpath(mi):
    try: p=mods[mi]['mod']
    except: return ('_other','misc','unknown')
    p=p.replace('/','\\'); low=p.lower()
    base=re.sub(r'\.(obj|rc|lib)$','',p.split('\\')[-1],flags=re.I)
    parts=low.split('\\'); layer,lib='_other','misc'
    for i,seg in enumerate(parts):
        if seg=='obj' and i+2<len(parts): layer=parts[i+1].upper(); lib=parts[i+2]; break
    if parts[:2]==['obj','i386']: layer,lib='_runtime','msvcrt'
    elif 'intel' in low: layer,lib='_runtime','intel_jpeg'
    elif layer=='_other' and 'core_dev' in low: layer='CORE'
    return (layer,lib,base)

def classify_pub(names):
    n=names[0]
    if 'D3DX' in n: return ('_runtime','d3dx9')
    if re.match(r'^_?(mem|str|wcs|_?f?printf|malloc|free|calloc|realloc|atexit|exit|abort|sprintf|sscanf|qsort|bsearch|rand|srand|time|clock|fopen|fclose|fread|fwrite)',n.lstrip('_?')):
        return ('_runtime','msvcrt')
    if n.startswith('_ijl') or 'IJL' in n or 'ijl' in n: return ('_runtime','intel_jpeg')
    return ('_runtime','static_libs')

src=open(os.path.join(ROOT,"acclient.c"),encoding='latin-1').read().split('\n')
pat=re.compile(r'^//----- \(([0-9A-Fa-f]{8})\) -')
marks=[(i,int(m.group(1),16)) for i,l in enumerate(src) if (m:=pat.match(l))]
first=marks[0][0]
hdr=src[:first]
pi=next((i for i,l in enumerate(hdr) if 'Function declarations' in l),14)
di=next((i for i,l in enumerate(hdr) if 'Data declarations' in l),len(hdr))
BAN=("/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186\n"
     "   (Asheron's Call, September 2013).  Split by original .obj module using the\n"
     "   symbol and module records in the shipped acclient.pdb.\n"
     "   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.\n"
     "   Every function keeps its original acclient.c line number, so existing\n"
     "   acclient.c:NNNNN citations still resolve. */\n\n")
def w(p,lines):
    os.makedirs(os.path.dirname(p),exist_ok=True)
    open(p,'w',encoding='latin-1').write(BAN+sanitize('\n'.join(lines).rstrip())+'\n')
w(os.path.join(OUT,"include","acclient_prologue.h"),hdr[:pi])
w(os.path.join(OUT,"include","acclient_protos.h"),hdr[pi:di])
w(os.path.join(OUT,"include","acclient_data.h"),hdr[di:])

buckets=collections.defaultdict(list); stats=collections.Counter(); noname=0
for k,(li,va) in enumerate(marks):
    end=marks[k+1][0] if k+1<len(marks) else len(src)
    block=src[li:end]
    rec=byva.get(va)
    if rec:
        nm=rec[2]; layer,lib,base=modpath(rec[3])
    elif va in pubva:
        nm=pubva[va][0]; layer,lib=classify_pub(pubva[va]); base=lib
    else:
        nm='sub_%08X'%va; layer,lib,base='_runtime','static_libs','static_libs'; noname+=1
    block=[block[0]+"  // acclient.c:%d"%(li+1)]+block[1:]
    buckets[(layer,lib,base)].append((va,nm,block)); stats[layer]+=1
INC=('#include "%sinclude/acclient_prologue.h"\n'
     '#include "%sinclude/acclient_types.h"\n'
     '#include "%sinclude/acclient_protos.h"\n'
     '#include "%sinclude/acclient_data.h"\n')
manifest=[]
for (layer,lib,base),items in sorted(buckets.items()):
    items.sort()
    rel=os.path.join(layer,lib,base+".c"); path=os.path.join(OUT,"src",rel)
    os.makedirs(os.path.dirname(path),exist_ok=True)
    up='../'*(rel.count(os.sep)+1)
    head=(BAN+"/* Module     : %s\n   Object     : %s\\%s\\%s.obj\n   Functions  : %d\n"
          "   Addresses  : %08X - %08X */\n\n"%(base,layer,lib,base,len(items),
          items[0][0],items[-1][0])+(INC%(up,up,up,up))+"\n")
    with open(path,'w',encoding='latin-1') as f:
        f.write(head)
        for va,nm,block in items: f.write(sanitize('\n'.join(block).rstrip())+'\n\n')
    manifest.append((layer,lib,base,len(items),rel,items[0][0],items[-1][0]))
pickle.dump(manifest,open(os.path.join(HERE,'manifest.pkl'),'wb'))
print("functions: %d ; files: %d ; still unnamed: %d"%(len(marks),len(manifest),noname))
for k,v in stats.most_common(): print("   %-12s %6d"%(k,v))
