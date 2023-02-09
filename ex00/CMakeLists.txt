cmake_minimum_required(VERSION 3.23)
project(ex00)
project(ex00_lib)

add_compile_options(-gdwarf-4 -Wall -Wextra -Werror)
set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 src/CharHandler.cpp  src/CharHandler.h  src/InputEvaluator.cpp  src/InputEvaluator.h  src/main.cpp
        src/NumberHandler.cpp src/NumberHandler.h  src/ScalarConversion.cpp  src/ScalarConversion.h)
add_library(ex00_lib src/CharHandler.cpp  src/CharHandler.h  src/InputEvaluator.cpp  src/InputEvaluator.h
        src/NumberHandler.cpp src/NumberHandler.h  src/ScalarConversion.cpp  src/ScalarConversion.h)

add_subdirectory(test)