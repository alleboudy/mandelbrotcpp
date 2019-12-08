
#include "Main.h"

using namespace alleboudy;
using namespace std;

int main()
{
	int WIDTH = 800, HEIGHT = 600;
	Bitmap bm(WIDTH, HEIGHT);
	double min = 9999999;
	double max = -9999999;

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 });
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{ 0 });//foreach pixel, how many iterations?

	//collecting the histogram of iterations number [each iterations values, how many pixels got it]
	//and saving for each pixel, the number of iterations [each pixel how many iterations it had]
	// will use this in the histogram colouring
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			//bm.setPixel(col, row, 255, 0, 0);
			//std::uint8_t* p = bm.getPixel(col, row);
			double xFractal = (col - WIDTH / 2 - 200) * 2.0 / HEIGHT;
			double yFractal = (row - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			fractal[row * WIDTH + col] = iterations;
			if (iterations != Mandelbrot::MAX_ITERATIONS)
				histogram[iterations]++;


		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}
	//coloring using the histogram
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{

			std::uint8_t red = 0;
			std::uint8_t green = 0;
			std::uint8_t blue = 0;

			int iterations = fractal[row * WIDTH + col];
			//std::uint8_t color = (std::uint8_t) (256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;
				for (int i = 0; i <= iterations; i++) {
					hue += ((double)histogram[i]) / total;
				}
				green = pow(255, hue);

			}
			bm.setPixel(col, row, red, green, blue);


		}
	}


	//checking the values of the histogram
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		cout << histogram[i] << " " << flush;

	}
	cout << endl;


	cout << min << "||" << max << endl;
	bm.write("./tst.bmp");
	cout << "finished" << endl;
	return 0;
}
