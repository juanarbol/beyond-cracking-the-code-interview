add_library(stringmanipulation manipulation.cc)
target_include_directories(stringmanipulation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(stringmanipulationtest test.cpp)
target_link_libraries(stringmanipulationtest
  stringmanipulation
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(stringmanipulationtest)
