cmake_minimum_required(VERSION 3.18)

project(${PROJECT_NAME} LANGUAGES CXX VERSION 1.0.0)

add_compile_options(-std=c++20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

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

