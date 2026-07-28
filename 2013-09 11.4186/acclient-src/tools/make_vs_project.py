#!/usr/bin/env python3
"""Regenerate the Visual Studio browsing solution for acclient-src.

Produces acclient.sln / acclient.vcxproj / acclient.vcxproj.filters and
CppProperties.json.  The project is a Makefile-type project so Visual Studio
never attempts to compile the decompiler output; it exists for navigation.
"""
import os,uuid,json
HERE=os.path.dirname(os.path.abspath(__file__))
ROOT=os.path.abspath(os.path.join(HERE,os.pardir))
os.chdir(ROOT)
GUID="{8E3C1A94-7D62-4F0B-9A15-2C6F4B8E1D73}"
srcs=sorted(os.path.join(r,f).replace("/","\\")
            for r,d,fs in os.walk("src") for f in fs if f.endswith(".c"))
hdrs=sorted(os.path.join("include",f).replace("/","\\")
            for f in os.listdir("include") if f.endswith(".h"))
# the IDA type library lives beside the monolith, one level up
hdrs.append("..\\acclient.h")
DEFS="_WIN32;WIN32;__thiscall=__cdecl;__usercall=__cdecl;__userpurge=__cdecl"
proj=['<?xml version="1.0" encoding="utf-8"?>\n',
 '<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">\n',
 '  <ItemGroup Label="ProjectConfigurations">\n',
 '    <ProjectConfiguration Include="Browse|Win32">\n      <Configuration>Browse</Configuration>\n      <Platform>Win32</Platform>\n    </ProjectConfiguration>\n',
 '  </ItemGroup>\n',
 f'''  <PropertyGroup Label="Globals">
    <ProjectGuid>{GUID}</ProjectGuid>
    <RootNamespace>acclient</RootNamespace>
    <Keyword>MakeFileProj</Keyword>
    <WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Browse|Win32'" Label="Configuration">
    <ConfigurationType>Makefile</ConfigurationType>
    <PlatformToolset>v143</PlatformToolset>
    <UseDebugLibraries>false</UseDebugLibraries>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Browse|Win32'">
    <NMakeBuildCommandLine>echo acclient-src is decompiler output for browsing. It does not build.</NMakeBuildCommandLine>
    <NMakeReBuildCommandLine>echo acclient-src is decompiler output for browsing. It does not build.</NMakeReBuildCommandLine>
    <NMakeCleanCommandLine>echo Nothing to clean.</NMakeCleanCommandLine>
    <NMakeOutput>acclient.exe</NMakeOutput>
    <NMakeIncludeSearchPath>$(ProjectDir)include;$(NMakeIncludeSearchPath)</NMakeIncludeSearchPath>
    <NMakePreprocessorDefinitions>{DEFS};$(NMakePreprocessorDefinitions)</NMakePreprocessorDefinitions>
  </PropertyGroup>
''','  <ItemGroup>\n']
proj += ['    <ClInclude Include="%s" />\n'%h for h in hdrs]
proj += ['  </ItemGroup>\n  <ItemGroup>\n']
proj += ['    <ClCompile Include="%s" />\n'%s for s in srcs]
proj += ['  </ItemGroup>\n','  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.targets" />\n</Project>\n']
open("acclient.vcxproj","w",encoding="utf-8").write("".join(proj))

folders={"include"}
for s in srcs:
    parts=s.split("\\")[:-1]
    for i in range(1,len(parts)+1): folders.add("\\".join(parts[:i]))
f=['<?xml version="1.0" encoding="utf-8"?>\n',
   '<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">\n','  <ItemGroup>\n']
f += ['    <Filter Include="%s"><UniqueIdentifier>{%s}</UniqueIdentifier></Filter>\n'
      %(fo,uuid.uuid5(uuid.NAMESPACE_DNS,fo)) for fo in sorted(folders)]
f += ['  </ItemGroup>\n  <ItemGroup>\n']
f += ['    <ClInclude Include="%s"><Filter>include</Filter></ClInclude>\n'%h for h in hdrs]
f += ['  </ItemGroup>\n  <ItemGroup>\n']
f += ['    <ClCompile Include="%s"><Filter>%s</Filter></ClCompile>\n'%(s,"\\".join(s.split("\\")[:-1])) for s in srcs]
f += ['  </ItemGroup>\n</Project>\n']
open("acclient.vcxproj.filters","w",encoding="utf-8").write("".join(f))

open("acclient.sln","w",encoding="utf-8").write(
f'''Microsoft Visual Studio Solution File, Format Version 12.00
# Visual Studio Version 17
VisualStudioVersion = 17.0.31903.59
MinimumVisualStudioVersion = 10.0.40219.1
Project("{{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}}") = "acclient", "acclient.vcxproj", "{GUID}"
EndProject
Global
\tGlobalSection(SolutionConfigurationPlatforms) = preSolution
\t\tBrowse|Win32 = Browse|Win32
\tEndGlobalSection
\tGlobalSection(ProjectConfigurationPlatforms) = postSolution
\t\t{GUID}.Browse|Win32.ActiveCfg = Browse|Win32
\tEndGlobalSection
\tGlobalSection(SolutionProperties) = preSolution
\t\tHideSolutionNode = FALSE
\tEndGlobalSection
EndGlobal
''')

json.dump({"configurations":[{
    "name":"Browse","includePath":["${workspaceRoot}/include","${workspaceRoot}/src"],
    "defines":DEFS.split(";"),
    "intelliSenseMode":"windows-msvc-x86","browse":{
        "path":["${workspaceRoot}/include","${workspaceRoot}/src"],
        "limitSymbolsToIncludedHeaders":False}}]},
    open("CppProperties.json","w"),indent=2)
print("sources=%d headers=%d filters=%d"%(len(srcs),len(hdrs),len(folders)))
