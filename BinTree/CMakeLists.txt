cmake_minimum_required(VERSION 3.6)
project(BinTree)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 14)

project (BinTree)

set(SOURCES
        main.cpp

        BinaryTree.cpp
        Data.cpp
        )

add_executable(BinTree ${SOURCES})

include_directories(BinTree
        PRIVATE
        ${PROJECT_SOURCE_DIR}/
        )
