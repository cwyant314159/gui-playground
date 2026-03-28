#
# STB
#
add_library(stb INTERFACE)
target_include_directories(stb
    INTERFACE
        stb
)

#
# raylib
#
set(CUSTOMIZE_BUILD OFF)
add_subdirectory(raylib)

#
# Generic raygui Interface Library
#
add_library(raygui-generic INTERFACE)
target_include_directories(raygui-generic
    INTERFACE
        raygui/src/
)

#
# Dear ImGui
#
# Define the core ImGui library
add_library(imgui STATIC)
target_sources(imgui
    PUBLIC
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
)
target_include_directories(imgui
    PUBLIC
        imgui
)

#
# raylib/Dear ImGui Integration Library
#
add_library(rlImGui STATIC)
target_sources(rlImGui
    PRIVATE
        rlImGui/rlImGui.cpp
)
target_include_directories(rlImGui
    PUBLIC
        rlImGui
)
target_link_libraries(rlImGui
    PUBLIC
        raylib
        imgui
)

#
# SDL
#
# TODO add option to enable SDL from command line
# add_subdirectory(SDL)
