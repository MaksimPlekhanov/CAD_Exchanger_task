#pragma once

#include "figure.h"

class Ellipse : public Figure {
public:
    Ellipse() : radiusX_(0.), radiusY_(0.) {
        center_ = Vector(0., 0., 0.);
    }
    Ellipse(double radiusX, double radiusY)
            : radiusX_(radiusX), radiusY_(radiusY) {
                center_ = Vector(0., 0., 0.);
    }
    Ellipse(double radiusX, double radiusY, Vector center)
            : radiusX_(radiusX), radiusY_(radiusY), center_(center) {}
    Ellipse(const Ellipse&) = default;
    Vector GetPoint(double t) override;
    Vector GetDerivative(double t) override;
    ~Ellipse() = default;
private:
    double radiusX_ = 0.;
    double radiusY_ = 0.;
    Vector center_;
};

Vector Ellipse::GetPoint(double t) {
    Vector point = Vector(radiusX_ * std::cos(t) + center_[0],
                          radiusY_ * std::sin(t) + center_[1], 0.);
    return point;
}

Vector Ellipse::GetDerivative(double t) {
    Vector vect = Vector(radiusX_ * (-std::sin(t)),
                         radiusY_ * std::cos(t), 0.);
    return vect;
}
