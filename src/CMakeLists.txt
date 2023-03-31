set(TARGET target_name)
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${source_dir}/*.cpp")
add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})