#ifndef SWATCH_HPP
#define SWATCH_HPP

#include "raylib.h"

#include <optional>
#include <string>

class Swatch
{
public:
    Swatch(const Vector2& origin, float width, float height, const Color& color, std::optional<Font> labelFont);
    void Draw() const;

private:
    Rectangle m_rect;
    Color m_color;
    Font m_font;
    std::string m_name;

    void DrawLabel() const;
};

#endif // SWATCH_HPP