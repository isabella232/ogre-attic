# Microsoft Developer Studio Project File - Name="RenderSystem_Direct3D8" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RenderSystem_Direct3D8 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RenderSystem_Direct3D8.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RenderSystem_Direct3D8.mak" CFG="RenderSystem_Direct3D8 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RenderSystem_Direct3D8 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RenderSystem_Direct3D8 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/S&S/DEV/Ogrenew/RenderSystem_Direct3D8", SEDAAAAA"
# PROP Scc_LocalPath ".."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RenderSystem_Direct3D8 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin\Release"
# PROP Intermediate_Dir "..\obj\Release"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OGRED3DENGINEDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /Ob0 /I "..\include" /I "..\..\..\OgreMain\include" /I "..\..\..\Dependencies\include" /D "_USRDLL" /D "OGRED3D8ENGINEDLL_EXPORTS" /D "NDEBUG" /D "_MBCS" /D "OGRE_WIN32" /D "_WINDOWS" /D "WIN32" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 libpng.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib zlib.lib OgreMain.lib d3d8.lib d3dx8.lib dxerr8.lib /nologo /dll /machine:I386 /nodefaultlib:"LIBC" /libpath:"../../../OgreMain/Lib/Release" /libpath:"..\..\..\Dependencies\lib\Debug"
# SUBTRACT LINK32 /profile /debug
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy ..\bin\Release\*.dll ..\..\..\Samples\Common\bin\Release
# End Special Build Tool

!ELSEIF  "$(CFG)" == "RenderSystem_Direct3D8 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin\Debug"
# PROP Intermediate_Dir "..\obj\Debug"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OGRED3DENGINEDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\include" /I "..\..\..\OgreMain\include" /I "..\..\..\Dependencies\include" /D "_USRDLL" /D "OGRED3D8ENGINEDLL_EXPORTS" /D "_MBCS" /D "_WINDOWS" /D "_DEBUG" /D "WIN32" /FD /GZ /c
# SUBTRACT CPP /Fr /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libpng.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib dxguid.lib zlib.lib OgreMain.lib libpng.lib jpegLib.lib d3d8.lib d3dx8.lib dxerr8.lib /nologo /dll /debug /machine:I386 /nodefaultlib:"LIBCD" /nodefaultlib:"LIBCMT" /pdbtype:sept /libpath:"../../../OgreMain/Lib/Debug" /libpath:"..\..\..\Dependencies\lib\Debug"
# SUBTRACT LINK32 /verbose
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy ..\bin\Debug\*.dll ..\..\..\Samples\Common\bin\Debug
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "RenderSystem_Direct3D8 - Win32 Release"
# Name "RenderSystem_Direct3D8 - Win32 Debug"
# Begin Group "D3dEngine"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\d3dfont.cpp
# End Source File
# Begin Source File

SOURCE=..\include\d3dfont.h
# End Source File
# Begin Source File

SOURCE=..\include\dxutil.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8Device.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8Device.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8DeviceList.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8DeviceList.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8Driver.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8Driver.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8DriverList.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8DriverList.h
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8Prerequisites.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8RenderSystem.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8RenderSystem.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8RenderWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8RenderWindow.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8Texture.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8Texture.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8TextureManager.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8TextureManager.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8VideoMode.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8VideoMode.h
# End Source File
# Begin Source File

SOURCE=..\src\OgreD3D8VideoModeList.cpp
# End Source File
# Begin Source File

SOURCE=..\include\OgreD3D8VideoModeList.h
# End Source File
# End Group
# Begin Group "Interface"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\OgreD3D8EngineDll.cpp
# End Source File
# Begin Source File

SOURCE=..\misc\OgreD3D8RenderSystem.def
# End Source File
# End Group
# End Target
# End Project
