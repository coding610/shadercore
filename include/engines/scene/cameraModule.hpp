/*
-- CameraModule of SceneEngine --

- Handles camera movement and projection matrixes.
- Is treated like a special object by SceneEngine.

*/

#pragma once

#include <vmmlib/vector.hpp>


struct CameraCrate {
    vmml::vec3f position;
    vmml::vec3f direction;
    vmml::vec2f fov;
    float focalLength;
};

struct CameraUBOCrate {
    alignas(16) vmml::vec3f position;
    alignas(16) vmml::vec3f direction;
    alignas(16) vmml::vec2f fov;
    alignas(16) float focalLength;
};

class CameraModule {
public:
    CameraModule();
    ~CameraModule();

    void init(const CameraCrate& crate);
    void update();
    const CameraUBOCrate buildUBOCrate() const;

private:
    vmml::vec3f position;
    vmml::vec3f direction;
    vmml::vec2f fov;
    float focalLength;
};
