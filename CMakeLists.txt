cmake_minimum_required(VERSION 3.20)

project(HatRenderer
	VERSION 0.1.0
	LANGUAGES C CXX
)

SET(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
	glad
	GIT_REPOSITORY https://github.com/Dav1dde/glad.git
	GIT_TAG 73db193f853e2ee079bf3ca8a64aa2eaf645904
	SOURCE_SUBDIR cmake
)

FetchContent_MakeAvailable(glad)

glad_add_library(
	glad_gl_core_33
	REPRODUCTIBLE
	API gl:core=3.3
)

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

	Graphics/VertexBuffer.cpp
	Graphics/VertexBuffer.h

	Graphics/VertexArray.cpp
	Graphics/VertexArray.h

	Graphics/Renderer.cpp
	Graphics/Renderer.h

	Graphics/Shader.cpp 
	Graphics/Shader.h

	Graphics/Math/Mat4.cpp
	Graphics/Math/Mat4.h
	Graphics/Math/Vec3.cpp
	Graphics/Math/Vec3.h

	Graphics/IndexBuffer.cpp
	
  "Graphics/VertexArray.cpp" "Graphics/VertexArray.h" "Graphics/Math/Vec3.h" "Graphics/Math/Mat4.h" "Graphics/Math/Mat4.cpp" "Graphics/Math/Vec3.cpp" "Graphics/IndexBuffer.h" "Graphics/IndexBuffer.cpp")

target_compile_definitions(HatRenderer
	PRIVATE
	HATRENDERER_SHADER_DIR="${CMAKE_SOURCE_DIR}/shaders"
)

target_link_libraries(HatRenderer
	PRIVATE
	glfw
	OpenGL::GL
	glad_gl_core_33
)