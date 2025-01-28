#include <GLFW/glfw3.h>

#include <engines/scene/sceneEngine.hpp>
#include <engines/scene/cameraModule.hpp>
#include <models/object3D.hpp>
#include <vmmlib/vector.hpp>


//////////////////////
////// Builders //////
//////////////////////
SceneEngine::SceneEngine() : objects({}), cameraModule({}) {
    CameraCrate cameraCrate;
    cameraCrate.position = {0, 0, 0};
    cameraCrate.direction = {0, 0, -1};
    cameraCrate.fov = 90;
    cameraCrate.focalLength = 1;
    cameraModule.init(cameraCrate);
}

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
const CameraUBOCrate SceneEngine::getCameraCrate() const { return cameraModule.buildUBOCrate(); }


//////////////////
////// Main //////
//////////////////
void SceneEngine::init(const SceneCrate& crate) { }
void SceneEngine::update() {
    glfwPollEvents();
}
