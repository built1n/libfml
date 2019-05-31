#ifndef QUAT_H
#define QUAT_H

#include "fml.h"
#include <iostream>

namespace fml {
    class quat {
    public:
        scalar w, x, y, z;
    public:
        quat(scalar w, scalar x, scalar y, scalar z);
        quat(scalar x, scalar y, scalar z);
        quat(scalar w, vec3 vec);
        quat(vec3 vec);
        quat();

        operator vec3() const;

        quat conjugate() const;

        /* returns <cos / 2, x * sin / 2, y * sin / 2, z * sin / 2> */
        static quat from_angleaxis(scalar angle, vec3 axis);

        /* returns rotquat * this * rotquat.conj */
        quat rotateby(const quat &rotquat) const;
    };

    quat operator*(const quat &, const quat &);
    std::ostream &operator<<(std::ostream &os, const quat &);
}
#endif
