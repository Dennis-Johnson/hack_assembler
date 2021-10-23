cmake_minimum_required(VERSION 3.10)

# Project name
project(hack-assembler)

# creates the variable EXEC and sets it to assembler
set(EXEC assembler)

# set the C++20 standard
set(CMAKE_CXX_STANDARD 20)

# I../includes
include_directories(includes)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp)

# compiles the files defined by SOURCES to generate the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})
