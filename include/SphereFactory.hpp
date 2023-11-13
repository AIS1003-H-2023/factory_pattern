
#ifndef THREEPP_VCPKG_DEMO_SPHEREFACTORY_HPP
#define THREEPP_VCPKG_DEMO_SPHEREFACTORY_HPP

#include "MeshFactory.hpp"

#include "threepp/geometries/SphereGeometry.hpp"
#include "threepp/materials/Material.hpp"

class SphereFactory: public MeshFactory {

public:
    explicit SphereFactory(float radius, const std::shared_ptr<threepp::Material>& material)
        : material_(material), geometry_(threepp::SphereGeometry::create(radius)) {}

    std::shared_ptr<threepp::Mesh> create() override {
        auto mesh = threepp::Mesh::create(geometry_, material_);
        return mesh;
    }

private:
    // chose to reuse geometry and material
    std::shared_ptr<threepp::BufferGeometry> geometry_;
    std::shared_ptr<threepp::Material> material_;
};

#endif//THREEPP_VCPKG_DEMO_SPHEREFACTORY_HPP
