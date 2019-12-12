
#include <iostream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>//to write a binary file of our bitmap

namespace alleboudy {

	Bitmap::Bitmap(int width, int height) :m_width(width), m_height(height), m_pPixels(cv::Size(width, height), CV_8UC4){

	}

	bool Bitmap::write(std::string fname) {
		
		/*BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file;

		file.open(fname.c_str(), std::ios::binary);
		if (!file) {
			std::cout << "didn't open!" << std::endl;
			return false;
		}
		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));*/
		//file.write((char*)m_pPixels.get(), m_width * m_height * 3);
		std::vector<int> compression_params;
		compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(0);
		cv::imwrite(fname, m_pPixels, compression_params);
		/*cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
		cv::imshow("image", m_pPixels);
		cv::waitKey(30);*/
		/*file.flush();
		file.close();*/
		std::cout << "wrote" << std::endl;
		//if (!file)return false;

		return true;
	}
	void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
		//std::uint8_t* pPixel = m_pPixels.get();//get a pointer to the particular pixel (x,y)
		m_pPixels.at<cv::Vec4b>(y, x) = cv::Vec4b(blue, green, red, 255);
		//pPixel += 3 * y * m_width + 3 * x;//moving to the correct pixel

		//brg, because bitmap uses littleendian
		/*pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;*/
	}
	std::uint8_t* Bitmap::getPixel(int x, int y) {
		//std::uint8_t* pPixel = m_pPixels.get();//get a pointer to the particular pixel (x,y)

		//pPixel += 3 * y * m_width + 3 * x;//moving to the correct pixel
		return nullptr;
//		return pPixel;
	}
	Bitmap::~Bitmap() {

	}
}