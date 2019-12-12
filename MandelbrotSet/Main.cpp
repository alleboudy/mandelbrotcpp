
#include "Main.h"
#include <iostream>
#include "Zoom.h"
using namespace alleboudy;
using namespace std;

int main()
{
	RGB rgb1(4, 5, 6);
	RGB rgb2(1, 2, 3);
	RGB rgb3 = rgb1 - rgb2;
	cout << rgb3.r << rgb3.g << rgb3.b << endl;

	FractalCreator  fractalCreator(1800, 1024);

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(255, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	//fractalCreator.addZoom(Zoom(1024, 1024, 0.9));
	//fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("./tst22.png");
	cout << "finished" << endl;
	return 0;
}
