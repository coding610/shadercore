#include <GL/glew.h>
#include <GL/gl.h>

#include <GLFW/glfw3.h>
#include <engines/render/renderEngine.hpp>
#include <engines/scene/sceneEngine.hpp>
#include <engines/render/bufferModule.hpp>
#include <engines/render/shaderModule.hpp>

RenderEngine::RenderEngine() { }
RenderEngine::~RenderEngine() { }

void RenderEngine::init(const RenderCrate& crate) {
    ////// Setup fullscreen quad to draw on //////

    /*
    Raytracing on the frag is essentialy coloring a rectangle.
    It could be a triangle as well.
    */

    float vertices[] = { -1.0f, -1.0f, 1.0f, -1.0f, 1.0f,  1.0f, -1.0f,  1.0f };
    GLuint indices[] = { 0, 1, 2, 2, 3, 0 };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    ////// Load shader //////
    shaderModule.loadShader("debug", "shaders/debug/debug.vert.glsl", "shaders/debug/debug.frag.glsl");
    shaderModule.loadShader("wave", "shaders/wave/wave.vert.glsl", "shaders/wave/wave.frag.glsl");
}

void RenderEngine::update(const SceneEngine& sceneEngine) {
    glClear(GL_COLOR_BUFFER_BIT);

    ////// Shader select //////
    // shaderModule.useShader("debug");
    shaderModule.useShader("wave");
    shaderModule.setUniform("wave", "time", glfwGetTime());

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
