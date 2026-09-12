cmake_minimum_required(VERSION 3.20)

project(cpp_data_structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(linked_list src/linked_list.cpp)
target_include_directories(linked_list PUBLIC include)

add_executable(linked_list_test tests/linked_list_test.cpp)
target_link_libraries(linked_list_test PRIVATE linked_list)

enable_testing()
add_test(NAME linked_list_test COMMAND linked_list_test)
