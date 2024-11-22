#pragma once
#include <array>

class Vector {
public:
    Vector() : vect_{0., 0., 0.} {}
    Vector(double x, double y, double z) : vect_{x, y, z} {}

    double& operator[](std::size_t ind) {
        return vect_[ind];
    }
    double operator[](std::size_t ind) const {
        return vect_[ind];
    };

private:
    std::array<double, 3> vect_;
};

std::ostream& operator<<(std::ostream& out, const Vector& vect) {
    return out << vect[0] << " " << vect[1] << " " << vect[2];
}
