/*
-- WindowEngine of App --

- Encapsulates GLFW for window creation and input handling.
- Stores window dimensions, input callbacks and OpenGL contex details.

*/

#pragma once

#include <GLFW/glfw3.h>
#include <vmmlib/vector.hpp>


struct WindowCrate {
    float width;
    float height;
    const char* title;
};

class WindowEngine {
public:
    ////// Default Builders //////
    WindowEngine();
    ~WindowEngine();

    /////// Main ///////
    void init(const WindowCrate& crate);
    void update();

    ////// Getters //////
    GLFWwindow*     getWindow();
    vmml::vec2f&    getDimensions();
    const char*     getTitle();

private:
    ////// Glfw //////
    GLFWwindow* window;
    vmml::vec2f dimensions;
    const char* title;
};
