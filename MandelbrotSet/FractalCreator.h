#pragma once

#include <memory>
#include <string>
#include <math.h>
#include <vector>
#include "Bitmap.h"
#include "ZoomList.h"
#include "Zoom.h"
#include "Mandelbrot.h"
#include "RGB.h"

namespace alleboudy {
	class FractalCreator {
	private:
		int m_width;
		int m_height;
		int m_total{ 0 };

		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;//foreach pixel, how many iterations?
		Bitmap m_bitmap;
		ZoomList m_zoomList;

		std::vector<int> m_ranges;
		std::vector<RGB> m_colors;
		std::vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

		void calculateIteration();
		void drawFractal();
		void calculateTotalIterations();
		void writeBitmap(std::string fname);

	public:
		void addRange(double rangeEnd, const RGB& rgb);
		FractalCreator(int width, int height);
		void addZoom(const Zoom& zoom);
		virtual ~FractalCreator();
		void run(std::string fname);
	};
}