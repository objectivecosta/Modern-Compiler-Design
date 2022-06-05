cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_GENERATOR "Ninja")
message("Generator is set to ${CMAKE_GENERATOR}")

# set the project name
project(Cap1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable

add_subdirectory(./src)
# add_executable(Compiler ${compiler_src})