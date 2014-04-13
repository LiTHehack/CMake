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

# set the binary output
set(EXECUTABLE_OUTPUT_PATH ${HELLO_BASE_DIR}/bin)

# Set the source directory to the current directory, use a 
# subdirectory for large projects
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# group source files for the projects categories, here only one is used
file(GLOB MAIN_SOURCE ${SOURCE_DIR}/*.cpp)
file(GLOB MAIN_HEADER ${SOURCE_DIR}/*.h)

# create main group
source_group(Main FILES ${MAIN_SOURCE} ${MAIN_HEADER})

# Add the sources and headers to one large file list
set(HELLO_SOURCE ${HELLO_SOURCE} ${MAIN_SOURCE})
set(HELLO_HEADER ${HELLO_HEADER} ${MAIN_HEADER})

# create executable by adding all source and header files
add_executable(Hello ${HELLO_SOURCE} ${HELLO_HEADER})

# link with the dependent libraries
target_link_libraries(Hello ${DEPENDENT_LIBS})