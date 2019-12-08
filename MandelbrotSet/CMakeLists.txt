# CMakeList.txt : CMake project for MandelbrotSet, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (MandelbrotSet "FractalCreator.h" "FractalCreator.cpp" "ZoomList.cpp" "ZoomList.h" "Zoom.h" "Main.cpp" "Main.h" "BitmapFileHeader.h" "BitmapInfoHeader.h" "Bitmap.h" "Bitmap.cpp" "Mandelbrot.cpp" "Mandelbrot.h")
 
# TODO: Add tests and install targets if needed.
