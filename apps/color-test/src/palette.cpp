#include "palette.hpp"

#include <cmath>

Palette::Palette(const Vector2& origin, std::optional<Font> labelFont)
{
    // Use math tricks to compute the number of rows. The number of rows is
    // the number of swatches divided by swatches per row rounded up.
    constexpr size_t numRows = (MAX_SWATCHES + (SWATCHES_PER_ROW - 1)) / SWATCHES_PER_ROW;

    // When computing the width and height, remember to account for the padding between
    // swatches. The total padding can be computed as:
    //      padding = ((swatch_dimension_count - 1) + 2) * padding
    //              = (swatch_dimension_count + 1) * padding
    const float width  = (SWATCHES_PER_ROW * SWATCH_WIDTH) + ((SWATCHES_PER_ROW + 1) * SWATCH_PADDING_PX);

    const float height = (numRows * SWATCH_HEIGHT) + ((numRows + 1) * SWATCH_PADDING_PX);

    m_swatchCanvas = {
        origin.x - (width / 2.0f),
        origin.y - (height / 2.0f),
        width,
        height
    };

    for (std::size_t col = 0; col < SWATCHES_PER_ROW; ++col)
    {
        for (std::size_t row = 0; row < numRows; ++row)
        {
            const std::size_t idx = col + (row * SWATCHES_PER_ROW);
            if (idx < SWATCH_COLORS.size())
            {
                // Anchor points for the (0,0) swatch
                const float xAnchor = m_swatchCanvas.x + SWATCH_PADDING_PX + (SWATCH_WIDTH  / 2);
                const float yAnchor = m_swatchCanvas.y + SWATCH_PADDING_PX + (SWATCH_HEIGHT / 2);
                
                
                const float x = xAnchor + (col * (SWATCH_WIDTH  + SWATCH_PADDING_PX));
                const float y = yAnchor + (row * (SWATCH_HEIGHT + SWATCH_PADDING_PX));
                const Vector2 swatchOrigin{x, y};

                m_swatches.push_back(ConfigureSwatch(swatchOrigin, SWATCH_COLORS.at(idx), labelFont));
            }
        }
    }
}

void Palette::Draw() const
{
    DrawRectangleRec(m_swatchCanvas, CANVAS_BG_COLOR);
    
    for (const Swatch& s : m_swatches)
    {
        s.Draw();
    }
}

Swatch Palette::ConfigureSwatch(const Vector2& origin, const Color& color, std::optional<Font> labelFont)
{
    return Swatch{origin, SWATCH_WIDTH, SWATCH_HEIGHT, color, labelFont};
}