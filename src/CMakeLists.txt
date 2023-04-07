cmake_minimum_required(VERSION 3.6)
project(Calculator_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../inc)
set(wxWidgets_USE_STATIC 1)
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})


file(GLOB SOURCE_FILES "*.cpp")
message("sources: ${SOURCE_FILES}")
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})