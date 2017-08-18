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
//This software is provided by the copyright holders and contributors “as is” 
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
//Copyright(c) 2015 Toni Rönkkö
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
//
#pragma once
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
#include "filebrowser.hpp"


using namespace cv;
using namespace std;
using namespace Magick;
//using namespace Gdiplus;


filebrowser::filebrowser(string folderpath, unsigned int x) {
	last_blackframe = x;
	absolute_folder_path = folderpath; //save folderpath
	
	// get filenames within main folder
	if ((dir = opendir(folderpath.c_str())) != NULL) {
		while ((ent = readdir(dir)) != NULL) { //while there are unread elements
			subfoldernames[counter] = ent->d_name;  //load all file names into stringarray
													//printf("%s\n", ent->d_name);
			if (subfoldernames[counter].length() == 3 &&
				(subfoldernames[counter].c_str()[0] - 48) >= 0 && (subfoldernames[counter].c_str()[0] - 48) <= 9 && // is first character a number?
				(subfoldernames[counter].c_str()[1] - 48) >= 0 && (subfoldernames[counter].c_str()[1] - 48) <= 9 && // is second character a number?
				(subfoldernames[counter].c_str()[2] - 48) >= 0 && (subfoldernames[counter].c_str()[2] - 48) <= 9) { // is third character a number?
				folders[n_folders] = absolute_folder_path + "\\"+subfoldernames[counter];
				n_folders++;
			}
			counter++;
		}
		closedir(dir); //close directory
	}
	else {
		perror("");
		//cout << "Error while reading folder!" << endl;
		throw std::exception();
	}

	counter = 0;
	n_img = 0;
	while (counter <= (n_folders-1)) {
		dir = opendir(folders[counter].c_str());

		while ((ent = readdir(dir)) != NULL) { //while there are unread elements
			tmp_str = ent->d_name;  //load all file names into stringarray
			if (!(tmp_str.find(file_ending) != string::npos)) {
				// if this file has no .tif ending don't use it
			}
			else {
				// if file has .tif ending use it and load it to second legal array
				filenames_legal[n_img] = folders[counter]+"\\"+tmp_str;
				n_img++;
			}
			//cout << filenames_legal[n_img] << endl;
		}
		counter++;
		closedir(dir); //close directory
	}

	//if number of images is not multiple of 5
	if (n_img % 5 != 0) {
		//cout << "Error number of input images is not multiple of 5" << endl;
		throw std::exception();
	}
	else { //if multiple of 5
		//cout << "Message " << n_img << " images found in directory" << endl;
		//cout << filenames_legal[0] << endl; cout << filenames_legal[1] << endl;
	}
	counter = 0;
	
	// calculate number for each image and save to array (IMG_0001_1.tif is 11 and IMG_9999_5.tif would be 10'004)
	while (counter <= (n_img-1)) {
		tmp_sort[counter] = (
			(stoi(filenames_legal[counter].substr(filenames_legal[counter].length() - 10, 4))+1)*10 + //_xxxx_
			stoi(filenames_legal[counter].substr(filenames_legal[counter].length() - 5, 1)) + // _x.
			(stoi(filenames_legal[counter].substr(filenames_legal[counter].length() - 16, 3))+1) * 100000 //folder
			);

			counter++;
	}
	counter = 0;
	//sort files on their filename (framenuber and bandnumber)
	while (sorting == true) {
		//cout << tmp_sort[0] << " " << tmp_sort[1] << " " << tmp_sort[2] << " " << tmp_sort[3] << " " << tmp_sort[4] << endl;
		if (tmp_sort[counter] < tmp_sort[counter+1]) {

			if ((counter+2) < n_img) {
				counter++;
			}
			else{
				sorting = false; //sorting finished
				counter = 0;
			}
		}
		else { //Swap two elements
			//swap number array
			tmp = tmp_sort[counter];
			tmp_sort[counter] = tmp_sort[counter + 1];
			tmp_sort[counter + 1] = tmp;
			
			//swap filename array
			tmp_str = filenames_legal[counter];
			filenames_legal[counter] = filenames_legal[counter + 1];
			filenames_legal[counter + 1] = tmp_str;
			counter = 0;
		}
	}
}

bool filebrowser::is_blackframe(void) {
	//check if frame is blackframe

	if ((tmp_sort[counter] - 1) % 10 == 0) { //if x-1 dividable by 10 then it's channel 1
		tmp = tmp_sort[counter] - 1;
	}else if((tmp_sort[counter] - 2) % 10 == 0 ){
		tmp = tmp_sort[counter] - 2;
	}else if ((tmp_sort[counter] - 3) % 10 == 0 ) {
		tmp = tmp_sort[counter] - 3;
	}else if ((tmp_sort[counter] - 4) % 10 == 0) {
		tmp = tmp_sort[counter] - 4;
	}else if ((tmp_sort[counter] - 5) % 10 == 0) {
		tmp = tmp_sort[counter] - 5;
	}

	if ((last_blackframe - 1) % 10 == 0) { //if x-1 dividable by 10 then it's channel 1
		if (last_blackframe - 1 >= tmp) {
			return(true);
		}
		else {
			return(false);
		}
	}
	else if ((last_blackframe - 2) % 10 == 0) {
		if (last_blackframe - 2 >= tmp) {
			return(true);
		}
		else {
			return(false);
		}
	}
	else if ((last_blackframe - 3) % 10 == 0) {
		if (last_blackframe - 3 >= tmp) {
			return(true);
		}
		else {
			return(false);
		}
	}
	else if ((last_blackframe - 4) % 10 == 0) {
		if (last_blackframe - 4 >= tmp) {
			return(true);
		}
		else {
			return(false);
		}
	}
	else if ((last_blackframe - 5) % 10 == 0) {
		if (last_blackframe - 5 >= tmp) {
			return(true);
		}
		else {
			return(false);
		}
	}
}

string filebrowser::getfilename(void) {
	tmp_str = filenames_legal[counter]; //return full filepath
	return(tmp_str);
}

unsigned int filebrowser::getImagenumber(void) {
	return(tmp_sort[counter]);
}

void filebrowser::LoadNextImage(void) {
	counter++;
}

bool filebrowser::end(void) {
	if (counter >= (n_img-1)) { 
		return(true); //if last frame processed
	}
	else {
		return(false); //if there are more frames
	}
}

unsigned int filebrowser::get_frame_state(void) {
		return(counter);
}