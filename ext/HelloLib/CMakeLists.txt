#########################################################################################
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
# set the binary output
set(EXECUTABLE_OUTPUT_PATH ${HELLO_BASE_DIR}/bin)

#########################################################################################
# Library sources
#########################################################################################

# Set the source directory and header dirctory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/hellolib)

# group source files for the projects categories, here only one is used
file(GLOB LIBRARY_SOURCE ${SOURCE_DIR}/*.cpp)
file(GLOB LIBRARY_HEADER ${HEADER_DIR}/*.h)

# create main group
source_group(Library FILES ${LIBRARY_SOURCE} ${LIBRARY_HEADER})

# Add the sources and headers to one large file list
set(HELLOLIB_SOURCE ${HELLOLIB_SOURCE} ${LIBRARY_SOURCE})
set(HELLOLIB_HEADER ${HELLOLIB_HEADER} ${LIBRARY_HEADER})

#########################################################################################
# library dependencies
#########################################################################################

#######################################
# Threads
#######################################
# find Threads using CMake built in find command (sets the CMAKE_THREAD_LIBS_INIT variable)
find_package( Threads REQUIRED)

# Add the library to the dependent libs
set(HELLO_DEPENDENT_LIBS ${HELLO_DEPENDENT_LIBS} ${CMAKE_THREAD_LIBS_INIT})

#########################################################################################
# Library
#########################################################################################

# create executable by adding all source and header files
add_library(HelloLib ${HELLOLIB_SOURCE} ${HELLOLIB_HEADER})

# link HelloLib with Threads library
target_link_libraries(HelloLib ${HELLO_DEPENDENT_LIBS})