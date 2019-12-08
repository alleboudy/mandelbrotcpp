#pragma once

namespace alleboudy {

	class Mandelbrot {
	public:
		static const int MAX_ITERATIONS = 10;
	public:
		Mandelbrot();
		virtual ~Mandelbrot();

		static int getIterations(double x, double y);

	};
}