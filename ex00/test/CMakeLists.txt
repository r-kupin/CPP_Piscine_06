# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with lib
add_executable(Google_Tests_run char_test.cpp  correct_input.cpp  int_test.cpp  ratio_test.cpp  wrong_input.cpp)
target_link_libraries(Google_Tests_run ex00_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)