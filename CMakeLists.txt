cmake_minimum_required(VERSION 3.17)
project(Project1Phase1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1Phase1 main.cpp Tokenizer.cpp Tokenizer.hpp Token.cpp Token.hpp Stack.cpp Stack.hpp)