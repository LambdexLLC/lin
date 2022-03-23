add_executable(test_0 test_0.cpp)
target_link_libraries(test_0 PUBLIC lbx-lin)
add_test(NAME test_0 COMMAND test_0)
