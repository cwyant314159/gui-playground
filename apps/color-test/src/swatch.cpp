#include "swatch.hpp"

#include "rayoperators.hpp"
#include <cstdint>
#include <format>
#include <string_view>
#include <unordered_map>

Swatch::Swatch(const Vector2& origin, float width, float height, const Color& color, std::optional<Font> labelFont)
    : m_rect{
        origin.x - (width / 2.0f),
        origin.y - (height / 2.0f),
        width,
        height
    }
    , m_color{color}
{
    // If a font is not provided to the constructor, fallback to the raylib
    // default font.
    m_font = labelFont.value_or(GetFontDefault());

    // Use a map based lookup table to convert the Color struct into a string
    // containing the color name. If the provided color does not have a name
    // fallback to the RGB numerical value.
    const std::unordered_map<Color, std::string_view> colorMap{
        {LIGHTGRAY,  "LightGray"},
        {GRAY,       "Gray"},
        {DARKGRAY,   "DarkGray"},
        {YELLOW,     "Yellow"},
        {GOLD,       "Gold"},
        {ORANGE,     "Orange"},
        {PINK,       "Pink"},
        {RED,        "Red"},
        {MAROON,     "Maroon"},
        {GREEN,      "Green"},
        {LIME,       "Lime"},
        {DARKGREEN,  "DarkGreen"},
        {SKYBLUE,    "SkyBlue"},
        {BLUE,       "Blue"},
        {DARKBLUE,   "DarkBlue"},
        {PURPLE,     "Purple"},
        {VIOLET,     "Violet"},
        {DARKPURPLE, "DarkPurple"},
        {BEIGE,      "Beige"},
        {BROWN,      "Brown"},
        {DARKBROWN,  "DarkBrown"},
        {WHITE,      "White"},
        {BLACK,      "Black"},
        {BLANK,      "Blank"},
        {MAGENTA,    "Magenta"},
        {RAYWHITE,   "RayWhite"},
    };

    const auto it = colorMap.find(m_color);
    if (it != colorMap.end())
    {
        m_name = it->second;
    } else {
        m_name = std::format("{:3}, {:3}, {:3}", m_color.r, m_color.g, m_color.b);
    }

}

void Swatch::Draw() const
{
    DrawRectangleRec(m_rect, m_color);
    DrawLabel();
}

void Swatch::DrawLabel() const
{
    // Constants
    constexpr float textPadding    = 4.0f;
    constexpr Color labelBoxColor  = BLACK;
    constexpr Color labelTextColor = WHITE;

    const float fontSize = m_font.baseSize * 1.0f;
    const float spacing  = 1.0f;

    // Measure the label text using the swatch's font.
    Vector2 textSize = MeasureTextEx(m_font, m_name.c_str(), fontSize, spacing);
    
    // Draw the label box
    float labelWidth  = textSize.x + (2 * textPadding);
    float labelHeight = textSize.y + (2 * textPadding);

    Rectangle labelBox{
        m_rect.x + ((m_rect.width  - labelWidth)  / 2),
        m_rect.y + ((m_rect.height - labelHeight) / 2),
        labelWidth,
        labelHeight
    };

    DrawRectangleRec(labelBox, labelBoxColor);

    // Draw the text
    Vector2 textPosition{
        labelBox.x + ((labelBox.width  - textSize.x) / 2),
        labelBox.y + ((labelBox.height - textSize.y) / 2)
    };

    DrawTextEx(m_font, m_name.c_str(), textPosition, fontSize, spacing, labelTextColor);
}
