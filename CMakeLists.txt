cmake_minimum_required(VERSION 3.10)
project(Stack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StackApp
    src/main.cpp
    src/Stack.cpp
    include/Stack.h
)

target_include_directories(StackApp PRIVATE include)