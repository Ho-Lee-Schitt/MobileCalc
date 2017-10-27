cmake_minimum_required(VERSION 3.2)
project(MobileCalc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        MobileCalc/Customer.cpp
        MobileCalc/Customer.h
        MobileCalc/MobileCalc.cpp
        MobileCalc/Plan.cpp
        MobileCalc/Plan.h
        MobileCalc/stdafx.cpp
        MobileCalc/stdafx.h
        MobileCalc/targetver.h)

add_executable(MobileCalc ${SOURCE_FILES})
