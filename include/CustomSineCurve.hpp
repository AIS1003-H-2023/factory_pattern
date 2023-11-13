
#ifndef FACTORY_PATTERN_CUSTOMSINECURVE_HPP
#define FACTORY_PATTERN_CUSTOMSINECURVE_HPP

#include "threepp/extras/core/Curve.hpp"
#include "threepp/math/MathUtils.hpp"

struct CustomSineCurve: threepp::Curve3 {

    explicit CustomSineCurve(float radius): radius_(radius) {}

    void getPoint(float t, threepp::Vector3& target) const override {
        float tx = std::cos(threepp::math::TWO_PI * t);
        float ty = std::sin(threepp::math::TWO_PI * t);
        float tz = 0;

        target.set(tx, ty, tz).multiplyScalar(radius_);
    }

private:
    float radius_;
};

#endif//FACTORY_PATTERN_CUSTOMSINECURVE_HPP
