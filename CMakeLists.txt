cmake_minimum_required(VERSION 3.27)
project(AiZO_projekt1)

set(CMAKE_CXX_STANDARD 23)

add_executable(AiZO_projekt1 sources/main/main.cpp
        headers/data/numberGenerator.h
        headers/sort_algorithms/insertionSort.h
        headers/sort_algorithms/quickSort.h
        headers/data/txtToArray.h
        headers/sort_algorithms/heapSort.h
        headers/sort_algorithms/ShellSort.h
        headers/data/presort.h)

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
