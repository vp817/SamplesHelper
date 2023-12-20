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

set(SAMPLES_HELPER_PATH "")
set(SAMPLES_DIRECTORY_PATH "")

macro(initialize_samples_helper samples_helper_path samples_directory_path)
    message(STATUS "Initializing SamplesHelper...")

    if(NOT IS_DIRECTORY ${samples_directory_path})
        message(FATAL_ERROR "The samples helper path is not a directory or is not found.")
    endif()

    if(NOT IS_DIRECTORY ${samples_directory_path})
        message(FATAL_ERROR "The samples directory path is not a directory or is not found.")
    endif()

    set(SAMPLES_HELPER_PATH ${samples_helper_path})
    set(SAMPLES_DIRECTORY_PATH ${samples_directory_path})

    message(STATUS "Successfully initialized SamplesHelper...")
endmacro()

macro(add_sub_dir_if_exists path)
    if(NOT IS_DIRECTORY ${path})
        message(SEND_ERROR "The path ${path} is not found to be added as a subdirectory.")
    endif()

    add_subdirectory(${path})
endmacro()

macro(add_sample sample_name default_value)
    if(NOT ${sample_name} STREQUAL ${default_value})
        add_sub_dir_if_exists(${SAMPLES_DIRECTORY_PATH}/${sample_name})
    endif()
endmacro()

macro(inject_sample_helper target)
    message(STATUS "Injecting sample helper ${target} to the current project.")
    target_include_directories(${target} PRIVATE ${SAMPLES_HELPER_PATH}/src)
    message(STATUS "Successfully injected sample helper to ${target}")
endmacro()

macro(add_all_samples)
    file(GLOB sample_directories "${SAMPLES_DIRECTORY_PATH}/*")

    foreach(sample_directory ${sample_directories})
        add_sub_dir_if_exists(${sample_directory})
    endforeach()
endmacro()
