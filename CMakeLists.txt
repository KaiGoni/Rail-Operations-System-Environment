cmake_minimum_required(VERSION 3.16)
project(Rail_Operations_System_Environment)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

add_executable(Rail_Operations_System_Environment
        src/main.cpp
        src/track.h
        src/track.cpp
        src/editor/interface.cpp
        src/editor/interface.h
        src/gui/panel.cpp
        src/gui/panel.h
        src/gui/elements.cpp
        src/gui/elements.h
        src/gui/panelManager.cpp
        src/gui/panelManager.h
        src/gui/uiConstants.h
        src/textureManager.cpp
        src/textureManager.h
)

target_link_libraries(Rail_Operations_System_Environment sfml-system sfml-window sfml-graphics)