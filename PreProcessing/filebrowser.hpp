//----------------------------------------
// Project: Multispectral Image PreProcessing Tool
// Partially developed by: pr5syl3ed
// Date: 2017-08-18
//----------------------------------------

// OpenCV License
//
//By downloading, copying, installing or using the software you agree to this license.
//If you do not agree to this license, do not download, install, copy or use 
//the software.
//
//License Agreement
//For Open Source Computer Vision Library
//(3 - clause BSD License)
//
//Redistribution and use in source and binary forms, with or without 
//modification, are permitted provided that the following conditions are met :
//
//- Redistributions of source code must retain the above copyright notice,
//this list of conditions and the following disclaimer.
//
//- Redistributions in binary form must reproduce the above copyright notice, 
//this list of conditions and the following disclaimer in the documentation 
//and/or other materials provided with the distribution.
//
//- Neither the names of the copyright holders nor the names of the contributors
//may be used to endorse or promote products derived from this
//software without specific prior written permission.
//
//This software is provided by the copyright holders and contributors �as is� 
//and any express or implied warranties, including, but not limited to, 
//the implied warranties of merchantability and fitness for a 
//particular purpose are disclaimed.In no event shall copyright 
//holders or contributors be liable for any direct, indirect, 
//incidental, special, exemplary, or consequential damages(including, 
//but not limited to, procurement of substitute goods or services; 
//loss of use, data, or profits; or business interruption) however 
//caused and on any theory of liability, whether in contract, 
//strict liability, or tort(including negligence or otherwise) 
//arising in any way out of the use of this software, even if advised 
//of the possibility of such damage.
//
//
//Copyright[yyyy][name of copyright owner]
//
//Licensed under the ImageMagick License(the "License"); you may not use
//this file except in compliance with the License.You may obtain a copy
//of the License at
//
//https ://www.imagemagick.org/script/license.php
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.See the
//License for the specific language governing permissions and limitations
//under the License.
//
//
//
//
//
//
//
//
//GDAL / OGR Licensing
//==================
//Copyright(c) 2000, Frank Warmerdam
//
//Permission is hereby granted, free of charge, to any person obtaining a
//copy of this software and associated documentation files(the "Software"),
//to deal in the Software without restriction, including without limitation
//the rights to use, copy, modify, merge, publish, distribute, sublicense,
//and/or sell copies of the Software, and to permit persons to whom the
//Software is furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included
//in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
//THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//DEALINGS IN THE SOFTWARE.
//
//
//
// License dirent.h
//
//The MIT License(MIT)
//
//Copyright(c) 2015 Toni R�nkk�
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
//
//
//
// LIBTIFF License
//
//Copyright(c) 1988 - 1997 Sam Leffler
//Copyright(c) 1991 - 1997 Silicon Graphics, Inc.
//
//Permission to use, copy, modify, distribute, and sell this software and
//its documentation for any purpose is hereby granted without fee, provided
//that(i) the above copyright notices and this permission notice appear in
//all copies of the software and related documentation, and (ii)the names of
//Sam Leffler and Silicon Graphics may not be used in any advertising or
//publicity relating to the software without the specific, prior written
//permission of Sam Leffler and Silicon Graphics.
//
//THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
//EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
//WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
//
//IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR
//ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
//OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
//WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF
//LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
//OF THIS SOFTWARE.
//#pragma once
#include "stdafx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>
#include <tiffio.h>
#include <tiff.h>
#include <math.h>
#include "opencv2/features2d.hpp" //xfeat
#include <Magick++.h>
#include <list>
#include <filesystem>
#include <dirent.h>
#include <sstream>
#include <stdlib.h>
#include <direct.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <cstdarg>
#include <bitset>
//#include <windows.h>
//#include <gdiplus.h>
#include <stdarg.h>


using namespace cv;
using namespace std;
using namespace Magick;
//using namespace Gdiplus;


class filebrowser {
private:
	//string* folderfiles = new string[2048];
	//bool mask[2048];
	string separator = "\\\\"; //keep in mind a slash has to contain two of '\'
	bool sorting = true; //flag for sorting algorithm
	unsigned int tmp_sort[2048]; 
	string filenames_legal[2048]; //filename array max 2048 files
	string filenames[2048]; //filename array max 2048 files
	unsigned int counter = 0;
	string file_ending = ".tif"; //file ending syntax to search for
	unsigned int n_img = 0; //number of existing images
	unsigned int tmp = 0;
	string tmp_str;
	DIR *dir; //pointer for buffering file
	struct  dirent *ent;  //pointer for buffering file
	unsigned int tmp_counter = 0;
	string absolute_folder_path;
	unsigned int n_folders = 0;
	string folders[50];
	string subfoldernames[50];
	unsigned int counter1=0;
	unsigned int last_blackframe;
public:
	filebrowser(string, unsigned int); //constructor & analyze this folderpath
	string getfilename(void); //get next valid filename
	bool end(void); //are all images processed?
	unsigned int get_frame_state(void); //which frame are we processing
	unsigned int getImagenumber(void);
	void LoadNextImage(void);
	bool is_blackframe(void);
};
