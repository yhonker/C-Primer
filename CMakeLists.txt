cmake_minimum_required(VERSION 3.20)
project(CppTrain)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppTrain main.cpp Sales_data.cpp Sales_data.h Screen.cpp Screen.h Window_mgr.cpp Window_mgr.h Other.cpp Other.h Account.cpp Account.h)
