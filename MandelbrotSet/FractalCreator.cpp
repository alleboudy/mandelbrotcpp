#include "FractalCreator.h"
#include "Zoom.h"

namespace alleboudy {
	class FractalCreator {
	public:
		FractalCreator() {}
		FractalCreator::FractalCreator(int width, int height)
		{
		}
		virtual ~FractalCreator() {}
		void FractalCreator::calculateIteration()
		{
		}
		void FractalCreator::drawFractal()
		{
		}
		void FractalCreator::writeBitmap(std::string fname)
		{
		}
		void FractalCreator::addZoom(const Zoom& zoom)
		{
		}
		;

	};
}