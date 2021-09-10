// tutorial used: https://studiofreya.com/3d-math-and-physics/simple-aabb-vs-aabb-collision-detection/

#ifndef AABB_h
#define AABB_h

#include <stdio.h>
#include "Point.h"
#include <math.h>

struct AABB {
    AABB() : c(), r() {}
    
    AABB(const Point & center, const Point & halfwidths)
    : c(center)
    , r(halfwidths)
    {}
    
    Point c;        // center point
    Point r;        // halfwidths
};

class Collision {
public:
    static float Abs(float a);
    static bool testAABBAABB(const AABB &a, const AABB &b);
};


#endif /* AABB_h */
