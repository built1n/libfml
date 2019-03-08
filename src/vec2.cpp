#include <iostream>
#include <cmath>
#include <fml/vec2.h>
using std::ostream;
using namespace fml;

namespace fml {
    vec2::vec2() {
        v[0] = 0;
        v[1] = 0;
    }
    vec2::vec2(scalar x) {
        v[0] = x;
        v[1] = 0;
    }
    vec2::vec2(scalar x, scalar y) {
        v[0] = x;
        v[1] = y;
    }
    scalar &vec2::operator[](int index) {
        return v[index];
    }
    scalar vec2::operator[](int index) const {
        return v[index];
    }
    vec2 vec2::operator*(scalar scale) const {
        return vec2(v[0] * scale, v[1] * scale);
    }
    vec2 vec2::operator/(scalar scale) const {
        return vec2(v[0] / scale, v[1] / scale);
    }
    vec2 vec2::operator+(const vec2 &other)  const{
        return vec2(v[0] + other.v[0], v[1] + other.v[1]);
    }
    vec2 vec2::operator-(const vec2 &other) const {
        return vec2(v[0] - other.v[0], v[1] - other.v[1]);
    }
    vec2 vec2::operator-() const {
        return vec2(-v[0], -v[1]);
    }
    const vec2 &vec2::operator*=(scalar scale) {
        v[0] *= scale;
        v[1] *= scale;
        return *this;
    }
    const vec2 &vec2::operator/=(scalar scale) {
        v[0] /= scale;
        v[1] /= scale;
        return *this;
    }
    const vec2 &vec2::operator+=(const vec2 &other) {
        v[0] += other.v[0];
        v[1] += other.v[1];
        return *this;
    }
    const vec2 &vec2::operator-=(const vec2 &other) {
        v[0] -= other.v[0];
        v[1] -= other.v[1];
        return *this;
    }
    scalar vec2::magnitude() const {
        return sqrt(v[0] * v[0] + v[1] * v[1]);
    }
    scalar vec2::magnitudeSquared() const {
        return v[0] * v[0] + v[1] * v[1];
    }
    vec2 vec2::normalize() const {
        scalar m = sqrt(v[0] * v[0] + v[1] * v[1]);
        return vec2(v[0] / m, v[1] / m);
    }
    scalar vec2::dot(const vec2 &other) const {
        return v[0] * other.v[0] + v[1] * other.v[1];
    }
    std::ostream &operator<<(std::ostream &output, const vec2 &v) {
        return output << v[0] << " " << v[1];
    }

    std::istream &operator>>(std::istream &input, vec2 &v)
    {
        if(!(input >> v[0] >> v[1]))
            throw "error parsing vector";
        return input;
    }

    vec2 operator*(scalar scale, const vec2 &v)
    {
        return v * scale;
    }
}
