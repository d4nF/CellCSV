cmake_minimum_required(VERSION 2.6)
project(cellcsv)

add_executable(cellcsv main.cpp)

install(TARGETS cellcsv RUNTIME DESTINATION bin)
