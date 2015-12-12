cmake_minimum_required(VERSION 3.3)
project(ucd_csi2312_pa2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Cluster.cpp
    Cluster.h
    ClusteringTests.cpp
    ClusteringTests.h
    ErrorContext.cpp
    ErrorContext.h
    Main.cpp
    Point.cpp
    Point.h
    points.csv)

add_executable(ucd_csi2312_pa2 ${SOURCE_FILES})