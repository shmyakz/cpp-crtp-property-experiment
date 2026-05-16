cmake_minimum_required(VERSION 4.0)
project(Properties)

set(CMAKE_CXX_STANDARD 23)

add_executable(Properties main.cpp
	Source/Property.h
	Source/GroupProperty.cpp
	Source/GroupProperty.h
	Source/IntegerProperty.cpp
	Source/IntegerProperty.h
)
