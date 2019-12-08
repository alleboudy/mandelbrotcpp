#pragma once

#include <string>
namespace alleboudy {
	class FractalCreator {
	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		void calculateIteration();
		void drawFractal();
		void writeBitmap(std::string fname);
		void addZoom(const Zoom& zoom);
	};
}