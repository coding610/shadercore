#include <app.hpp>
#include <GLFW/glfw3.h>
#include <engines/window/engine.hpp>

//////////////////////
////// BUILDERS //////
//////////////////////
App::App() : windowEngine(WindowEngine({.dimensions = {500, 500}, .title = "pathtracer"}))  {
    windowEngine.init();
}

App::~App() {
}


//////////////////
////// MAIN //////
//////////////////
void App::run() {
    while (!glfwWindowShouldClose(windowEngine.getWindow())) {
        windowEngine.update();
    }
}
