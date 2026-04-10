#ifndef RAYOPERATORS_HPP
#define RAYOPERATORS_HPP

#include "raylib.h"

#include <cstdint>
#include <functional>

inline bool operator==(const Color& lhs, const Color& rhs)
{
    return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b) && (lhs.a == rhs.a);
}

inline bool operator!=(const Color& lhs, const Color& rhs)
{
    return !(lhs == rhs);
}

namespace std{

template<>
struct hash<Color>
{
    std::size_t operator()(Color c) const noexcept
    {
        return static_cast<std::size_t>(
             static_cast<std::uint32_t>(c.r)         |
            (static_cast<std::uint32_t>(c.g) << 8U)  |
            (static_cast<std::uint32_t>(c.b) << 16U) |
            (static_cast<std::uint32_t>(c.a) << 24U)
        );
    }
};

} // namespace std

#endif // RAYOPERATORS_HPP