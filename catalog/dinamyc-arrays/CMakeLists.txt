add_library(dynamic-array INTERFACE)
target_include_directories(dynamic-array INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dynamic-array-test test.cpp)
target_link_libraries(dynamic-array-test
  dynamic-array
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(dynamic-array-test)
