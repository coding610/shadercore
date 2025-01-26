#include <GL/glew.h>
#include <GL/gl.h>

#include <engines/render/renderEngine.hpp>
#include <engines/scene/sceneEngine.hpp>
#include <engines/render/bufferModule.hpp>
#include <engines/render/shaderModule.hpp>

RenderEngine::RenderEngine() { }
RenderEngine::~RenderEngine() { }

void RenderEngine::init(const RenderCrate& crate) {
    shaderModule.loadShader("debug", "shaders/debug/debug.vert.glsl", "shaders/debug/debug.frag.glsl");
}

void RenderEngine::update(const SceneEngine& sceneEngine) {
    shaderModule.useShader("debug");
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
