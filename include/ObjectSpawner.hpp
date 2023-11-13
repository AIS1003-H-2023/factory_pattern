
#ifndef THREEPP_VCPKG_DEMO_OBJECTSPAWNER_HPP
#define THREEPP_VCPKG_DEMO_OBJECTSPAWNER_HPP

#include "threepp/core/Object3D.hpp"

#include "MeshFactory.hpp"

class ObjectSpawner: public threepp::Object3D {

public:
    explicit ObjectSpawner(MeshFactory& factory);

    threepp::Mesh& spawn(float t);

    void setFactory(MeshFactory& factory);

    void setLifetime(float lifetime);

    void update(float t);

private:
    float lifetime_ = std::numeric_limits<float>::infinity();
    std::unordered_map<threepp::Mesh*, float> spawnedObjects_;
    MeshFactory* factory_;
};

#endif//THREEPP_VCPKG_DEMO_OBJECTSPAWNER_HPP
