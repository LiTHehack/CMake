#########################################################################################
#                                                                                       #
# Simple project example for code structure using CMake                                 #
#                                                                                       #
# Copyright (c) 2014                                                                    #
#                                                                                       #
# Permission is hereby granted, free of charge, to any person obtaining a copy of this  #
# software and associated documentation files (the "Software"), to deal in the Software #
# without restriction, including without limitation the rights to use, copy, modify,    #
# merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    #
# permit persons to whom the Software is furnished to do so, subject to the following   #
# conditions:                                                                           #
#                                                                                       #
# The above copyright notice and this permission notice shall be included in all copies #
# or substantial portions of the Software.                                              #
#                                                                                       #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   #
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         #
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    #
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  #
# CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  #
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                         #
#########################################################################################

#########################################################################################
# General Settings
#########################################################################################

# Decide on minimum requirements (optional)
cmake_minimum_required (VERSION 2.8) 

# create and name your project
project (Hello)

# create variables for project folders
set(HELLO_BASE_DIR "${PROJECT_SOURCE_DIR}")
set(HELLO_EXT_DIR "${HELLO_BASE_DIR}/ext")

# Actiating c++11, requires a modern compiler
SET(CMAKE_CXX_FLAGS "-std=c++11")

# Initiate the DEPENDENT_LIBS variable to nothing (does not need to be done)
# this variable will be used to contain all libraries that we are linking with
set(DEPENDENT_LIBS "")

# add search path for CMake modules (not used at the moment)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${HELLO_EXT_DIR})

#########################################################################################
# Libraries and dependencies
#########################################################################################

#######################################
# The home-made library
#######################################
# set variables for home made library
set(HELLOLIB_ROOT_DIR "${HELLO_EXT_DIR}/HelloLib")

#include the library header files
include_directories("${HELLOLIB_ROOT_DIR}/include")

# add the library directory to CMake build (only building library, not linking), the
# library dependent settings occurs in the HELLOLIB_ROOT_DIR CMakeLists.txt
add_subdirectory(${HELLOLIB_ROOT_DIR})

# Add the home made library to the dependent libs
set(DEPENDENT_LIBS ${DEPENDENT_LIBS} HelloLib)


#########################################################################################
# Executable
#########################################################################################

# add the src directory to CMake build, the binary dependent settings occurs in the
# src folder CMakeLists.txt
add_subdirectory(src)
