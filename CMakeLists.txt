# CMakeList.txt : CMake project for HelloBenchmark, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("HelloBenchmark")

find_package(benchmark REQUIRED)

# Add source to this project's executable.
add_executable (HelloBenchmark "HelloBenchmark.cpp" "HelloBenchmark.h")

# Set both releae and debug builds to use the release build benchmark dll:
# We should not need to debug into google benchmark and other libraries:
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")

# link to the installed google benchmark library: 
target_link_libraries(HelloBenchmark benchmark::benchmark)