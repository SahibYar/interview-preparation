cmake_minimum_required(VERSION 3.12)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib/leetcode)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib/leetcode)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin/leetcode)

add_executable(two-sum 0001-two-sum.cpp)
add_executable(add-two-numbers 0002-add-two-numbers.cpp)
add_executable(longest-substring-without-repeating-characters 0003-longest-substring-without-repeating-characters.cpp)
add_executable(median-of-two-sorted-arrays 0004-median-of-two-sorted-arrays.cpp)
add_executable(longest-palindromic-substring 0005-longest-palindromic-substring.cpp)
add_executable(zigzag-conversion 0006-zigzag-conversion.cpp)
install(CODE "MESSAGE(\"Installing ${PROJECT_NAME} \")")
install(TARGETS
        two-sum
        add-two-numbers
        longest-substring-without-repeating-characters
        median-of-two-sorted-arrays
        longest-palindromic-substring
        zigzag-conversion

        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h*")
