# Тесты с Catch2
find_package(Catch2 REQUIRED)
find_package(GTest REQUIRED)

add_executable(derivative_tests test_derivative.cpp ../src/derivative.cpp)
target_include_directories(derivative_tests PUBLIC ../include)
target_link_libraries(derivative_tests Catch2::Catch2WithMain)

add_executable(derivative_gtest gtest_derivative.cpp ../src/derivative.cpp)
target_include_directories(derivative_gtest PUBLIC ../include)
target_link_libraries(derivative_gtest GTest::gtest GTest::gtest_main)
