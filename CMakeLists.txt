cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME analysis_snp)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/sequence_processing.cpp
        src/energy.cpp
        src/check_input.cpp
        src/reading_conf.cpp
        inc/check_input.h
        inc/energy.h
        inc/reading_conf.h
        inc/all_amino_acids.h
        inc/sequence_processing.h)
