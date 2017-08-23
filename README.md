# Multispectral-Image-Pre-Processing Tool
For multi lens, multi-channel imagers.

This tool processes image all at once without steps in between. Before starting the process you can change settings in the GUI Window.

## Features:
- Processing images from multiple input folders 
- Duplicate file name support
- Timelapse support
- lens unvignetting (k1,k2,k3,k4,k5,k6,p1,p2)
- lens undistortion (k1,k2,k3,k4,k5,k6,p1,p2)
- dark frame subtraction
- Band alignment
- Band cropping
- Band stacking

## Requirements:
- Microsoft Visual Studio Community 2017
- ImageMagick
- OpenCV
- Libtiff
- dirent
- GDAL (optional)
- Git
- Microsoft Windows operating system

### Installation:
- 1.0 Install Microsoft Visual Studio Community 2017
- 1.1 Install Visual Studio Universal Windows Platform develeopment
- 1.2 Install Visual Studio Desktop development with c++
- 1.3 Install Visual Studio .NET Desktop development
- 1.4 Install Visual Studio .NET Core cross-platform development (optional)
- 2.0 Install ImageMagick-7.0.6-1-Q16-x64-dll.exe checking the following boxes in the installation window:
* Add application directory to your system path (this should set environment variables, if not do it manually)
* install FFmpeg
* Install development headers and libraries for c and c++
* ImageMagickobject OLE control for VBscript, visual basic
- 2.1 In case ImageMagick install setup should not set up environment variable, add another it yourself. Add an entry into "path" system environment variable c:\Programs\ImageMagick-x.y.z (your imagemagick installation directory may be called different)
- 3.0 Install OpenCV 3.2 Win-Pack (the pre-compiled version)
- 3.1 Create a "OpenCV_DIR" user variable pointing to path c:\where_your_extraced_opencv_folder_is\opencv\build
- 4.0 Download tiff-4.0.7 source folder from http://www.simplesystems.org/libtiff/
- 4.1 Open "x64 Native Tools Command Prompt for VS2017" (command line)
- 4.2 Navigate to your tiff folder (ex. cd c:\Users\developer\tiff)
- 4.3 nmake /f Makefile.vc (you compile the tiff source files)
- 4.4 When compiling completed successfully you should be able to find a libtiff.lib and .dll file in the folder or sub-folder (for later)
- 5.0 Download the content of dirent.h from https://code.woboq.org/userspace/glibc/dirent/dirent.h (for later)
- 6.0 Download GDAL source files
- 6.1 Open x64 native compiler from visual Studio
- 6.2 cd to the GDAL folder and do "nmake /f makefile.vc MSVC_VER=1900 WIN64=Yes" (this should compile gdal)
- 6.3 cd to the GDAL folder and do "nmake /f makefile.vc devinstall MSVC_VER=1900 WIN64=Yes" (this should compile gdal)
- 7.0 Open command line window and navigate to where you want to save the source code of multispectral-image-pre-processing
- 7.1 Get the source code with git clone https://github.com/pr5syl3ed/Multispectral-Image-Pre-Processing.git
- 7.2 Try to open the visual studio .sln project
- 7.3 You probably have to edit linker paths and vc++ source directory paths going to <code>Project->Project Properties->VC++ Directories->Library and include Directories</code>
- 7.4 You probably have to edit paths in dependencies going to <code>Project->Project Properties->Linker->Input->Additional Dependencies</code>

### Include Directories
- You may have to tell visual studio where external include files are located. Goto "Project">"Properties">"VC++ Directories">"Include Directories" and add your specific paths ex.<code>$(VC_IncludePath);$(WindowsSDK_IncludePath);C:\Program Files\gdal-2.2.0\alg;C:\Program Files\gdal-2.2.0\gcore;C:\Program Files\gdal-2.2.0\ogr;C:\Program Files\gdal-2.2.0\port;C:\Program Files\dirent;C:\Program Files\tiff-4.0.7\libtiff;C:\Program Files\ImageMagick-7.0.5-Q16\include;C:\Program Files\opencv\build\include;$(IncludePath)</code>
- You may have to tell visual studio where external precompiled libraries are located. Goto "Project">"Properties">"VC++ Directories">"Library Directories" and add your specific paths ex. <code>$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64);$(NETFXKitsDir)Lib\um\x64;C:\Program Files\gdal-2.2.0;C:\Program Files\tiff-4.0.7\libtiff;C:\Program Files\ImageMagick-7.0.5-Q16\lib;C:\Program Files\opencv\build\x64\vc14\lib;$(LibraryPath)</code>
- You may want to change Additional Dependencies in VIsual Studio. Goto "Project">"Properties">"Linkes">"Input">"Additional Dependencies" and add or remove precompiled libraries if you want. Ex. <code>gdal_i.lib;libtiff.lib;opencv_world320.lib;CORE_RL_Magick++_.lib;CORE_RL_MagickCore_.lib;CORE_RL_MagickWand_.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;</code>


### Environment Variables
After successfull compilation in Visual studio you may still can't execute the application due to missing precompiled dynamic link libraries .dll. You should change your environment variables in order that your computer knows where to search for the libraries when they are called from your application. Goto Windows Logo and search for system environment variables and open "Environment Variables...". 
- Create a user variable called "OpenCV_DIR" and set the path to the downloaded opencv_folder\build. 
- Edit the user path env. variable adding ...opencv_folder\build\x64\vc14\bin.
- Edit the system Path env. variable and add your_path_to\ImageMagick-7.0.5-Q16 (should already exist)
- Edit the system Path env. variable and add your_path_to\gdal-2.2.0\

Alternatively you could place the .dll files into the folder where your  previously built executable is. If the .dll files are in the same folder as your .exe it will work.

### Setup
- Open the .sln file in visual studio and try to resolve all paths.
- Compile in x64 release mode
- Entry Point Main
- Namespace "PreProcessing"
- Runtime Library "Multi-threaded DLL"

### Support:
- 16bit bit-depth TIF (.tif) files

### Realization:
- Object Based c++ and Windows Form .NET

### Notes:
- You do not to have use all external dependencies included if you don't want use them (some are barely used)
- There are hard-coded camera specific parameters you can change

### Installation/Distribution to non-developers
- Install Visual Studio 2017 as described above (maybe installing Microsoft visual c++ 2015 redistributable suffices)
- Download OpenCV, extract it and put the opencv_world320.dll in the same folder as our compiled .executable
- Install Image magick as described above and put the .dll files in the compiled executable folder
- Download gdal and put gdal202.dll into an .executable folder
- Install Microsoft visual c++ 2013 redistributable x64.
- Try to start the .executable


