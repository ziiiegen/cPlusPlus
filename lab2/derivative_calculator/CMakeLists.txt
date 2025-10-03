cmake_minimum_required(VERSION 3.10)
project(DerivativeCalculator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем поддиректории
add_subdirectory(src)
add_subdirectory(tests)
