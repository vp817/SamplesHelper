# SamplesHelper - A project that will make creating samples easier.
#
# Copyright (C) 2023  vp817
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.20)

project(math)

set(CMAKE_CXX_STANDARD 17)

# The path depends on where you put the SamplesHelper directory.
get_filename_component(INTERNAL_SAMPLES_HELPER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../.. REALPATH)

# Include the samples helper cmake script
include(${INTERNAL_SAMPLES_HELPER_PATH}/SamplesHelper.cmake)

# First argument is the path to the directory of the SamplesHelper project
# Second argument is the path to your samples directory
initialize_samples_helper(${INTERNAL_SAMPLES_HELPER_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/examples)

set(MATH_EXAMPLE_NAME "none" CACHE STRING "Specify the example name to compile.")

add_library(math STATIC src/lib.cpp)

# Shared library (Working)
# add_library(math SHARED src/lib.cpp)

target_include_directories(math PRIVATE include)

if(MATH_EXAMPLE_NAME STREQUAL "all")
    add_all_samples()
else()
    add_sample(${MATH_EXAMPLE_NAME} "none")
endif()
