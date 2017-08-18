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
#pragma once //only include files once
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
#include "band.hpp"


using namespace cv;
using namespace std;
using namespace Magick;
//using namespace Gdiplus;


band::band(unsigned int x) { //constructor
	blackframeID_last_before = x;
}



void band::loadBitmap(string filename, bool is_bl) { //load image, filename and metadata
	is_blackframe = is_bl;
	filepath = filename; //set object internal variable
	//cout << "loading";
	//load image and filename
	channel = filename.at(filename.length() - 5) - 48; //extract channel number from filename. The 5th last character is channel number. Convert Asci to Int
	bitmap = cv::imread(filename, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_GRAYSCALE); //load the image at 16bit and grayscale
	buffer = cv::imread(filename, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_GRAYSCALE); //load the image at 16bit and grayscale to a second variable

	//load standard meta tags from metadata
	TIFF* tif = TIFFOpen(filename.c_str(), "r"); //open image file on hard drive
	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &tmp1);  //image width in pixels,
	xRes = *tmp; //save width
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &tmp1);  //image length in pixels
	yRes = *tmp; //save heigth
	TIFFGetField(tif, TIFFTAG_BITSPERSAMPLE, &tmp1);  //bitdepth
	bitDepth = *tmp; //save bitdepth

	TIFFClose(tif); //close image file on hard drive

	//load private meta tags from metadata (camera specific)
	ifstream inFile; //initialize a file object
	inFile.open(filename.c_str(), ios::in | ios::binary); //open the image file
	inFile.ignore(4);  //skip this first bytes in file
	inFile.read(tmp, 4);  //read 255 bytes. The bytes 4-7 contain jump adress to next ifd
	inFile.close(); //close file

	//convert big endian adress
	adress = unsigned int (tmp[3] & 255) * 256 * 256 * 256 + //the 7 byte in file is heigest
		unsigned int(tmp[2] & 255) * 256 * 256 + //the 6 byte in file is second heighest
		unsigned int(tmp[1] & 255) * 256 + //the 5 byte in file is second lowest
		unsigned int(tmp[0] & 255); //the 4 byte in file is lowest

	//Read Blacklevel
	inFile.open(filename.c_str(), ios::in | ios::binary); //open file again
	inFile.ignore(adress - 192);  //go 192 bytes back from IFD adress (blacklevels are situated there)
	inFile.read(tmp, 255);  //read 255 bytes
	blacklevel[0] = (uint16)(uint8)tmp[0] + (uint8)tmp[1] * 256; //Big endian conversion for oddrow
	blacklevel[1] = (uint16)(uint8)tmp[2] + (uint8)tmp[3] * 256; //Big endian conversion for evenrow
	blacklevel[2] = (uint16)(uint8)tmp[4] + (uint8)tmp[5] * 256; //Big endian conversion for oddcol
	blacklevel[3] = (uint16)(uint8)tmp[6] + (uint8)tmp[7] * 256; //Big endian conversion for evencol
	inFile.close(); //close file again
}

unsigned int band::getchannel(void) {
	return(channel); //return channel number of current image
}

cv::Mat band::getbitmap(void) {
	return(bitmap); //return actual image
}

void band::unvignette(void) {

	//Initialize 2D array for unvignetting factor
	vector<vector<double> > k;
	k.resize(1280);
	for (int i = 0; i < 1280; ++i)
		k[i].resize(960);

	//Initialize 2D array for unvignetting distance from center
	vector<vector<double> > r;
	r.resize(1280);
	for (int i = 0; i < 1280; ++i)
		r[i].resize(960);


	while (x <= 1279) {
		while (y <= 959) {

			//calculate distance from center (see camera manual)
			r[x][y] = sqrt(pow(xd - cx_vign[channel - 1], 2) + pow(yd - cy_vign[channel - 1], 2));
			
			//calculate vignetting factor (see camera specification file)
			k[x][y] = 1 +
				k1_vign[channel-1] * r[x][y] + 
				k2_vign[channel - 1] * pow(r[x][y], 2) + 
				k3_vign[channel - 1] * pow(r[x][y], 3) + 
				k4_vign[channel - 1] * pow(r[x][y], 4) + 
				k5_vign[channel - 1] * pow(r[x][y], 5) + 
				k6_vign[channel - 1] * pow(r[x][y], 6);
			
			//apply pixel dependent vignetting factor on pixels
			intensity = bitmap.at<ushort>(y, x);
			(double)blue = (ushort)intensity.val[0];
			blue = (double)1 / (double)k[x][y] * blue;

			//in case that new value is greater than 65535 (or uint16)
			if (blue > 65535.0) {
				(ushort)bitmap.at<ushort>(y, x) = 65535; //set to absolute white
			}
			else {
				(ushort)bitmap.at<ushort>(y, x) = blue;	//write new value into image
			}
			y++; //unsigned integer row counter
			yd = yd + 1; //double row variable
		}

		x++; //unsigned integer column counter
		y = 0; //unsigned integer row counter
		yd = 0.0; //double row variable
		xd = xd + 1; //double col variable

	}
}

void band::undistortion(void) {

	distCoeff = cv::Mat::zeros(8, 1, CV_64FC1); // creates an empty matrix and sets data type 64 float 1 channel for undistortion

	//load undistortion parameters from array
	double k1 = k1_m[channel - 1]; // first channel is 1 (subtracting because undistortion parameter arrays start at 0)
	double k2 = k2_m[channel - 1];
	double k3 = k3_m[channel - 1];
	double k4 = k4_m[channel - 1];
	double k5 = k5_m[channel - 1];
	double k6 = k6_m[channel - 1];
	double p1 = p1_m[channel - 1];
	double p2 = p2_m[channel - 1];

	//load undistortion parameters into proper place of empty array
	distCoeff.at<double>(0, 0) = k1;
	distCoeff.at<double>(1, 0) = k2;
	distCoeff.at<double>(2, 0) = p1;
	distCoeff.at<double>(3, 0) = p2;
	distCoeff.at<double>(4, 0) = k3;
	distCoeff.at<double>(5, 0) = k4;
	distCoeff.at<double>(6, 0) = k5;
	distCoeff.at<double>(7, 0) = k6;

	// camera intrinsics
	cam1 = cv::Mat::eye(3, 3, CV_32FC1);
	cam1.at<float>(0, 0) = fx_m[channel - 1]; //focal length x
	cam1.at<float>(0, 1) = 0; // skew?
	cam1.at<float>(0, 2) = cx_m[channel - 1]; //x center

	cam1.at<float>(1, 0) = 0;
	cam1.at<float>(1, 1) = fy_m[channel - 1]; //focal length y
	cam1.at<float>(1, 2) = cy_m[channel - 1]; //y center

	//start undistortion
	cv::undistort(bitmap, buffer, cam1, distCoeff);
	bitmap = buffer; //load image back to old variable
}

void band::denoise(void) {

	if (is_blackframe == true) { //if the current image is a black image
		bitmap.convertTo(blackframe[counter],CV_64F); //save the black image into an array
		bitmap.convertTo(master_blackframe, CV_64F);
		counter++;
		was_blackframe = true;	//this is a reminder that last image was black image
	}
	else { //if the following images are normal images
		if (was_blackframe == true) { //if dark frames passed
			counter_denoise++;
			was_blackframe = false;
			counter_denoise = 0;
			master_blackframe = master_blackframe * 0;
			
			while (counter_denoise <= (counter-1)) {
				master_blackframe = master_blackframe + blackframe[counter_denoise];
				counter_denoise++;
			}

			master_blackframe = master_blackframe / (double)counter;
		}
		bitmap.convertTo(bitmap_signed, CV_64F);
		bitmap_signed = bitmap_signed - master_blackframe;
		//row_counter = 0;
		//col_counter = 0;
		//while (col_counter <= 1279) {
		//	while (row_counter <= 959) {
		//		if ((row_counter + 1) % 2 == 0 && (col_counter + 1) % 2 == 0) { // even row and even column
		//			(double)bitmap_signed.at<double>(row_counter, col_counter) = (double)bitmap_signed.at<double>(row_counter, col_counter) - (double)blacklevel[1];
		//		}
		//		else if ((row_counter + 1) % 2 == 1 && (col_counter + 1) % 2 == 0) { // odd row and even column
		//			(double)bitmap_signed.at<double>(row_counter, col_counter) = (double)bitmap_signed.at<double>(row_counter, col_counter) - (double)blacklevel[0];
		//		}
		//		else if ((row_counter + 1) % 2 == 0 && (col_counter + 1) % 2 == 1) { //even row and odd column
		//			(double)bitmap_signed.at<double>(row_counter, col_counter) = (double)bitmap_signed.at<double>(row_counter, col_counter) - (double)blacklevel[3]; //1023 my opinion
		//		}
		//		else if ((row_counter + 1) % 2 == 1 && (col_counter + 1) % 2 == 1) { //odd row and odd column
		//			(double)bitmap_signed.at<double>(row_counter, col_counter) = (double)bitmap_signed.at<double>(row_counter, col_counter) - (double)blacklevel[2]; //alternatively 2310 ask camera manufacturer
		//		}
		//		row_counter++; //begin new row
		//	}
		//	col_counter++; //begin new column
		//	row_counter = 0;
		//}
		//col_counter = 0;
		bitmap_signed = bitmap_signed; //+ (double)5000.0; //offset for conversion to unsigned shor
		bitmap_signed.convertTo(bitmap, CV_16U);
		//imwrite("c:\\Users\\\\Desktop\\test.tif", bitmap);
	}
}

void band::calibrate(void) {

}

string band::getfilename(void) {
	return(filepath);
}

cv::Mat band::get_masterblackframe(void) {
	return(master_blackframe);
}

bool band::is_bl(void) {
	return(is_blackframe);
}
