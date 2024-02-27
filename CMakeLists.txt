cmake_minimum_required(VERSION 3.10)
project(HonorsProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include the Dear ImGui and Gamma headers
include_directories(${CMAKE_SOURCE_DIR}/imgui)
include_directories(${CMAKE_SOURCE_DIR}/imgui/backends)
include_directories(${CMAKE_SOURCE_DIR}/Gamma)

# Add source files
file(GLOB PROJECT_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB IMGUI_SOURCES ${CMAKE_SOURCE_DIR}/imgui/*.cpp)
set(IMGUI_BACKENDS_SOURCES
    ${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
)

# Add Gamma source files if Gamma is not header-only

# Specify the executable to be built
add_executable(HonorsProject ${PROJECT_SOURCES} ${IMGUI_SOURCES} ${IMGUI_BACKENDS_SOURCES})

# Find and link OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
target_link_libraries(HonorsProject OpenGL::GL glfw)
