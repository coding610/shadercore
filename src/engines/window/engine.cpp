#include <stdexcept>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <vmmlib/vector.hpp>

#include <engines/window/engine.hpp>


//////////////////////
////// BUILDERS //////
//////////////////////
WindowEngine::WindowEngine(const WindowCrate& crate) {
    dimensions = crate.dimensions;
    title      = crate.title;
}

WindowEngine::~WindowEngine() {
    glfwDestroyWindow(window);
    glfwTerminate();
};

/////////////////////
////// GETTERS //////
/////////////////////
GLFWwindow*     WindowEngine::getWindow()     { return window; }
vmml::vec2f&    WindowEngine::getDimensions() { return dimensions;  }
const char*     WindowEngine::getTitle()      { return title; }

//////////////////
////// MAIN //////
//////////////////
void WindowEngine::init() {
    ////// GLFW //////
    if (!glfwInit()) { throw std::runtime_error("Fatal Error: App::WindowEngine::init()::glfwInit()"); }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(dimensions.x(), dimensions.y(), title, nullptr, nullptr);
    if (!window) { throw std::runtime_error("Fatal Error: App::WindowEngine::init()::glfwCreateWindow()"); }

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);

    ////// OPENGL //////
    glViewport(0, 0, dimensions.x(), dimensions.y());
    glEnable(GL_DEPTH_TEST);
}

void WindowEngine::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}
