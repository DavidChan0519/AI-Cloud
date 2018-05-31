cmake_minimum_required(VERSION 2.8.0)
project(human_body_segment)

set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-std=c++11)

set(EXTRA_LIBS ${EXTRA_LIBS} boost_system)
set(EXTRA_LIBS ${EXTRA_LIBS} jsoncpp)
set(EXTRA_LIBS ${EXTRA_LIBS} curl)
set(EXTRA_LIBS ${EXTRA_LIBS} crypto)
set(EXTRA_LIBS ${EXTRA_LIBS} opencv_core)
set(EXTRA_LIBS ${EXTRA_LIBS} opencv_highgui)


include_directories("${PROJECT_SOURCE_DIR}/../common/include/")

aux_source_directory(${PROJECT_SOURCE_DIR}/../common/src  SRC_LISTS)
aux_source_directory(${PROJECT_SOURCE_DIR}/  SRC_LISTS)

add_executable(human_body_segment ${SRC_LISTS})
target_link_libraries(human_body_segment ${EXTRA_LIBS})
install(TARGETS human_body_segment DESTINATION bin)
