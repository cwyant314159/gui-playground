#ifndef PALETTE_HPP
#define PALETTE_HPP

#include "raylib.h"
#include "swatch.hpp"

#include <array>
#include <optional>
#include <vector>

class Palette
{
public:
    Palette(const Vector2& origin, std::optional<Font> labelFont = std::nullopt);
    void Draw() const;

private:
    static constexpr Color  CANVAS_BG_COLOR   = BLACK;
    static constexpr size_t MAX_SWATCHES      = 26 + 1; // builtin + 1 custom
    static constexpr size_t SWATCHES_PER_ROW  = 3;
    static constexpr float  SWATCH_PADDING_PX = 2.0f;
    static constexpr float  SWATCH_WIDTH      = 220.0f;
    static constexpr float  SWATCH_HEIGHT     = 120.0f;


    static constexpr std::array<Color, MAX_SWATCHES> SWATCH_COLORS{
        LIGHTGRAY, GRAY,     DARKGRAY,
        YELLOW,    GOLD,     ORANGE,
        PINK,      RED,      MAROON,
        GREEN,     LIME,     DARKGREEN,
        SKYBLUE,   BLUE,     DARKBLUE,
        PURPLE,    VIOLET,   DARKPURPLE,
        BEIGE,     BROWN,    DARKBROWN,
        WHITE,     BLACK,    BLANK,
        MAGENTA,   RAYWHITE, Color{67, 67, 67, 255}
    };

    Rectangle m_swatchCanvas;
    std::vector<Swatch> m_swatches;

    Swatch ConfigureSwatch(const Vector2& origin, const Color& color, std::optional<Font> labelFont);
};

#endif // PALETTE_HPP