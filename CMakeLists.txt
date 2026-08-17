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
find_package(OpenGL REQUIRED)

add_executable(HatRenderer
	HatRenderer.cpp
	HatRenderer.h
)

target_link_libraries(HatRenderer
	PRIVATE
	glfw
	OpenGL::GL
)