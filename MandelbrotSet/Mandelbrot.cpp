#include "Mandelbrot.h"
#include <complex>
namespace alleboudy {
	Mandelbrot::Mandelbrot() {}
	Mandelbrot::~Mandelbrot() {}
	int Mandelbrot::getIterations(double x, double y) {
		std::complex<double> z = 0;
		std::complex<double> c(x, y);

		int iterations = 0;

		while (iterations < Mandelbrot::MAX_ITERATIONS) {
			z = z * z + c;

			if (abs(z) > 2)//get magnitude of complex number
			{
				break;
			}
			iterations++;
		}
		return iterations;
	}
}