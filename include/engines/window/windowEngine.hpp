/*
-- WindowEngine of App --

- Encapsulates GLFW for window creation and input handling.
- Stores window dimensions, input callbacks and OpenGL contex details.
*/

#pragma once

#include <GLFW/glfw3.h>
#include <vmmlib/vector.hpp>


struct WindowCrate {
    vmml::vec2f dimensions;
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
    GLFWwindow* getWindow() const;
    const vmml::vec2f& getDimensions() const;
    const char* getTitle() const;

private:
    ////// Glfw //////
    GLFWwindow* window;
    vmml::vec2f dimensions;
    const char* title;
};
