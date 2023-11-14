
#include "ObjectSpawner.hpp"

ObjectSpawner::ObjectSpawner(MeshFactory& factory)
    : factory_(&factory) {}


threepp::Mesh& ObjectSpawner::spawn(float t) {
    auto mesh = factory_->create();
    add(mesh);
    spawnedObjects_.emplace(mesh.get(), t + lifetime_);
    return *mesh;
}

void ObjectSpawner::setFactory(MeshFactory& factory) {
    factory_ = &factory;
}

void ObjectSpawner::setLifetime(float lifetime) {
    lifetime_ = lifetime;
}

float ObjectSpawner::getLifeTime() const {
    return lifetime_;
}

void ObjectSpawner::update(float t) {

    for (auto it = spawnedObjects_.begin(); it != spawnedObjects_.end();) {

        auto& [mesh, terminationTime] = *it;
        if (terminationTime < t) {
            remove(*mesh);
            it = spawnedObjects_.erase(it);
        } else {
            ++it;
        }
    }
}
