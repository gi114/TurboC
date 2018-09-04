cmake_minimum_required(VERSION 3.10)
project(TurboCSSP)

set(CMAKE_CXX_STANDARD 11)

add_executable(TurboCSSP
        turbo
        turboCMain.c)
