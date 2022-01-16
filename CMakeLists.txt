cmake_minimum_required(VERSION 3.10.2)
project(CppTrain)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppTrain main.cpp " Program/Sales_data.cpp" 类/Sales_data.h 类/Screen.cpp 类/Screen.h 类/Window_mgr.cpp 类/Window_mgr.h 类/Other.cpp 类/Other.h 类/Account.cpp 类/Account.h 拷贝控制/HasPtr.cpp 拷贝控制/HasPtr.h 拷贝控制/Other.cpp 拷贝控制/Other.h 拷贝控制/NoCopy.cpp 拷贝控制/NoCopy.h 拷贝控制/Message.cpp 拷贝控制/Message.h 拷贝控制/StrVec.cpp 拷贝控制/StrVec.h 拷贝控制/Folder.cpp 拷贝控制/Folder.h)
