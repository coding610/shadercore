#include "engines/scene/camera.hpp"
#include <engines/scene/engine.hpp>


SceneEngine::SceneEngine() : cameraModule({}), objects({}) {}
SceneEngine::~SceneEngine() {}

void SceneEngine::addObject(const std::shared_ptr<Object3D>& object) {
    objects.push_back(object);
}

void SceneEngine::addObject(const std::vector<std::shared_ptr<Object3D>>& _objects) {
    objects.insert(objects.end(), _objects.begin(), _objects.end());
}


