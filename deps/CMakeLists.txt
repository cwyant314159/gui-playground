#
# googletest
#
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest EXCLUDE_FROM_ALL)

#
# STB
#
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE stb)

#
# raylib
#
set(CUSTOMIZE_BUILD OFF)
add_subdirectory(raylib EXCLUDE_FROM_ALL)

#
# Generic raygui Interface Library
#
add_library(raygui-generic INTERFACE)
target_include_directories(raygui-generic INTERFACE raygui/src)
target_link_libraries(raygui-generic INTERFACE raylib)

#
# Dear ImGui
#
add_library(imgui STATIC)
target_sources(imgui
    PUBLIC
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
)
target_include_directories(imgui PUBLIC imgui)
set_target_properties(imgui PROPERTIES EXCLUDE_FROM_ALL TRUE)

#
# raylib/Dear ImGui Integration Library
#
add_library(rlImGui STATIC)
target_sources(rlImGui PRIVATE rlImGui/rlImGui.cpp)
target_include_directories(rlImGui PUBLIC rlImGui)
target_link_libraries(rlImGui PUBLIC raylib imgui)
set_target_properties(rlImGui PROPERTIES EXCLUDE_FROM_ALL TRUE)
