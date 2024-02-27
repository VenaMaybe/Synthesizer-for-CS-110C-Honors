cmake_minimum_required(VERSION 3.10)
project(HonorsProject)

# Set the default build type to Debug if it's not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(PORTAUDIO REQUIRED portaudio-2.0)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Add the executable
file(GLOB PROJECT_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB IMGUI_SOURCES ${CMAKE_SOURCE_DIR}/imgui/*.cpp)
set(IMGUI_BACKENDS_SOURCES
    ${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
)
add_executable(HonorsProject ${PROJECT_SOURCES} ${IMGUI_SOURCES} ${IMGUI_BACKENDS_SOURCES})

# Add and link the Gamma static library
add_library(Gamma STATIC IMPORTED)
set_property(TARGET Gamma PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Gamma/build/lib/libGamma.a)

# Target include directories
target_include_directories(HonorsProject PRIVATE
    ${CMAKE_SOURCE_DIR}/imgui
    ${CMAKE_SOURCE_DIR}/imgui/backends
    ${CMAKE_SOURCE_DIR}/Gamma
    ${PORTAUDIO_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(HonorsProject
    OpenGL::GL
    glfw
    Gamma
    ${PORTAUDIO_LIBRARIES}
)
