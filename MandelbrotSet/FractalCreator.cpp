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
		/*RGB startColor(0, 0, 0);
		RGB endColor(255, 0, 0);
		RGB colorDiff = endColor - startColor;*/
		//for the coloring we would need to use a different set of colors for each range, I would
		//coloring using the histogram
		for (int row = 0; row < m_height; row++)
		{
			for (int col = 0; col < m_width; col++)
			{
				int iterations = m_fractal[row * m_width + col];
				int range = getRange(iterations);
				int rangeTotal = m_rangeTotals[range];
				int rangeStart = m_ranges[range];
				RGB& startColor = m_colors[range];
				RGB& clrEnd = m_colors[range + 1];
				RGB colorDiff = clrEnd - startColor;

				std::uint8_t red = 0;
				std::uint8_t green = 0;
				std::uint8_t blue = 0;

				//std::uint8_t color = (std::uint8_t) (256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
				if (iterations != Mandelbrot::MAX_ITERATIONS)
				{
					float currentTotalPixels = 0.0f;
					for (int i = rangeStart; i <= iterations; i++) {
						currentTotalPixels += m_histogram[i];
					}
					/*blue = pow(188, hue);
					green = pow(140, hue);
					red = pow(91, hue);*/
					red = startColor.r + colorDiff.r * currentTotalPixels / rangeTotal;
					green = startColor.g + colorDiff.g * currentTotalPixels / rangeTotal;
					blue = startColor.b + colorDiff.b * currentTotalPixels / rangeTotal;


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

		std::cout << "Overall total: " << m_total << std::endl;
	}
	void FractalCreator::writeBitmap(std::string fname)
	{
		m_bitmap.write(fname);
	}
	int FractalCreator::getRange(int iteration) const
	{
		int range = 0;

		for (int i = 1; i < m_ranges.size(); i++) {

			range = i;

			if (m_ranges[i] > iteration) {
				break;
			}

		}

		range--;

		assert(range > -1);
		assert(range < m_ranges.size());

		return range;
	}
	void FractalCreator::addZoom(const Zoom& zoom)
	{
		m_zoomList.add(zoom);
	}
	void FractalCreator::calculateRangeTotals() {
		int rangeIdx = 0;
		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
			int pixels = m_histogram[i];
			if (i >= m_ranges[rangeIdx + 1]) {
				rangeIdx++;
			}
			m_rangeTotals[rangeIdx] += pixels;
		}
		int overallTotal = 0;
		for (int val : m_rangeTotals)
		{
			std::cout << val << std::endl;
			overallTotal += val;
		}
		std::cout << "Checked overall total: " << overallTotal << std::endl;
	}
	void FractalCreator::run(std::string fname)
	{

		calculateIteration();
		calculateTotalIterations();

		calculateRangeTotals();

		drawFractal();
		writeBitmap(fname);
	}
	;

}