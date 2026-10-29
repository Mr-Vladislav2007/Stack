cmake_minimum_required(VERSION 3.10)
project(Stack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB stack ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(StackApp ${stack})

target_include_directories(StackApp PRIVATE include)