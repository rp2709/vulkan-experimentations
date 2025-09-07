cmake_minimum_required(VERSION 3.16)
project(VulkanTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VulkanTest main.cpp
        debug.cpp
        debug.hpp
        framerate.cpp
        framerate.hpp)

target_compile_options(VulkanTest PRIVATE -O2)

target_link_libraries(VulkanTest PRIVATE
        glfw
        vulkan
        dl
        pthread
        X11
        Xxf86vm
        Xrandr
        Xi
)
