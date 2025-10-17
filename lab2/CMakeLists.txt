cmake_minimum_required(VERSION 3.16)
project(iomanip_project)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Catch2
find_package(Catch2 REQUIRED)

# Создание интерфейсной библиотеки
add_library(iomanip INTERFACE)
target_include_directories(iomanip INTERFACE include)

# Создание файла для защиты от пустой библиотеки
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/gprotect.cpp "#include <iomanip.hpp>\n")

# Сборка тестов
file(GLOB TESTS tests/*.cpp)
add_executable(tests_iomanip ${TESTS} ${CMAKE_CURRENT_BINARY_DIR}/gprotect.cpp)
target_link_libraries(tests_iomanip iomanip Catch2::Catch2WithMain)
