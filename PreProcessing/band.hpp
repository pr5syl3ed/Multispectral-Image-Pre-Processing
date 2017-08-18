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

#pragma once //do not read include files twice if already included
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


class band {
private:
	uint32 *tmp1; //temporary pointer
	uint32 xRes; //Image width
	uint32 yRes; //image height
	uint32 bitDepth; //image bitdepth
	char tmp[255]; //buffer for parsing .tif file
	unsigned int blacklevel[4]; //blacklevels 0-4 probably oddrow, evenrow, oddcol, evencol
	long adress; //First ifd adress to jump
	cv::Mat bitmap; //image buffer
	unsigned int x = 0; //unvignetting counter
	unsigned int y = 0;//unvignetting counter
	double xd = 0.0;//unvignetting counter
	double yd = 0.0;//unvignetting counter
	unsigned int channel = 1; //1blue 2green 3red 4NIR 5REdedge
	Vec3s intensity; //unvignetting
	double blue; //unvignetting
	cv::Mat distCoeff; //undistortion
	cv::Mat cam1; //undistortion
	cv::Mat buffer; //undistortion 
	string filepath;
	bool is_blackframe = false;
	cv::Mat blackframe[256]; //stores 16 blackframes
	unsigned int counter = 0;
	unsigned int frame_state = 0;
	cv::Mat master_blackframe;
	bool was_blackframe = false; //if last frame was a black frame but the next one is not
	unsigned int col_counter = 0;
	unsigned int row_counter = 0;
	double mean_col_calc[960]; //unvignetting parameter
	double mean_row_calc[1280]; //unvignetting parameter
	unsigned int tmp_counter = 0;
	unsigned int tmp_integer = 0;
	double row;
	double mean_col;
	unsigned int blacklevel_sorted[4]; //the smallest blacklevel is [0]
	cv::Mat bitmap_signed;
	cv::Mat black_frame_rec_tmp;
	unsigned int counter_denoise = 0;
	cv::Mat abc;
	cv::Mat def;
	unsigned int blackframeID_first_before;
	unsigned int blackframeID_last_before;

	// Hardcoded Undistortion lens parameters for specific camera
	double cx_m[5] = { 643.8893602713686,646.2876348370665, 635.112765023685,650.0172410017597, 640.2070796834802 };
	double cy_m[5] = { 478.9601599362568,487.8870702000254, 475.9487632367042,489.013354837388,476.4464172256909 };
	double fx_m[5] = { 1440.458661165309,1438.025532800022, 1449.574428100889,1448.951418563583, 1445.654664815826 };
	double fy_m[5] = { 1440.756614433281, 1438.404713281228, 1450.17247718981,1449.44316823106, 1446.22861154131 };
	double k1_m[5] = { -0.09667331646150404, -0.1010525208325428, -0.1042476549325377, -0.1087931871993678, -0.1047408687298381 };
	double k2_m[5] = { 0.1521699647928558, 0.1478560987422327,  0.1617802407386409, 0.1682341016318963, 0.1566098332433733 };
	double k3_m[5] = { -0.04861534157162112, -0.03838675728217016, -0.05795061949340015, -0.07950791535676657,-0.05174867374762403 };
	double k4_m[5] = { 0,0,0,0,0 };
	double k5_m[5] = { 0,0,0,0,0 };
	double k6_m[5] = { 0,0,0,0,0 };
	double p1_m[5] = { -0.0001392743237024886, 0.0005756050781485842, -0.0004677471183437311, 7.218071488114875e-05,0.0009096817577642966 };
	double p2_m[5] = { 0.0003938833050405934, 0.0007577955328215453, 0.0008923504691781989,0.0003125173327344626,0.0004917933128005809 };

	// Hardcoded Unvignetting lens parameters for specific camera
	double cx_vign[5] = { 615.0152608933483, 644.3574607588573,637.8219259304681, 634.9355405530644, 651.285524604551 };
	double cy_vign[5] = { 477.6321764467883, 476.9726085013394,478.6311498549013, 479.1132551629033,478.6735660570274 };
	double k1_vign[5] = { -0.0003417783394512867, -0.0003018824102758406,-0.0001337885913441529, 0.0002149127263262391, -6.776451649295096e-05 };
	double k2_vign[5] = { 3.441122739502885e-06,3.455991934675517e-06,1.55949208084643e-06, -4.337508825792706e-06, 2.100633240402365e-07 };
	double k3_vign[5] = { -1.848012657237475e-08, -1.988224398824752e-08, -1.016783227835597e-08, 8.873013544504981e-09,-6.385106893758652e-09 };
	double k4_vign[5] = { 4.49482539293681e-11, 4.997222904095209e-11, 2.399024838594838e-11, -3.598433534409943e-12, 2.022816878372607e-11 };
	double k5_vign[5] = { -5.11116229072061e-14,-5.810650981542908e-14, -2.573233269260111e-14, -7.534529507621262e-15, -2.584696084211612e-14 };
	double k6_vign[5] = { 2.154669597661016e-17, 2.489998847836525e-17, 1.000230573442146e-17, 5.957094806158578e-18, 1.155697586103054e-17 };
public:
	void unvignette(void); //remove lens vignetting
	band(unsigned int);  //constructor
	void undistortion(void); //remove lens distortion
	void denoise(void); //reduce image noise
	void calibrate(void); //calibrate camera signal response
	unsigned int getchannel(void); //get channel of current image
	cv::Mat getbitmap(void); //returns the image
	string getfilename(void); //returns the filename of the image
	void loadBitmap(string,bool); //load the image and metadata and also filename
	cv::Mat band::get_masterblackframe(void);
	bool is_bl(void);
};