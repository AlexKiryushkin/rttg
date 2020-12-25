
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(print_tuple_elements LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE( print_tuple_elements
                print_tuple_elements.cpp )
TARGET_LINK_LIBRARIES(print_tuple_elements rttg)
