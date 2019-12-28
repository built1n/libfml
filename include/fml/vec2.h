#ifndef VEC2_H
#define VEC2_H
#include <iostream>

#include "fml.h"

namespace fml {
    class vec2 {
    public:
        scalar v[2];
    public:
        vec2();
        vec2(scalar x);
        vec2(scalar x, scalar y);
        scalar &operator[](int index);
        scalar operator[](int index) const;
        vec2 operator*(scalar scale) const;
        vec2 operator/(scalar scale) const;
        vec2 operator+(const vec2 &other) const;
        vec2 operator-(const vec2 &other) const;
        vec2 operator-() const;
        const vec2 &operator*=(scalar scale);
        const vec2 &operator/=(scalar scale);
        const vec2 &operator+=(const vec2 &other);
        const vec2 &operator-=(const vec2 &other);
        scalar magnitude() const;
        scalar magnitudeSquared() const;
        vec2 normalize() const;
        vec2 rotateby(scalar angle);
        scalar dot(const vec2 &other) const;
    };

    vec2 operator*(scalar scale, const vec2 &v);

    std::ostream &operator<<(std::ostream &output, const vec2 &v);
    std::istream &operator>>(std::istream &input, vec3 &v);
}

#endif
