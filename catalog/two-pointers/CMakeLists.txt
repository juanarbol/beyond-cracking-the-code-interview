add_library(twopointers twopointers.cc)
target_include_directories(twopointers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(twopointerstest test.cc)
target_link_libraries(twopointerstest
  twopointers
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(twopointerstest)
