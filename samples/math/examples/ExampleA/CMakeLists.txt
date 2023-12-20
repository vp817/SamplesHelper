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

project(ExampleA)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(MATHLIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../.. REALPATH)

add_executable(ExampleA src/main.cpp)
inject_sample_helper(ExampleA) # Must be below add_executable
target_include_directories(ExampleA PRIVATE ${MATHLIB_PATH}/include)

target_link_libraries(ExampleA PRIVATE math)