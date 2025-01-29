/*
-- RenderEngine of App --

- Core rendering logic; shader program and rendering pipeline.
- Responsible for initizialsing shaders and buffers (its sub modules).
- Includes two modules, ShaderModule and BufferModule.

*/

#pragma once

#include <unordered_map>

#include <engines/scene/sceneEngine.hpp>
#include <engines/camera/cameraEngine.hpp>
#include <engines/render/bufferModule.hpp>
#include <engines/render/shaderModule.hpp>


struct RenderCrate {
    std::unordered_map<const char*, bool> shaderStatuses;
};

class RenderEngine {
public:
    RenderEngine();
    ~RenderEngine();

    void init(const RenderCrate& crate, const SceneEngine& sceneEngine);
    void update(const SceneEngine& sceneEngine, const CameraEngine& cameraEngine);

    void buildCrate(RenderCrate& crate) const;
    void applyCrate(const RenderCrate& crate);

private:
    ShaderModule shaderModule;
    BufferModule bufferModule;

    std::unordered_map<const char*, bool> shaderStatuses;
    const char* shaderInUse;

    GLuint VAO, VBO, EBO;
};
