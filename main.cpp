#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include <algorithm>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

double GenRandNumber(std::mt19937& random_generator, double min, double max) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(random_generator);
}

void Print(std::vector<std::shared_ptr<Figure>>& curves, double t) {
    for (size_t i = 0; i < curves.size(); ++i) {
        std::cout << "Point of " << i << " container and t = " <<
                     t << ": " << curves[i]->GetPoint(t) << std::endl;
        std::cout << "Vector derivative of " << i << " container and t = " <<
                     t << ": " << curves[i]->GetDerivative(t) << std::endl;
    }
}

bool Comp(const std::shared_ptr<Circle>& first, const std::shared_ptr<Circle>& second) {
    return first->GetRadius() < second->GetRadius();
}

int main() {
    std::random_device device;
    std::mt19937 random_generator;
    random_generator.seed(device());
    std::vector<std::shared_ptr<Figure>> curves;
    curves.reserve(100);
    for (std::size_t i = 0; i < 100; ++i) {
        Vector center(0., 0., 0.);
        for (size_t j = 0; j < 3; ++j) {
            center[j] = GenRandNumber(random_generator, -10, 10);
        }
        if (center[2] < -3.) {
            double radius = GenRandNumber(random_generator, 0.01, 10);
            curves.push_back(std::make_shared<Circle>(radius, center));
        } else if (center[2] < 4.) {
            double radiusX = GenRandNumber(random_generator, 0.01, 10);
            double radiusY = GenRandNumber(random_generator, 0.01, 10);
            curves.push_back(std::make_shared<Ellipse>(radiusX, radiusY, center));
        } else {
            double radius = GenRandNumber(random_generator, 0.01, 10);
            double step = GenRandNumber(random_generator, 0.01, 10);
            curves.push_back(std::make_shared<Helix>(radius, step, center));
        }
    }

    Print(curves, M_PI / 4);
    
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }
    std::sort(circles.begin(), circles.end(), Comp);

    double RadiusSum = 0;
    for (const auto& circle : circles) {
        RadiusSum += circle->GetRadius();
    }

    std::cout << "Total radius sum: " << RadiusSum;
    return 0;
}
