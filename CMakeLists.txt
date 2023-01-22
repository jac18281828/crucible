cmake_minimum_required(VERSION 3.18)

project(${PROJECT_NAME} LANGUAGES CXX VERSION 1.0.0)

add_compile_options(-std=c++20)
add_compile_options(-Wall -pedantic -Wextra)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

set(SRC src/main.cpp)

add_executable(
  main
  ${SRC}
)

target_include_directories(main PRIVATE include)

enable_testing()

add_executable(
  crucible_test
  test/crucible_test.cpp
)

target_include_directories(crucible_test PRIVATE include)
target_link_libraries(
  crucible_test
  gtest_main
  m
)


include(GoogleTest)
gtest_discover_tests(crucible_test)

