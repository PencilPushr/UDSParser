﻿# CMakeList.txt : CMake project for CANParser, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CANParser")

file (GLOB MAIN_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

file (GLOB_RECURSE SRC_FILES
	src/*.cpp
	src/*.h
)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${MAIN_FILES} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CANParser PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
