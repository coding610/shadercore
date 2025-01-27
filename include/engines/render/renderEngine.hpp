/*
-- RenderEngine of App --

- Core rendering logic; shader program and rendering pipeline.
- Responsible for initizialsing shaders and frame buffers.
- Includes two modules, ShaderModule and BufferModule.

*/


#pragma once

#include <engines/render/bufferModule.hpp>
#include <engines/render/shaderModule.hpp>
#include <engines/scene/sceneEngine.hpp>
#include <unordered_map>

struct RenderCrate { };

class RenderEngine {
public:
    RenderEngine();
    ~RenderEngine();

    void init(const RenderCrate& crate);
    void update(const SceneEngine& sceneEngine);

    std::unordered_map<const char*, bool> getShaderStatuses() const;
    void setShaderStatuses(std::unordered_map<const char*, bool> shaders);
    

private:
    ShaderModule shaderModule;
    BufferModule bufferModule;

    std::unordered_map<const char*, bool> shaderStatuses;
    const char* shaderInUse;

    GLuint VAO, VBO, EBO;
};
