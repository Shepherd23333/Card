cmake_minimum_required(VERSION 3.15.0)
project(Card VERSION 0.1.0)

include_directories(include)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_subdirectory(src)
aux_source_directory(. DIR_SRCS)
add_executable(Card ${DIR_SRCS})
target_link_libraries(Card srcs)