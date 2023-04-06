set(TARGET target_name)
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${source_dir}/*.cpp")

if(WIN32)
add_executable(${PROJECT_NAME} WIN32 ${source_files})
endif()
if(LINUX)
add_executable(${PROJECT_NAME} ${source_files})
endif()


target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})