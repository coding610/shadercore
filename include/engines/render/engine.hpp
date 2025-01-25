/*
-- RenderEngine of App --

- Core rendering logic; shader program and rendering pipeline.
- Responsible for initizialsing shaders and frame buffers.
- Includes two modules, ShaderModule and BufferModule.

*/


#pragma once

#include <engines/scene/engine.hpp>
#include <engines/render/buffer.hpp>
#include <engines/render/shader.hpp>


struct RenderCrate { };

class RenderEngine {
public:
    RenderEngine(const RenderCrate& crate);
    ~RenderEngine();

    void update(const SceneEngine& sceneEngine);

private:
    ShaderModule& shaderModule;
    BufferModule& bufferModule;

};
