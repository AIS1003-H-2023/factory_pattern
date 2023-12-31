
#include "threepp/extras/imgui/ImguiContext.hpp"
#include "threepp/threepp.hpp"

#include "BoxFactory.hpp"
#include "CustomSineCurve.hpp"
#include "ObjectSpawner.hpp"
#include "SphereFactory.hpp"

using namespace threepp;

namespace {

    auto createPath(Curve3& curve) {

        const auto points = curve.getPoints(50);
        const auto geometry = BufferGeometry::create();
        geometry->setFromPoints(points);
        const auto material = LineBasicMaterial::create();
        material->color = 0xff0000;
        const auto curveObject = Line::create(geometry, material);
        return curveObject;
    }

}// namespace

int main() {

    Canvas canvas("Factory pattern demo", {{"aa", 4}});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::aliceblue);

    auto camera = PerspectiveCamera::create(60, canvas.aspect());
    camera->position.z = 15;

    OrbitControls controls{*camera, canvas};

    auto scene = Scene::create();

    CustomSineCurve curve(5);
    auto path = createPath(curve);
    scene->add(path);

    auto sphereMaterial = MeshBasicMaterial::create({{"color", Color::red}});
    auto boxMaterial = MeshBasicMaterial::create({{"color", Color::blue}});
    std::vector<std::unique_ptr<MeshFactory>> factories;
    factories.emplace_back(std::make_unique<SphereFactory>(0.5f, sphereMaterial));
    factories.emplace_back(std::make_unique<BoxFactory>(0.5f, boxMaterial));

    ObjectSpawner spawner(*factories.back());
    scene->add(spawner);

    float lifeTime = 0.5f;
    spawner.setLifetime(lifeTime);
    ImguiFunctionalContext ui(canvas.windowPtr(), [&] {
        ImGui::SetNextWindowPos({0, 0}, 0, {0, 0});
        ImGui::SetNextWindowSize({230, 0}, 0);

        ImGui::Begin("ObjectSpawner");
        if (ImGui::SliderFloat("lifetime", &lifeTime, 0.1f, 1.f)) {
            spawner.setLifetime(lifeTime);
        }

        controls.enabled = !ImGui::IsWindowHovered();
        ImGui::End();
    });

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });

    size_t it = 0;
    Clock clock;
    canvas.animate([&] {
        float time = clock.getElapsedTime();

        if (it++ % 5 == 0) {// spawn every 5th iteration
            auto& mesh = spawner.spawn(time);
            curve.getPoint(time, mesh.position);
        }
        if (it % 10 == 0) {// possibly change factory every 10th iteration
            auto index = math::randInt(0, static_cast<int>(factories.size()) - 1);
            spawner.setFactory(*factories.at(index));
        }
        spawner.update(time);// removes objects based on elapsed time

        renderer.render(*scene, *camera);
        ui.render();
    });
}
