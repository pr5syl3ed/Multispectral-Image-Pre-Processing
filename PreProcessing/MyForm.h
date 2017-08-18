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
#include "main.hpp"
#include <msclr/marshal.h>
#include <chrono>
#include <fstream>
#include <iostream>


namespace PreProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private: System::Windows::Forms::Label^  label1;







	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Browse...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &MyForm::folderBrowserDialog1_HelpRequest);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(5, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"1. Browse to your photo folder";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(40, 87);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(5, 110);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(225, 23);
			this->label8->TabIndex = 11;
			this->label8->Text = L"2. Select last Blackframe";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(43, 136);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(79, 24);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Select...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(40, 163);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 13;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(43, 215);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(79, 24);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Start!";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(5, 189);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(225, 23);
			this->label10->TabIndex = 15;
			this->label10->Text = L"3. Press start";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(242, 60);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 16;
			this->textBox1->Text = L"5000";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(242, 136);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 17;
			this->textBox2->Text = L"0.0000000001";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(239, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 23);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Stop align after n iterations";
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(239, 110);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(156, 23);
			this->label12->TabIndex = 20;
			this->label12->Text = L"Stop align after error";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(242, 215);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(104, 17);
			this->checkBox1->TabIndex = 21;
			this->checkBox1->Text = L"Timelapse Mode";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label11->Location = System::Drawing::Point(131, 255);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(225, 23);
			this->label11->TabIndex = 22;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(145, 255);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 23;
			this->button4->Text = L"Help Me!";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(8, 284);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(490, 164);
			this->richTextBox1->TabIndex = 24;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(510, 460);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"PreProcessing";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog test;
		msclr::interop::marshal_context ctx;

		usercom user; //creat usercom object
		if (test.ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->label7->Text = gcnew System::String(test.SelectedPath);
			const char* converted = ctx.marshal_as<const char*>(test.SelectedPath);
			user.setfilepath(converted);

		}

		//		//MessageBox::Show("test");
		//
	}			

	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog ofd;
	msclr::interop::marshal_context ctx;

	//usercom user; //creat usercom object
	if (ofd.ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		this->label9->Text = gcnew System::String(ofd.FileName);
		const char* converted = ctx.marshal_as<const char*>(ofd.FileName);
		}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->label11->Text = "Please Wait!";
	//Sleep(1000);
	std::ofstream ofs("log.txt", std::ofstream::out); ofs << "logging started" << endl;
	DisableProcessWindowsGhosting();
	msclr::interop::marshal_context ctx;
	ofs << "starting initializing" << endl;
	usercom user;
	string filename = ctx.marshal_as<const char*>(this->label7->Text);

	user.setfilepath(filename);
	filename = ctx.marshal_as<const char*>(this->label9->Text);
	//FILE* fp = fopen("log.txt", "w");
	//fprintf(fp, "test1\n");
	//fprintf(fp, "test2\n");
	//fclose(fp);

	user.SetBlackframeID_last_before(
		stoi(filename.substr(filename.length() - 5, 1)) +
		(stoi(filename.substr(filename.length() - 10, 4)) + 1) * 10 +
		(stoi(filename.substr(filename.length() - 16, 3)) + 1) * 100000);
	
	if (checkBox1->Checked == true)
	{
		user.SetTimelapseMode(true);
		ofs << "timelapsemode on" << endl;
	}
	else {
		user.SetTimelapseMode(false);
		ofs << "timelapsemode off" << endl;
	}

	ofs << "User.GetPath = "+user.GetPath() << endl;
	ofs << "User.GetBlatframeID_last_before = " + std::to_string(user.GetBlackframeID_last_before()) << endl;
	//user.interact(); //let user type in his stuff

	// initialize filebrowser
	//filebrowser bildnamen("c:\\Users\\_vm\\Desktop\\000SET", 100245);
	filebrowser bildnamen(user.GetPath(), user.GetBlackframeID_last_before());
	ofs << "browser object" << endl;

	// Initialize 5 bands
	band band1(user.GetBlackframeID_last_before()); //initialize band object for blue channel
	band band2(user.GetBlackframeID_last_before()); //initialize band object for green channel
	band band3(user.GetBlackframeID_last_before()); //initialize band object for red channel
	band band4(user.GetBlackframeID_last_before()); //initialize band object for NearInfrared channel
	band band5(user.GetBlackframeID_last_before()); //initialize band object for RedEdge channel
	
	ofs << "initialized 5 band objects" << endl;
													// Initialize frame consisting of 5 bands
	filename = ctx.marshal_as<const char*>(this->textBox1->Text); //Align iterations

	string filename2 = ctx.marshal_as<const char*>(this->textBox2->Text); //dev stop

	frame bild(
		user.GetTimelapseMode(),
		user.GetAlignment_frameID(),
		MOTION_AFFINE
	);

	ofs << "initialized frame" << endl;

	bild.Set_ter_eps(stoi(filename2));
	bild.Set_ter_iter(stoi(filename));

	//Initialize file handling object, tell where photo folder is located

	//---Start with program-----------------------------------------------------------
	//this->label11->Text = gcnew System::String("Loading Images...");
	//this->progressBar1->Show()
	while (bildnamen.end() != true) { //repeat following steps until all frames are processed
		ofs << "in loop" << endl;
		ofs << bildnamen.is_blackframe() << endl;

		band1.loadBitmap(bildnamen.getfilename(), bildnamen.is_blackframe()); //Load next blue image and tell that this image is not a black frame
		bildnamen.LoadNextImage();
		ofs << bildnamen.is_blackframe() << endl;
		//this->label1->Text = bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 4);


		band2.loadBitmap(bildnamen.getfilename(), bildnamen.is_blackframe()); //Load next blue image and tell that this image is not a black frame
		bildnamen.LoadNextImage();
		ofs << bildnamen.is_blackframe() << endl;
		//this->label1->Text = bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 4);

		band3.loadBitmap(bildnamen.getfilename(), bildnamen.is_blackframe()); //Load next blue image and tell that this image is not a black frame
		bildnamen.LoadNextImage();
		ofs << bildnamen.is_blackframe() << endl;
		//this->label1->Text = bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 4);

		band4.loadBitmap(bildnamen.getfilename(), bildnamen.is_blackframe()); //Load next blue image and tell that this image is not a black frame
		bildnamen.LoadNextImage();
		ofs << bildnamen.is_blackframe() << endl;
		//this->label1->Text = bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 4);
		band5.loadBitmap(bildnamen.getfilename(), bildnamen.is_blackframe()); //Load next blue image and tell that this image is not a black frame
		bildnamen.LoadNextImage();



		if (band1.is_bl() == false && bildnamen.end() != true) {  //is not blackframe

			band1.denoise(); //reduce noise on blue channel Problem fra
			band2.denoise(); //reduce noise on green channel
			band3.denoise(); //reduce noise on red channel
			band4.denoise(); //reduce noise on red channel
			band5.denoise(); //reduce noise on RedEdge channel
							 //this->label1->Text = bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 3);
							 ////Do Lens unvignetting
			band1.unvignette();
			band2.unvignette();
			band3.unvignette();
			band4.unvignette();
			band5.unvignette();
			ofs << "unvignetting " + bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 3) << endl;
			//////Do lens undistortion
			band1.undistortion();
			band2.undistortion();
			band3.undistortion();
			band4.undistortion();
			band5.undistortion();
			ofs << "undistorting " + bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 3) << endl;;
			////Load 5 images (5bands) to a frame
			bild.loadbands(
				band1.getbitmap(), //blue channel
				band2.getbitmap(), //green channel
				band3.getbitmap(), //red channel
				band4.getbitmap(), //NearInfrared channel
				band5.getbitmap(), //RedEdge channel
				user.GetTimelapseMode(), //Give file name from one image to method to ensure right output frame number xxxx
				band1.getfilename(),
				band1.is_bl()
			);

			////Run Band alignment algorithm for one frame
			//this->label11->Text = gcnew System::String("Aligning...");
			bild.align();
			ofs << "aligning     " + bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 3) << endl;
			////Run black border removal for every band within frame
			bild.crop();
			ofs << "cropping     " + bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 3) << endl;
			////Save frame as multi-page tif file with 5 bands
			bild.stack();
			ofs << "stacking    " + bildnamen.getfilename().substr(bildnamen.getfilename().length() - 19, bildnamen.getfilename().length() - 3) << endl;
		}

	}
	ofs << "Completed";
	this->label11->Text = "Completed";
	MessageBox::Show("Alignment Completed!");
	ofs.close();

}
private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("photo folder ex. c:\\0001SET\nblackframe before alignment frame ex. c:\\0001SET\\000\\IMG_0040_5.tif\nInreasing the number of iterations gives better alignment results but takes longer\nDecreasing alignment error threshold gives better results but takes longer\nProcess may take a long time, when finisehd a window pops up.");
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};

}
