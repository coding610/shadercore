/*
-- SceneEngine of App --

- Stores and manages objects.
- Provides data structures to populate SSBOs and UBOs.

*/

#pragma once

#include <engines/scene/camera.hpp>
#include <assets/object3D.hpp>
#include <memory>
#include <vector>


class SceneEngine {
public:
    SceneEngine();
    ~SceneEngine();

    void update();      // Update objects that needs refreshing, like the camera

    ////// GETTERS AND SETTERS //////
    void addObject(const std::shared_ptr<Object3D>& object);
    void addObject(const std::vector<std::shared_ptr<Object3D>>& objects);
    const std::vector<std::shared_ptr<Object3D>>& getObjects() const;

private:
    CameraModule cameraModule;
    std::vector<std::shared_ptr<Object3D>> objects;
};
