#pragma once

#include <memory>
#include <string>
#include <math.h>
#include "zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "Zoom.h"
#include "Mandelbrot.h"


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



	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		void calculateIteration();
		void drawFractal();
		void calculateTotalIterations();
		void writeBitmap(std::string fname);
		void addZoom(const Zoom& zoom);
	};
}