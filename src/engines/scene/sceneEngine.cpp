#include <GLFW/glfw3.h>

#include <engines/scene/sceneEngine.hpp>
#include <models/object3D.hpp>
#include <vmmlib/vector.hpp>


//////////////////////
////// Builders //////
//////////////////////
SceneEngine::SceneEngine() : objects({}) { }
SceneEngine::~SceneEngine() {}


/////////////////////
////// Setters //////
/////////////////////
void SceneEngine::addObject(const std::shared_ptr<Object3D>& object) {
    objects.push_back(object);
}

void SceneEngine::addObject(const std::vector<std::shared_ptr<Object3D>>& _objects) {
    objects.insert(objects.end(), _objects.begin(), _objects.end());
}


/////////////////////
////// Getters //////
/////////////////////
const std::vector<std::shared_ptr<Object3D>>& SceneEngine::getObjects() const { return objects; }


//////////////////
////// Main //////
//////////////////
void SceneEngine::init(const SceneCrate& crate) { }
void SceneEngine::update() {
    glfwPollEvents();
}
