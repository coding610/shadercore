/*
-- SceneEngine of App --

- Stores and manages objects.
- Provides data structures to populate SSBOs and UBOs.
- A base class is also found, Object3D, with derived classes
  like Sphere, Plane, Mesh etc.

*/

#pragma once

#include <engines/scene/camera.hpp>


struct SceneCrate { };

class SceneEngine {
public:
    SceneEngine(const SceneCrate& crate);
    ~SceneEngine();

    void update();

private:
    CameraModule cameraModule;
};
