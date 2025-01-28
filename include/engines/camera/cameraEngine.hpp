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
    float fov;
    float focalLength;
};

struct CameraUBOCrate {
    alignas(16) vmml::vec3f position;
    alignas(16) vmml::vec3f direction;
    alignas(16) float fov;
    alignas(16) float focalLength;
};

class CameraEngine {
public:
    CameraEngine();
    ~CameraEngine();

    void init(const CameraCrate& crate);
    void update();

    const CameraUBOCrate buildUBOCrate() const;
    const CameraCrate buildCrate()       const;
    void setCrate(const CameraCrate& crate);

private:
    vmml::vec3f position;
    vmml::vec3f direction;
    float fov;
    float focalLength;
};
