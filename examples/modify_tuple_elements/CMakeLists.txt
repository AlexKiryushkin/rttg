
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(modify_tuple_elements LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE( modify_tuple_elements
                modify_tuple_elements.cpp )
TARGET_LINK_LIBRARIES(modify_tuple_elements rttg)
