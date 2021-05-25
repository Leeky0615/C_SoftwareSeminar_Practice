cmake_minimum_required(VERSION 3.19)
project(SWSeminar)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fexec-charset=CP949")

add_executable(single_file_exe SWSeminar/[0525_Lab12]/[0525_Lab12]Exercise2.c)
set_target_properties(single_file_exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/SWSeminar/")
