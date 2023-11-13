
#ifndef THREEPP_VCPKG_DEMO_MESHFACTORY_HPP
#define THREEPP_VCPKG_DEMO_MESHFACTORY_HPP

#include "threepp/objects/Mesh.hpp"

// Abstract factory class for Mesh
class MeshFactory {

public:
    virtual std::shared_ptr<threepp::Mesh> create() = 0;
};

#endif//THREEPP_VCPKG_DEMO_MESHFACTORY_HPP
