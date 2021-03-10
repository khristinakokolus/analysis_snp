cmake_minimum_required(VERSION 3.17)
project(analysis_snp)

set(CMAKE_CXX_STANDARD 17)

add_executable(analysis_snp src/main.cpp src/sequence_processing.cpp)