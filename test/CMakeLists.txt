add_executable(
    unit_tests
    test_gcd.cpp
    )

target_link_libraries(
    unit_tests
    gtest
    gtest_main
    util
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
add_dependencies(unit_tests third_parties)
