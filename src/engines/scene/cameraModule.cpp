#include <engines/scene/cameraModule.hpp>

void CameraModule::init(const CameraCrate& crate) {
    position = crate.position;
    direction = crate.direction;
    fov = crate.fov;
    focalPoint = crate.focalPoint;
}

void CameraModule::update() { /* TODO: Movement */ }
