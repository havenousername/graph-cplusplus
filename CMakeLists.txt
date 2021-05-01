cmake_minimum_required(VERSION 3.19)
project(LIS)

set(CMAKE_CXX_STANDARD 14)

add_executable(LIS main.cpp graph/Graph.cpp graph/Graph.h interfaces/GraphInterface.hpp graph-representation/AdjancencyMatrixGraph.cpp graph-representation/AdjancencyMatrixGraph.h expeptions/GraphExceptions.cpp expeptions/GraphExceptions.h enums/GraphTypeEnum.h interfaces/GraphCalculationsInterface.hpp enums/ShortestPathFunctionEnum.h)