/*window
-- WindowEngine of App --

- Encapsulates GLFW for window creation and input handling.
- Stores window dimensions, input callbacks and OpenGL contex details.

*/

#pragma once

#include <GLFW/glfw3.h>
#include <vmmlib/vector.hpp>


struct WindowCrate {
    const vmml::vec2f& dimensions;
    const char* title;
};

class WindowEngine {
public:
    ////// BUILDERS //////
    WindowEngine(const WindowCrate& crate);
    ~WindowEngine();

    /////// MAIN //////
    void init();
    void update();

    ////// GETTERS //////
    GLFWwindow*     getWindow();
    vmml::vec2f&    getDimensions();
    const char*     getTitle();

private:
    ////// GLFW //////
    GLFWwindow* window;
    vmml::vec2f dimensions;
    const char* title;
};
