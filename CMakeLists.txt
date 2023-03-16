cmake_minimum_required(VERSION 3.0.0)
project(Calculator VERSION 0.1.0)


add_executable(Calculator src/main.cpp src/Application.h src/Application.cpp src/Calculation.h src/Calculation.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
