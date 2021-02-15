cmake_minimum_required(VERSION 3.14)

project(rttg_examples CXX)

include(FetchContent)
FetchContent_Declare(rttg SOURCE_DIR "${PROJECT_SOURCE_DIR}/..")
FetchContent_MakeAvailable(rttg)

foreach(name IN ITEMS modify_tuple_elements
                      print_tuple_elements
                      access_individual_element
                      vector_indices)
  add_executable("${name}" "${name}.cpp")
  target_link_libraries("${name}" PRIVATE rttg::rttg)
  target_compile_features("${name}" PRIVATE cxx_std_17)
endforeach()
