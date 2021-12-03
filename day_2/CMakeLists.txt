cmake_minimum_required(VERSION 3.0)

project(aoc_2021 C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Wpedantic -lgsl -lcblas")

#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")
#set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native")

#find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(SRC src/main.cpp)
#set(INC src/problem.h)

add_executable(main ${SRC} ${INC})
#target_link_libraries(main Eigen3::Eigen)
#target_include_directories(main PUBLIC ${metapopulation_SOURCE_DIR}/vendor/eigen)
