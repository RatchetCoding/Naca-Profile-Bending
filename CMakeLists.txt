cmake_minimum_required(VERSION 3.4)
project (NACA)
add_executable(NACA src/NACA.c src/Math.c src/File_IO.c src/Node.c)
include_directories("include")
target_link_libraries(NACA m)

