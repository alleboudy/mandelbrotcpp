
#include "Main.h"

using namespace alleboudy;
using namespace std;

int main()
{
	int WIDTH = 800, HEIGHT = 600;
	Bitmap bm(WIDTH, HEIGHT);
	double min = 9999999;
	double max = -9999999;


	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			//bm.setPixel(col, row, 255, 0, 0);
			//std::uint8_t* p = bm.getPixel(col, row);
			double xFractal = (col - WIDTH / 2-200) * 2.0 / HEIGHT;
			double yFractal = (row - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			std::uint8_t color = (std::uint8_t) (256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			color = color * color * color;

			bm.setPixel(col, row, 0, color, 0);
			if (color < min) min = color;
			if (color > max) max = color;

		}
	}


	cout << min << "||" << max << endl;
	bm.write("./tst.bmp");
	cout << "finished" << endl;
	return 0;
}
