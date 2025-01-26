// FIX THESE
#include <GL/glew.h>

#include <engines/window/windowEngine.hpp>
#include <engines/scene/sceneEngine.hpp>
#include <engines/render/renderEngine.hpp>
#include <app.hpp>

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

    RenderCrate renderCrate;
    renderEngine.init(renderCrate);
}

App::~App() { }


//////////////////
////// Main //////
//////////////////
void App::run() {
    while (!glfwWindowShouldClose(windowEngine.getWindow())) {
        sceneEngine.update();
        renderEngine.update(sceneEngine);
        windowEngine.update();
    }
}
