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
#include <cstdio>
#include <bitset>
#include <windows.h>
//#include <gdiplus.h>
#include <stdarg.h>
#include "frame.hpp"
#include <fileapi.h>

using namespace cv;
using namespace std;
using namespace Magick;
//using namespace Gdiplus;

void frame::write(void) { //method for debugging which writes images on harddrive
	cv::imwrite("c:\\images\\test1.tif", band1);
	cv::imwrite("c:\\images\\test2.tif", band2);
	cv::imwrite("c:\\images\\test3.tif", band3);
	cv::imwrite("c:\\images\\test4.tif", band4);
	cv::imwrite("c:\\images\\test5.tif", band5);
}

void frame::ftran1(void) {
	cv::TermCriteria criteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, number_of_iterations, termination_eps); //termination criteria
	findTransformECC(band5_gr, band1_gr, warp_matrix, warp_mode, criteria); //termination criteria);
}

void frame::ftran2(void) {
	cv::TermCriteria criteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, number_of_iterations, termination_eps); //termination criteria
	findTransformECC(band5_gr, band2_gr, warp_matrix1, warp_mode, criteria); //termination criteria);
}

void frame::ftran3(void) {
	cv::TermCriteria criteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, number_of_iterations, termination_eps); //termination criteria
	findTransformECC(band5_gr, band3_gr, warp_matrix2, warp_mode, criteria); //termination criteria);
}

void frame::ftran4(void) {
	cv::TermCriteria criteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, number_of_iterations, termination_eps); //termination criteria
	findTransformECC(band5_gr, band4_gr, warp_matrix3, warp_mode, criteria); //termination criteria);
}


void frame::align(void) {
	/*

	In the following code are 2 variables which have an influence on the resulting images.
	One is called iterations and the other correlation. The variable iterations default value is  5000.
	Higher values mean longer computation time and better results.
	The correlation variable’s default values is 1e-10. Lower values mean longer computation time and better results.
	You can choose between transformation modes:
	Translation (x and y shift)
	Eucleidean  (x and y shift and rotation)
	affine (x and y shift and rotation and shear and scale) is recommended

	Homography (x and y shift and rotation and shear and scale and more….)
	*/
	if(!is_blackframe){
		//imwrite("c:\\Users\\\\Desktop\\a.tif", band1);
		//imwrite("c:\\Users\\\\Desktop\\b.tif", band2);
		//imwrite("c:\\Users\\\\Desktop\\c.tif", band3);
		//imwrite("c:\\Users\\Desktop\\d.tif", band4);
		//imwrite("c:\\Users\\Desktop\\e.tif", band5);
	//convert datatype short to 32bit float

	band1.convertTo(band1_gr, CV_32FC1, 1.0 / 65535.0); //the last argument is the scaling factor
	band2.convertTo(band2_gr, CV_32FC1, 1.0 / 65535.0);
	band3.convertTo(band3_gr, CV_32FC1, 1.0 / 65535.0);
	band4.convertTo(band4_gr, CV_32FC1, 1.0 / 65535.0);
	band5.convertTo(band5_gr, CV_32FC1, 1.0 / 65535.0);


	// Run the ECC algorithm. find same image features in both images
	// The results are stored in warp_matrix.
	//cout << timelapse << " timelapse" << endl;
	//cout << last_bl << " last_was_blackframe" << endl;
	if (timelapse == false || (timelapse == true && last_bl == true)) { //analyze only first frame when timelapse mode is enabled
		//cout << "finding transform" << endl;
		cv::TermCriteria criteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, number_of_iterations, termination_eps); //termination criteria
		//band2_gr.convertTo(band2_gr, CV_16U, 65535.0 / 1.0);
		//imwrite("c:\\Users\\\\Desktop\\a.tif", band2_gr);
		findTransformECC(band5_gr, band1_gr, warp_matrix, warp_mode, criteria);
		//cout << "a";
		findTransformECC(band5_gr, band2_gr, warp_matrix1, warp_mode, criteria); //find same features in green and RedEdge channel
		//cout << "b";
		findTransformECC(band5_gr, band3_gr, warp_matrix2, warp_mode, criteria); //find same features in red and RedEdge channel
		//cout << "c";
		findTransformECC(band5_gr, band4_gr, warp_matrix3, warp_mode, criteria); //find same features in NearInfrared and RedEdge channel
		//cout << "d";
		last_bl = false;
		//imwrite("c:\\Users\\\\Desktop\\test1.tif", band5_gr);
	}



	// start image alignment to RedEdge channel depending on warp mode "affine" or "homography"
	if (warp_mode != cv::MOTION_HOMOGRAPHY) {
		// Use warpAffine for Translation, Euclidean and Affine
		warpAffine(band1_gr, band1_al, warp_matrix, band1.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
		warpAffine(band2_gr, band2_al, warp_matrix1, band2.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
		warpAffine(band3_gr, band3_al, warp_matrix2, band3.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
		warpAffine(band4_gr, band4_al, warp_matrix3, band4.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
	}
	else {
		// Use warpPerspective for Homography
		warpPerspective(band1_gr, band1_al, warp_matrix, band1.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
		warpPerspective(band2_gr, band2_al, warp_matrix1, band2.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
		warpPerspective(band3_gr, band3_al, warp_matrix2, band3.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
		warpPerspective(band4_gr, band4_al, warp_matrix3, band4.size(), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP);
	}

	//convert 32 bit float back to short
	band1_al.convertTo(band1, CV_16U, 65535.0 / 1.0);
	band2_al.convertTo(band2, CV_16U, 65535.0 / 1.0);
	band3_al.convertTo(band3, CV_16U, 65535.0 / 1.0);
	band4_al.convertTo(band4, CV_16U, 65535.0 / 1.0);
	band5_gr.convertTo(band5, CV_16U, 65535.0 / 1.0);
	}
}

frame::frame(bool x, unsigned int y, unsigned int z) {
	timelapse = x;
	alignment_frameID = y;
	warp_mode = z;

	// Initialize the matrix to identity
	if (warp_mode == cv::MOTION_HOMOGRAPHY) { //when complexer model "homography" chosen
		warp_matrix = cv::Mat::eye(3, 3, CV_32F);
		warp_matrix1 = cv::Mat::eye(3, 3, CV_32F);
		warp_matrix2 = cv::Mat::eye(3, 3, CV_32F);
		warp_matrix3 = cv::Mat::eye(3, 3, CV_32F);
		warp_matrix4 = cv::Mat::eye(3, 3, CV_32F);
	}
	else if (warp_mode == cv::MOTION_AFFINE) { //when simpler model "affine" chosen
		warp_matrix = cv::Mat::eye(2, 3, CV_32F);
		warp_matrix1 = cv::Mat::eye(2, 3, CV_32F);
		warp_matrix2 = cv::Mat::eye(2, 3, CV_32F);
		warp_matrix3 = cv::Mat::eye(2, 3, CV_32F);
		warp_matrix4 = cv::Mat::eye(2, 3, CV_32F);
	}
}




void frame::loadbands(cv::Mat img1,cv::Mat img2, cv::Mat img3, cv::Mat img4, cv::Mat img5, bool tl, string filename, bool bl) {
	band1 = img1;
	band2 = img2;
	band3 = img3;
	band4 = img4;
	band5 = img5;
	timelapse = tl; //save desired timelapse mode
	is_blackframe = bl;
	//parse frame number from filename
	framenumber = (stoi(filename.substr(filename.length() - 10, 4)) + 1) * 10 + //_xxxx_
		stoi(filename.substr(filename.length() - 5, 1)) + // _x.
		(stoi(filename.substr(filename.length() - 16, 3)) + 1) * 100000; //folder
	
	filepath = filename; //save for later
}


//image conversion for transport from one object in another one
Magick::Image Mat2Magick(Mat& src) 
{
	Magick::Image mgk(src.cols, src.rows, "BGR", ShortPixel, (short *)src.data);
	return mgk;
}


void frame::stack(void) {
	temp_str = filepath.substr(0, filepath.length() - 19) +"\\"+ "tmp"; //reconstruct new folderpath using the filename

	//cout << "\n " + temp_str + " " << endl;
	mkdir(temp_str.c_str());  //create new folder
	//cout << temp_str << endl;
	//temporary write images to tmp folder
	cv::imwrite(filepath.substr(0, filepath.length() - 19) + "\\tmp\\band1.tif" , band1); //frame number IMG_XXXX, band1);
	
	cv::imwrite(filepath.substr(0, filepath.length() - 19) + "\\tmp\\band2.tif" , band2); //frame number IMG_XXXX, band1);
		
	cv::imwrite(filepath.substr(0, filepath.length() - 19) + "\\tmp\\band3.tif" , band3); //frame number IMG_XXXX, band1);
	
	cv::imwrite(filepath.substr(0, filepath.length() - 19) + "\\tmp\\band4.tif" , band4); //frame number IMG_XXXX, band1);
	
	cv::imwrite(filepath.substr(0, filepath.length() - 19) + "\\tmp\\band5.tif" , band5); //frame number IMG_XXXX, band1);


	imageList.clear(); //delete imageListe before loading new images in it

	//read images in different object type
	Magick::readImages(&imageList, filepath.substr(0, filepath.length() - 19) + "\\tmp\\band1.tif");
	Magick::readImages(&imageList, filepath.substr(0, filepath.length() - 19) + "\\tmp\\band2.tif");
	Magick::readImages(&imageList, filepath.substr(0, filepath.length() - 19) + "\\tmp\\band3.tif");
	Magick::readImages(&imageList, filepath.substr(0, filepath.length() - 19) + "\\tmp\\band4.tif");
	Magick::readImages(&imageList, filepath.substr(0, filepath.length() - 19) + "\\tmp\\band5.tif");



	////tmp file removal
	remove((filepath.substr(0, filepath.length() - 19) + "\\tmp\\" + "band1.tif").c_str());
	remove((filepath.substr(0, filepath.length() - 19) + "\\tmp\\" + "band2.tif").c_str());
	remove((filepath.substr(0, filepath.length() - 19) + "\\tmp\\" + "band3.tif").c_str());
	remove((filepath.substr(0, filepath.length() - 19) + "\\tmp\\" + "band4.tif").c_str());
	remove((filepath.substr(0, filepath.length() - 19) + "\\tmp\\" + "band5.tif").c_str());

	temp_str = filepath.substr(0, filepath.length() - 19) +"\\"+ "output"; //create output folder reconstructing path from filename
	mkdir(temp_str.c_str());  //create new folder


	//write stacked multi-page tif
	Magick::writeImages(
		imageList.begin(), 
		imageList.end(), 
		filepath.substr(0, filepath.length() - 19) + //folderpath
		"\\output\\" + //adtional folder 
	 to_string(framenumber) + ".tif"); //frame number IMG_XXXX keeps the right frame number
	

}

void frame::crop(void) {


	while (counter <= 3) {

		//process one band after another
		if (counter == 0) { temp2 = band1; } //load current band to buffer temp2
		else if (counter == 1) { temp2 = band2; }
		else if (counter == 2) { temp2 = band3; }
		else if (counter == 3) { temp2 = band4; }

		//set to start position down left corner
		y = y_res; 
		x = 0;
		border_flag = false;

		//start finding first non-dark pixel from bottom
		while (y >= 0 && border_flag == false) {
			x = 0;
			while (x <= x_res && border_flag == false) {
				Vec3s intensity = temp2.at<ushort>(y, x);
				float blue = intensity.val[0];
				if (blue > 0) {
					border_flag = true;
				}
				else
				{
					x++;
				}
			}
			if (y > 0) {
				y--;
			}
		}
		if (border_flag == true) {
			bd[counter] = y_res - (y + 1);
		}

		//start from the top left corner
		border_flag = false;
		x = 0;
		y = 0;

		//start finding first non-dark pixel on left border
		while (x <= x_res && border_flag == false) {
			y = 0;
			while (y <= y_res && border_flag == false) {
				Vec3s intensity = temp2.at<ushort>(y, x);
				float blue = intensity.val[0];
				if (blue > 0) {
					border_flag = true;
				}
				else
				{
					y++;
				}
			}
			x++;
		}
		if (border_flag == true) {
			bl[counter] = x;

		}

		//start from top right corner
		border_flag = false;
		x = x_res;
		y = 0;

		//start finding first non-dark pixel on right border
		while (x >= 0 && border_flag == false) {
			y = 0;
			while (y <= y_res && border_flag == false) {
				Vec3s intensity = temp2.at<ushort>(y, x);
				float blue = intensity.val[0];
				if (blue > 0) {
					border_flag = true;
				}
				else
				{
					y++;
				}
			}
			if (x > 0) {
				x--;
			}
		}
		if (border_flag == true) {
			br[counter] = x_res - (x + 1);
		}

		//start from top left corner
		border_flag = false;
		y = 0;
		x = 0;
		
		//start finding first non-dark pixel from top
		while (y <= y_res && border_flag == false) {
			x = 0;
			while (x <= x_res && border_flag == false) {
				Vec3s intensity = temp2.at<ushort>(y, x);
				float blue = intensity.val[0];
				if (blue > 0) {
					border_flag = true;
				}
				else
				{
					x++;
				}
			}
			y++;
		}
		if (border_flag == true) {
			bt[counter] = y;
		}
		counter++;

	}


	x = 0;//reset
	tmp = 0;//reset

	//find biggest right border (bubble sort array)
	while (sorting == true) {
		if (br[x] >= br[x + 1]) {
			if (x < 2) {
				x++;
			}
			else
			{
				sorting = false; //finished
				x = 0;
			}
		}
		else //swap to elements
		{
			tmp = br[x];
			br[x] = br[x + 1];
			br[x + 1] = tmp;
			x = 0;
		}
	}

	sorting = true;

	//find biggest left border (bubble sort array)
	while (sorting == true) {
		if (bl[x] >= bl[x + 1]) {
			if (x < 2) {
				x++;
			}
			else
			{
				sorting = false; //finished
				x = 0;
			}
		}
		else //swap to elements
		{
			tmp = bl[x];
			bl[x] = bl[x + 1];
			bl[x + 1] = tmp;
			x = 0;
		}
	}
	sorting = true;

	//find biggest top border (bubble sort array)
	while (sorting == true) {
		if (bt[x] >= bt[x + 1]) {
			if (x < 2) {
				x++;
			}
			else
			{
				sorting = false; //finished
				x = 0;
			}
		}
		else //swap to elements
		{
			tmp = bt[x];
			bt[x] = bt[x + 1];
			bt[x + 1] = tmp;
			x = 0;
		}
	}
	sorting = true;

	//find biggest bottom border  (bubble sort array)
	while (sorting == true) {
		if (bd[x] >= bd[x + 1]) {
			if (x < 2) {
				x++;
			}
			else
			{
				sorting = false; //finished
				x = 0;
			}
		}
		else //swap to elements
		{
			tmp = bd[x];
			bd[x] = bd[x + 1];
			bd[x + 1] = tmp;
			x = 0;
		}
	}

	// Setup a rectangle to define your region of interest
	cv::Rect myROI(bl[0], bt[0], 1279 - bl[0] - br[0], 959 - bt[0] - bd[0]); //myROI(x, y,width, height)

	// crop all bands to overlapping area
	band1 = band1(myROI);
	band2 = band2(myROI);
	band3 = band3(myROI);
	band4 = band4(myROI);
	band5 = band5(myROI);

}

void frame::Set_ter_eps(double x) {
	termination_eps = x;
}

void frame::Set_ter_iter(int x) {
	number_of_iterations = x;
}