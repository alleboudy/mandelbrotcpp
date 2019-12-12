
#include <iostream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>//to write a binary file of our bitmap

namespace alleboudy {

	ImageHandler::ImageHandler(int width, int height) :m_width(width), m_height(height), m_pPixels(cv::Size(width, height), CV_8UC4) {

	}

	bool ImageHandler::write(std::string fname) {


		std::vector<int> compression_params;
		compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(0);
		cv::imwrite(fname, m_pPixels, compression_params);
		std::cout << "wrote" << std::endl;


		return true;
	}
	void ImageHandler::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
		m_pPixels.at<cv::Vec4b>(y, x) = cv::Vec4b(blue, green, red, 255);
	}
	std::uint8_t* ImageHandler::getPixel(int x, int y) {
		return nullptr;
	}
	ImageHandler::~ImageHandler() {

	}
}