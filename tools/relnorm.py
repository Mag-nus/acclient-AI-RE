import struct
def load(path):
    b=bytearray(open(path,'rb').read())
    pe=struct.unpack_from('<I',b,0x3C)[0]
    nsec=struct.unpack_from('<H',b,pe+6)[0]; oh=struct.unpack_from('<H',b,pe+20)[0]
    o=pe+24+oh; secs={}
    for i in range(nsec):
        h=b[o+i*40:o+i*40+40]; nm=h[:8].rstrip(b'\0').decode()
        vs,va,rs,ro=struct.unpack_from('<IIII',h,8); secs[nm]=(va,vs,ro,rs)
    def r2f(rva):
        for nm,(va,vs,ro,rs) in secs.items():
            if va<=rva<va+max(vs,rs): return ro+(rva-va)
        return None
    # walk .reloc
    rva,vs,ro,rs=secs['.reloc']
    relocs=set(); p=ro; end=ro+rs
    while p<end-8:
        page,blk=struct.unpack_from('<II',b,p)
        if blk==0 or blk<8: break
        for k in range((blk-8)//2):
            e=struct.unpack_from('<H',b,p+8+k*2)[0]
            typ,off=e>>12,e&0xFFF
            if typ==3: relocs.add(page+off)      # IMAGE_REL_BASED_HIGHLOW
        p+=blk
    return b,secs,r2f,relocs
def normalize(b,secs,r2f,relocs):
    """zero every relocated dword and every E8/E9/0F8x rel32 inside .text"""
    n=bytearray(b)
    for rva in relocs:
        f=r2f(rva)
        if f is not None and f+4<=len(n): n[f:f+4]=b'\0\0\0\0'
    va,vs,ro,rs=secs['.text']
    i=ro; end=ro+min(vs,rs)
    while i<end-5:
        op=n[i]
        if op in (0xE8,0xE9):
            n[i+1:i+5]=b'\0\0\0\0'; i+=5; continue
        if op==0x0F and 0x80<=n[i+1]<=0x8F:
            n[i+2:i+6]=b'\0\0\0\0'; i+=6; continue
        i+=1
    return bytes(n)
