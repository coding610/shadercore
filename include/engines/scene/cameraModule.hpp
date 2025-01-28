/*
-- CameraModule of SceneEngine --

- Handles camera movement and projection matrixes.
- Is treated like a special object by SceneEngine.

*/

#pragma once

#include <vmmlib/vector.hpp>


struct CameraCrate {
    const vmml::vec3f& position;
    const vmml::vec3f& direction;
    const vmml::vec2f& fov;
    const float& focalPoint;
};

class CameraModule {
public:
    CameraModule();
    ~CameraModule();

    void init(const CameraCrate& crate);
    void update();

private:
    vmml::vec3f position;
    vmml::vec3f direction;
    vmml::vec2f fov;
    float focalPoint;
};
