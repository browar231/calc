cmake_minimum_required(VERSION 3.0.0)
project(Calculator VERSION 0.1.0)


find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

include_directories(inc)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
