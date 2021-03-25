cmake_minimum_required(VERSION 3.17)
project(analysis_snp)

set(CMAKE_CXX_STANDARD 17)

#add_executable(analysis_snp
#        src/main.cpp
#        src/sequence_processing.cpp
#        src/energy.cpp
#        src/plot.cpp
#        src/check_input.cpp
#        inc/check_input.h
#        inc/energy.h
#        inc/plot.h
#        inc/sequence_processing.h)

add_executable(analysis_snp
        src/example.cpp)