#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

#include <iostream>

void WriteColor(std::ostream &out, Color pixelColor)
{
    out <<Cast(pixelColor.x())<<' '<<Cast(pixelColor.y())<<' '<<Cast(pixelColor.z())<<'\n';
}

inline int Cast(double t) {
    return static_cast<int>(255.999 * t);
}

#endif