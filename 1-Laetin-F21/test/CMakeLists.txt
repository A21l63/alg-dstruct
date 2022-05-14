project(gtest)

add_subdirectory(lib)
include_directories(${lib}/include ${lib})


add_executable(gtest_run test.cpp)

target_link_libraries(gtest_run gtest gtest_main)