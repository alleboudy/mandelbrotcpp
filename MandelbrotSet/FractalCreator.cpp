#include "FractalCreator.h"


namespace alleboudy {
	void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
	{
		m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
		m_colors.push_back(rgb);
		if (m_bGotFirstRange)
		{
			m_rangeTotals.push_back(0);
		}
		m_bGotFirstRange = true;
	}
	FractalCreator::FractalCreator(int width, int height) :m_width(width), m_height(height),
		m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 }),
		m_fractal(new int[m_width * m_height]{ 0 }),
		m_bitmap(width, height),
		m_zoomList(width, height)

	{
		m_zoomList.add(Zoom(m_width / 2, m_height / 2, 3. / m_width));
	}

	FractalCreator::~FractalCreator()
	{
	}

	void FractalCreator::calculateIteration()
	{

		//collecting the histogram of iterations number [each iterations values, how many pixels got it]
		//and saving for each pixel, the number of iterations [each pixel how many iterations it had]
		// will use this in the histogram colouring
		for (int row = 0; row < m_height; row++)
		{
			for (int col = 0; col < m_width; col++)
			{

				std::pair<double, double> coords = m_zoomList.doZoom(col, row);
				int iterations = Mandelbrot::getIterations(coords.first, coords.second);
				m_fractal[row * m_width + col] = iterations;
				if (iterations != Mandelbrot::MAX_ITERATIONS)
					m_histogram[iterations]++;
			}
		}

	}
	void FractalCreator::drawFractal()
	{
		RGB startColor(0, 0, 0);
		RGB endColor(255, 0, 0);
		RGB colorDiff = endColor - startColor;
		//coloring using the histogram
		for (int row = 0; row < m_height; row++)
		{
			for (int col = 0; col < m_width; col++)
			{

				std::uint8_t red = 0;
				std::uint8_t green = 0;
				std::uint8_t blue = 0;

				int iterations = m_fractal[row * m_width + col];
				//std::uint8_t color = (std::uint8_t) (256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
				if (iterations != Mandelbrot::MAX_ITERATIONS)
				{
					double hue = 0.0;
					for (int i = 0; i <= iterations; i++) {
						hue += ((double)m_histogram[i]) / m_total;
					}
					//red = pow(255, hue);
					red = startColor.r + colorDiff.r * hue;
					green = startColor.g + colorDiff.g * hue;
					blue = startColor.b + colorDiff.b * hue;


				}
				m_bitmap.setPixel(col, row, red, green, blue);


			}
		}
	}
	void FractalCreator::calculateTotalIterations()
	{
		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
			m_total += m_histogram[i];
		}
	}
	void FractalCreator::writeBitmap(std::string fname)
	{
		m_bitmap.write(fname);
	}
	void FractalCreator::addZoom(const Zoom& zoom)
	{
		m_zoomList.add(zoom);
	}
	void FractalCreator::run(std::string fname)
	{

		calculateIteration();
		calculateTotalIterations();
		drawFractal();
		writeBitmap(fname);
	}
	;

}