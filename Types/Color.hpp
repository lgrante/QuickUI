#ifndef __COLOR_H__
#define __COLOR_H__

#include "Types.hpp"
#include <type_traits>


template<typename T>
class Color
{
    static_assert(std::is_signed<T>, "Incorect template type: color components must be positive.");

    public:
        Color(const T &r, const T &g, const T &b, const T &a) : r(r), g(g), b(b), a(a) {}
        Color(const Color &other) : a(other.a), r(other.r), g(other.g), b(other.b) {}

        Color<T> operator=(const Color<T> other)
        {
            a = other.a;
            r = other.r;
            g = other.g;
            b = other.b;
            return *this;
        }

        bool operator==(const Color<T> other) const
        {
            return (a == other.a && r == other.r && g == other.g && b == other.b);
        }

        T a;
        T r;
        T g;
        T b;
};

template<> Color<quick::f32>::Color(const quick::f32 &a, const quick::f32 &r, const quick::f32 &g, const quick::f32 &b)
    : 
    a(static_cast<quick::s32>(a)), r(static_cast<quick::s32>(r)), 
    g(static_cast<quick::s32>(g)), b(static_cast<quick::s32>(b))
{
}

template<> Color<quick::f64>::Color(const quick::f64 &a, const quick::f64 &r, const quick::f64 &g, const quick::f64 &b)
    : 
    a(static_cast<quick::s64>(a)), r(static_cast<quick::s64>(r)), 
    g(static_cast<quick::s64>(g)), b(static_cast<quick::s64>(b))
{
}

#endif