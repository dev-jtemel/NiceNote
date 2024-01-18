cmake_minimum_required(VERSION 3.20)

project(nice-note
        VERSION 1.0
        DESCRIPTION "A nice note project"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)

add_subdirectory(nice_note)