/*
-- WindowEngine of App --

- Encapsulates GLFW for window creation and input handling.
- Stores window dimensions, input callbacks and OpenGL contex details.

*/

#pragma once


struct WindowCrate { };

class WindowEngine {
public:
    WindowEngine(const WindowCrate& crate);
    ~WindowEngine();

    void update();

private:
};
