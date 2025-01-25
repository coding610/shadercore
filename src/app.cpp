#include <app.hpp>
#include <GLFW/glfw3.h>
#include <engines/window/windowEngine.hpp>
#include <engines/scene/sceneEngine.hpp>

//////////////////////
////// Builders //////
//////////////////////
App::App() : windowEngine(WindowEngine()), sceneEngine(SceneEngine()) {
    WindowCrate windowCrate;
    windowCrate.width = 500;
    windowCrate.height = 500;
    windowCrate.title = "pathtracing";
    windowEngine.init(windowCrate);

    SceneCrate sceneCrate;
    sceneEngine.init(sceneCrate);
}

App::~App() { }


//////////////////
////// Main //////
//////////////////
void App::run() {
    while (!glfwWindowShouldClose(windowEngine.getWindow())) {
        windowEngine.update();
    }
}
