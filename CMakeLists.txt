cmake_minimum_required(VERSION 3.20)
project(dex)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        dex main.cpp
        DexParseHelper.cpp
        DexParseHelper.h
        DexShowHelper.cpp
        DexShowHelper.h
        dex.h
        class/annotation/AnnotationParser.cpp
        class/annotation/AnnotationParser.h
)
