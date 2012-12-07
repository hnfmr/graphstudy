cmake_minimum_required(VERSION 2.8)

project(graphstudy)

# For Clang, disable TR1 tuple.
add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)

if (${UNIX})
  if ("$ENV{CLANGHOME}" STREQUAL "")
    message(FATAL_ERROR "CLANGHOME not defined.")
  else()
    set(CMAKE_C_COMPILER $ENV{CLANGHOME}/bin/clang)
    set(CMAKE_CXX_COMPILER $ENV{CLANGHOME}/bin/clang++)

    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH $ENV{CLANGHOME}/lib)

    set(CMAKE_USE_RELATIVE_PATHS TRUE)
  endif()
endif()

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}
)

set(TESTING_LIBS ${CMAKE_SOURCE_DIR}/lib/libgtest.a)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pipe -march=native -O3 -std=c++11 -stdlib=libc++")

add_library(graphstudy
            include/graph.h src/graph.cpp
	    include/trace.h src/trace.cpp
)

add_subdirectory(test)