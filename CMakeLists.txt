cmake_minimum_required(VERSION 3.10.0)
project(softRaster VERSION 0.1.0 LANGUAGES C CXX)

set(CXX_STANDARD_REQUIRED true)
set(CXX_STANDARD 20)

set(TARGET_NAME ${PROJECT_NAME})

add_subdirectory(vendor)
add_subdirectory(source)

