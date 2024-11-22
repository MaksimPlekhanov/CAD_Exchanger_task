#pragma once
#include <functional>
#include <math.h>

#include "vector.h"

class Figure {
public:
    Figure() = default;
    Figure(const Figure&) = default;
    virtual Vector GetPoint(double t) = 0;
    virtual Vector GetDerivative(double t) = 0;
    virtual ~Figure() = default;
};
