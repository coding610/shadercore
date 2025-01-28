#include <engines/scene/cameraModule.hpp>


CameraModule::CameraModule()  { }
CameraModule::~CameraModule() { }

void CameraModule::init(const CameraCrate& crate) {
    position = crate.position;
    direction = crate.direction;
    fov = crate.fov;
    focalLength = crate.focalLength;
}

void CameraModule::update() { }

// TODO: not copy?
const CameraUBOCrate CameraModule::buildUBOCrate() const { return { position, direction, fov, focalLength }; }
