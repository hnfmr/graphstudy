add_executable(testGraph testGraph.cpp)
target_link_libraries(testGraph graphstudy ${TESTING_LIBS} pthread c++abi)
