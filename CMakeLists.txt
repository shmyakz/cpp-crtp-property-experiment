cmake_minimum_required(VERSION 4.0)
project(Properties)

set(CMAKE_CXX_STANDARD 23)

add_executable(Properties main.cpp
	Source/property.h
	Source/groupproperty.cpp
	Source/GroupProperty.h
	Source/IntegerProperty.cpp
	Source/IntegerProperty.h
)
