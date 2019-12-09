#pragma once

namespace alleboudy {
	struct RGB {

		double r;
		double g;
		double b;

		RGB(double r, double g, double b);
	};
	RGB operator-(const RGB& firtst, const RGB& second);
}