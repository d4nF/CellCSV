cmake_minimum_required(VERSION 2.6)
project(cellcsvexample)

SET( cellcsvexample_SRCS
     src/example.cpp
)
SET( cellcsvexample_HDRS
     src/cellCsv.hpp
     src/timsort.hpp
)
add_executable(cellcsvexample ${cellcsvexample_SRCS})
set_property(TARGET cellcsvexample PROPERTY CXX_STANDARD 11)
set_property(TARGET cellcsvexample PROPERTY CXX_STANDARD_REQUIRED ON)
install(TARGETS cellcsvexample RUNTIME DESTINATION bin)
