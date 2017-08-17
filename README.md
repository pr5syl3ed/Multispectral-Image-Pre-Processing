# Multispectral-Image-Pre-Processing Tool
For multi lens, multi-channel imagers.

This tool processes image all at once without steps in between. Before starting the process you can change settings in the GUI Window.

Features:
- Processing images from multiple input folders 
- Duplicate file name support
- Timelapse support
- lens unvignetting
- lens undistortion
- dark frame subtraction
- Band alignment
- Band cropping
- Band stacking

Requirements:
- Microsoft Visual Studio Community 2017
- ImageMagick
- OpenCV
- Libtiff

Installation:
1.0 Install Microsoft Visual Studio Community 2017
1.1 Install Visual Studio Universal Windows Platform develeopment
1.2 Install Visual Studio Desktop development with c++
1.3 Install Visual Studio .NET Desktop development
1.4 Install Visual Studio .NET Core cross-platform development (optional)
2.0 Install ImageMagick-7.0.6-1-Q16-x64-dll.exe checking the following boxes in the installation window:
- Add application directory to your system path (this should set environment variables, if not do it manually)
- install FFmpeg
- Install development headers and libraries for c and c++
- ImageMagickobject OLE control for VBscript, visual basic
2.1 In case ImageMagick install setup should not set up environment variable, add another it yourself. Add an entry into "path" system environment variable c:\Programs\ImageMagick-x.y.z (your imagemagick installation directory may be called different)
3.0 Install OpenCV 3.2 Win-Pack (the pre-compiled version)
3.1 Create a "OpenCV_DIR" user variable pointing to path c:\where_your_extraced_opencv_folder_is\opencv\build
4.0 Download tiff-4.0.7 source folder from http://www.simplesystems.org/libtiff/
4.1 Open "x64 Native Tools Command Prompt for VS2017" (command line)
4.2 Navigate to your tiff folder (ex. cd c:\Users\developer\tiff)
4.3 nmake /f Makefile.vc (you compile the tiff source files)
4.4 When compiling completed successfully you should be able to find a libtiff.lib and .dll file in the folder or sub-folder (for later)
5.0 Download the content of dirent.h from https://code.woboq.org/userspace/glibc/dirent/dirent.h (for later)



Support:
- 16bit bit-depth TIF (.tif) files

Realization:
- Object Based c++
- Windows Form GUI .NET CLR
