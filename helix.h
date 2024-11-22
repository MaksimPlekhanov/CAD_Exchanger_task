#pragma once

#include "figure.h"

class Helix : public Figure {
public:
    Helix() : radius_(0.), step_(0.) {}
    Helix(double radius, double step) : radius_(radius), step_(step) {
        center_ = Vector(0., 0., 0.);
    }
    Helix(double radius, double step, Vector center)
          : radius_(radius), step_(step), center_(center) {}
    Helix(const Helix&) = default;
    Vector GetPoint(double t) override;
    Vector GetDerivative(double t) override;
    ~Helix() = default;
private:
    double radius_ = 0.;
    double step_ = 0.;
    Vector center_;
};

Vector Helix::GetPoint(double t) {
    Vector point = Vector(radius_ * std::cos(t) + center_[0],
                          radius_ * std::sin(t) + center_[1],
                          step_ / (2 * M_PI) * t + center_[2]);
    return point;
}

Vector Helix::GetDerivative(double t) {
    Vector vect = Vector(radius_ * (-std::sin(t)),
                         radius_ * std::cos(t), step_ / (2 * M_PI));
    return vect;
}
