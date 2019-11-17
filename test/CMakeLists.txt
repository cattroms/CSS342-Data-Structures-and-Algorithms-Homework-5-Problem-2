add_executable(binary_tree_tests main.cpp BinaryTreeTest.cpp)

include_directories(${CMAKE_LIBRARY_PATH})
link_directories(${LIBRARY_OUTPUT_PATH})

target_link_libraries(
                    binary_tree_tests
                    gtest)

add_test(
        NAME
        BinarySearchTreeTests
        COMMAND
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/binary_search_tests
)

