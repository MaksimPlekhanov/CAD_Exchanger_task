#pragma once

#include "figure.h"

class Circle : public Figure {
public:
    Circle() : radius_(0.) {
        center_ = Vector(0., 0., 0.);
    }
    Circle(double radius) : radius_(radius) {
        center_ = Vector(0., 0., 0.);
    }
    Circle(double radius, Vector center)
           : radius_(radius), center_(center) {}
    Circle(const Circle&) = default;
    Vector GetPoint(double t) override;
    Vector GetDerivative(double t) override;
    double GetRadius() {
        return radius_;
    }
    ~Circle() override {}
private:
    double radius_ = 0.;
    Vector center_;
};

Vector Circle::GetPoint(double t) {
    Vector point = Vector(radius_ * std::cos(t) + center_[0],
                          radius_ * std::sin(t) + center_[1], 0.);
    return point;
}

Vector Circle::GetDerivative(double t) {
    Vector vect = Vector(radius_ * (-std::sin(t)),
                         radius_ * std::cos(t), 0.);
    return vect;
}
