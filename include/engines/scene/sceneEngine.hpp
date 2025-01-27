/*
-- SceneEngine of App --

- Stores and manages objects.
- Provides data structures to populate SSBOs and UBOs.

TODO:
- Handle input
- CameraModule

*/

#pragma once

#include <vector>
#include <memory>

#include <engines/scene/cameraModule.hpp>
#include <assets/object3D.hpp>

struct SceneCrate { };

class SceneEngine {
public:
    SceneEngine();
    ~SceneEngine();

    void init(const SceneCrate& crate);
    void update();  // Used for update objects that needs refreshing, like the camera

    ////// Setters //////
    void addObject(const std::shared_ptr<Object3D>& object);
    void addObject(const std::vector<std::shared_ptr<Object3D>>& objects);
    
    ////// Getters //////
    const std::vector<std::shared_ptr<Object3D>>& getObjects() const;

private:
    // CameraModule cameraModule;
    std::vector<std::shared_ptr<Object3D>> objects;
};
