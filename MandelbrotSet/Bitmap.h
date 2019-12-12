#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include<opencv2/opencv.hpp>

namespace alleboudy {

	class ImageHandler {
	private:
		int m_width{ 0 };
		int m_height{ 0 };
		//std::unique_ptr<std::uint8_t[]> m_pPixels{ nullptr };
		cv::Mat m_pPixels;
		

	public:
		ImageHandler(int width, int height);
		bool write(std::string fname);
		void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
		std::uint8_t* getPixel(int x, int y);
		virtual ~ImageHandler();
	};
}