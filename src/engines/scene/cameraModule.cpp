#include <engines/camera/cameraEngine.hpp>


//////////////////////
////// Builders //////
//////////////////////
CameraEngine::CameraEngine()  { }
CameraEngine::~CameraEngine() { }


/////////////////////
////// Getters //////
/////////////////////
const CameraUBOCrate CameraEngine::buildUBOCrate() const {
    return { position, direction, fov, focalLength };
}

const CameraCrate CameraEngine::buildCrate() const {
    return { position, direction, fov, focalLength };
}


/////////////////////
////// Setters //////
/////////////////////
void CameraEngine::setCrate(const CameraCrate& crate) {
    position = crate.position;
    direction = crate.direction;
    fov = crate.fov;
    focalLength = crate.focalLength;
}


//////////////////
////// Main //////
//////////////////
void CameraEngine::init(const CameraCrate& crate) {
    position = crate.position;
    direction = crate.direction;
    fov = crate.fov;
    focalLength = crate.focalLength;
}

void CameraEngine::update() { }
