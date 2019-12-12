# CMakeList.txt : CMake project for MandelbrotSet, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
# Add source to this project's executable.
add_executable (MandelbrotSet "RGB.cpp" "RGB.h" "FractalCreator.h" "FractalCreator.cpp" "ZoomList.cpp" "ZoomList.h" "Zoom.h" "Main.cpp" "Main.h" "BitmapFileHeader.h" "BitmapInfoHeader.h" "Bitmap.h" "Bitmap.cpp" "Mandelbrot.cpp" "Mandelbrot.h")
target_link_libraries(MandelbrotSet ${OpenCV_LIBS}) 
