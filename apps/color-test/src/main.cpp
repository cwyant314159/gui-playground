#include "raylib.h"
#include "palette.hpp"

#include <filesystem>
#include <stdexcept>

#ifndef FONT_RUNTIME_DIR
#error "FONT_RUNTIME_DIR not defined"
#endif

static Font LoadFontFile(std::string ttfFileName)
{
    using namespace std::filesystem;

    path fontDir = FONT_RUNTIME_DIR;
    path fontPath = fontDir / ttfFileName;

    if (!exists(fontPath))
    {
        throw std::runtime_error("Font directory does not exist\n");
    }

    Font font = LoadFont(fontPath.c_str());
    if (font.texture.id == 0)
    {
        throw std::runtime_error("Failed to load font\n");
    }

    return font;
}

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 1150;

    InitWindow(screenWidth, screenHeight, "Color Palette Test");
    SetTargetFPS(60);

    const Vector2 origin{
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f,
    };

    const Font font = LoadFontFile("SourceCodePro-Regular.ttf");
    Palette p{origin, font};

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        p.Draw();
        DrawFPS(2,2);
        EndDrawing();
    }

    return 0;
}