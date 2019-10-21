cmake_minimum_required(VERSION 2.8)

project(CGMBE)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 17)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_custom_target(third_parties)
include(ExternalProject)
ExternalProject_Add(
  google_gtest
  URL https://github.com/google/googletest/archive/release-1.8.1.zip
  PREFIX ${PROJECT_SOURCE_DIR}/third/gtest
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${PROJECT_SOURCE_DIR}/third/gtest/build -DBUILD_SHARED_LIBS=OFF
  )
add_dependencies(third_parties google_gtest)

include_directories(
  ${PROJECT_SOURCE_DIR}/third/gtest/build/include
  )

link_directories(
  ${PROJECT_SOURCE_DIR}/third/gtest/build/lib
  )

# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
