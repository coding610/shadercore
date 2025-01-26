/*
-- RenderEngine of App --

- Core rendering logic; shader program and rendering pipeline.
- Responsible for initizialsing shaders and frame buffers.
- Includes two modules, ShaderModule and BufferModule.

*/


#pragma once

#include <engines/scene/sceneEngine.hpp>
#include <engines/render/bufferModule.hpp>
#include <engines/render/shaderModule.hpp>


struct RenderCrate { };

class RenderEngine {
public:
    RenderEngine();
    ~RenderEngine();

    void init(const RenderCrate& crate);
    void update(const SceneEngine& sceneEngine);

private:
    ShaderModule shaderModule;
    BufferModule bufferModule;
};
