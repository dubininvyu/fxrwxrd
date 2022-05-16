#===============================================================================#
#   A GTA CR-MP plugin called by Fxrwxrd RolePlay                               #
#                                                                               #
#   Copyright (c) 2022, dubininvyu                                              #
#                                                                               #
#   Licensed under the Apache License, Version 2.0 (the "License");             #
#   you may not use this file except in compliance with the License.            #
#   You may obtain a copy of the License at                                     #
#                                                                               #
#       http://www.apache.org/licenses/LICENSE-2.0                              #
#                                                                               #
#   Unless required by applicable law or agreed to in writing, software         #
#   distributed under the License is distributed on an "AS IS" BASIS,           #
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.    #
#   See the License for the specific language governing permissions and         #
#   limitations under the License.                                              #
#===============================================================================#

cmake_minimum_required(VERSION 3.0)
include(CheckIncludeFiles)

#==============================================================================#
# Settings                                                                     #
#==============================================================================#
set(PLUGIN_NAME "srv_cr")
set(PLUGIN_VERSION_MAJOR 0)
set(PLUGIN_VERSION_MINOR 0)
set(PLUGIN_VERSION_BUILD 1)

set(PLUGIN_SUPPORTS_PROCESS_TICK FALSE)
set(PLUGIN_LINK_DEPENDENCIES "")
set(PLUGIN_COMPILE_DEFINITIONS "")
set(CMAKE_CXX_STANDARD 20)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list Plugin/src/*.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

file(GLOB PLUGIN_SRC # project files
        Plugin/src/*.cpp
        Plugin/src/*.h
        Plugin/src/*/*.cpp
        Plugin/src/*/*.h
        Plugin/src/*/*/*.cpp
        Plugin/src/*/*/*.h
        Plugin/src/*/*/*/*.cpp
        Plugin/src/*/*/*/*.h
        Plugin/src/*/*/*/*/*.cpp
        Plugin/src/*/*/*/*/*.h
        Plugin/src/*/*/*/*/*/*.cpp
        Plugin/src/*/*/*/*/*/*.h
        Plugin/src/*/*/*/*/*/*/*.cpp
        Plugin/src/*/*/*/*/*/*/*.h
        Plugin/src/*/*/*/*/*/*/*/*.cpp
        Plugin/src/*/*/*/*/*/*/*/*.h
        Plugin/src/*/*/*/*/*/*/*/*/*.cpp
        Plugin/src/*/*/*/*/*/*/*/*/*.h
        Plugin/src/*/*/*/*/*/*/*/*/*/*.cpp
        Plugin/src/*/*/*/*/*/*/*/*/*/*.h
        )

HEADER_DIRECTORIES(PLUGIN_DIR)

#==============================================================================#

project(${PLUGIN_NAME}
        LANGUAGES CXX
        VERSION ${PLUGIN_VERSION_MAJOR}.${PLUGIN_VERSION_MINOR}.${PLUGIN_VERSION_BUILD}
        )

# Check include files availability
set(REQUIRED_INCLUDE_FILES
        "inttypes.h"
        "stdint.h"
        "alloca.h"
        )

foreach(INCLUDE_FILE ${REQUIRED_INCLUDE_FILES})
    string(REGEX REPLACE "\\.|/" "_" DEFINITION_NAME "HAVE_${INCLUDE_FILE}")
    string(TOUPPER ${DEFINITION_NAME} DEFINITION_NAME)
    check_include_files("${INCLUDE_FILE}" ${DEFINITION_NAME})
    if(${DEFINITION_NAME})
        set(PLUGIN_COMPILE_DEFINITIONS ${PLUGIN_COMPILE_DEFINITIONS} "${DEFINITION_NAME}=1")
    endif()
endforeach()

string(TOLOWER ${PLUGIN_NAME} PLUGIN_NAME_LOWERCASE)
configure_file("plugin.inc.in" "${CMAKE_CURRENT_BINARY_DIR}/${PLUGIN_NAME_LOWERCASE}.inc")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Server/plugins/)

if(UNIX)
    #set(PLUGIN_SRC "${PLUGIN_SRC}")
    set(PLUGIN_COMPILE_DEFINITIONS ${PLUGIN_COMPILE_DEFINITIONS} "LINUX")
endif()
if(MINGW)
    set(PLUGIN_COMPILE_DEFINITIONS ${PLUGIN_COMPILE_DEFINITIONS} "HAVE_STDINT_H=1" "__need_size_t")
endif()

# Make sure the target is 32-bit
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
    endif()
endif()

set(PLUGIN_SUPPORTS_FLAGS "SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES")
if(PLUGIN_SUPPORTS_PROCESS_TICK)
    set(PLUGIN_SUPPORTS_FLAGS "${PLUGIN_SUPPORTS_FLAGS} | SUPPORTS_PROCESS_TICK")
endif()
configure_file("pluginconfig.h.in" "${CMAKE_CURRENT_BINARY_DIR}/pluginconfig.h")

add_library(${PLUGIN_NAME_LOWERCASE} SHARED ${PLUGIN_SRC})

target_include_directories(${PLUGIN_NAME_LOWERCASE} PUBLIC
        ${PLUGIN_DIR} # includes directory
        "D:/Projects/Fxrwxrd/Plugin/inc"
        )

target_link_directories(${PLUGIN_NAME_LOWERCASE} PRIVATE
        "D:/Projects/Fxrwxrd/Plugin/lib"
        "D:/Tools/MySQL/MySQL Server 8.0/lib"
        )

target_link_libraries(${PLUGIN_NAME_LOWERCASE}
        libmysql.a
        libboost_program_options-mgw8-mt-d-x32-1_79.a
        )

target_compile_features(${PLUGIN_NAME_LOWERCASE} PRIVATE cxx_range_for)

set_property(TARGET ${PLUGIN_NAME_LOWERCASE} APPEND_STRING PROPERTY "COMPILE_DEFINITIONS" ${PLUGIN_COMPILE_DEFINITIONS})
set_property(TARGET ${PLUGIN_NAME_LOWERCASE} PROPERTY PREFIX "")
if(MSVC)
    set(STR_PLUGIN_DEF_PROCESS_TICK "")
    if(PLUGIN_SUPPORTS_PROCESS_TICK)
        set(STR_PLUGIN_DEF_PROCESS_TICK "ProcessTick")
    endif()
    configure_file("plugin.def.in" "${CMAKE_CURRENT_BINARY_DIR}/plugin.def")
    set_property(TARGET ${PLUGIN_NAME_LOWERCASE}
            APPEND_STRING PROPERTY LINK_FLAGS "/DEF:\"${CMAKE_CURRENT_BINARY_DIR}/plugin.def\""
            )
endif()
if(MINGW)
    set_property(TARGET ${PLUGIN_NAME_LOWERCASE}
            APPEND_STRING PROPERTY LINK_FLAGS "-Wl,--kill-at"
            )
endif()
add_custom_command(
        TARGET "${PLUGIN_NAME_LOWERCASE}" POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/${PLUGIN_NAME_LOWERCASE}.inc
        ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>/${PLUGIN_NAME_LOWERCASE}.inc
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PLUGIN_NAME_LOWERCASE}.inc" DESTINATION "include")
install(TARGETS ${PLUGIN_NAME_LOWERCASE}
        LIBRARY DESTINATION "plugins"
        RUNTIME DESTINATION "plugins"
        )
if(WIN32)
    set(CPACK_GENERATOR "ZIP")
elseif(UNIX)
    set(CPACK_GENERATOR "TGZ")
endif()
set(CPACK_PACKAGE_NAME "${PLUGIN_NAME_LOWERCASE}")
set(CPACK_PACKAGE_VERSION_MAJOR ${PLUGIN_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PLUGIN_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PLUGIN_VERSION_BUILD})
include(CPack)