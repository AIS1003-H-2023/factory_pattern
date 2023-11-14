
#ifndef THREEPP_VCPKG_DEMO_BOXFACTORY_HPP
#define THREEPP_VCPKG_DEMO_BOXFACTORY_HPP

#include "MeshFactory.hpp"

#include "threepp/geometries/BoxGeometry.hpp"
#include "threepp/materials/Material.hpp"

class BoxFactory: public MeshFactory {

public:
     BoxFactory(float size, const std::shared_ptr<threepp::Material>& material)
        : material_(material), geometry_(threepp::BoxGeometry::create(size, size, size)) {}

    std::shared_ptr<threepp::Mesh> create() override {
        auto mesh = threepp::Mesh::create(geometry_, material_);
        return mesh;
    }

private:
    // chose to reuse geometry and material
    std::shared_ptr<threepp::BufferGeometry> geometry_;
    std::shared_ptr<threepp::Material> material_;
};

#endif//THREEPP_VCPKG_DEMO_BOXFACTORY_HPP
