cmake_minimum_required(VERSION 3.20)

project(HatRenderer
	VERSION 0.1.0
	LANGUAGES CXX
)

SET(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.4
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

add_executable(HatRenderer
	HatRenderer.cpp
	HatRenderer.h
)

target_link_libraries(HatRenderer
	PRIVATE
	glfw
)





#[[

# CMakeList.txt : CMake project for HatRenderer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("HatRenderer")

# Add source to this project's executable.
add_executable (HatRenderer "HatRenderer.cpp" "HatRenderer.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HatRenderer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

]]