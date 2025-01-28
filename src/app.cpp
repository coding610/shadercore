// FIX THESE
#include <GL/glew.h>

#include <engines/window/windowEngine.hpp>
#include <engines/scene/sceneEngine.hpp>
#include <engines/render/renderEngine.hpp>
#include <engines/camera/cameraEngine.hpp>
#include <engines/ui/uiEngine.hpp>
#include <app.hpp>

//////////////////////
////// Builders //////
//////////////////////
App::App() {
    WindowCrate windowCrate;
    windowCrate.width = 1920;
    windowCrate.height = 1080;
    windowCrate.title = "shadercore";
    windowEngine.init(windowCrate);

    SceneCrate sceneCrate;
    sceneEngine.init(sceneCrate);

    RenderCrate renderCrate;
    renderEngine.init(renderCrate);

    UiCrate uiCrate;
    uiCrate.windowEngine = &windowEngine;
    uiEngine.init(uiCrate);

    CameraCrate cameraCrate;
    cameraCrate.position    = {0, 0, 0};
    cameraCrate.direction   = {0, 0, -1};
    cameraCrate.fov         = 90;
    cameraCrate.focalLength = 2;
    cameraEngine.init(cameraCrate);
}

App::~App() { }


//////////////////
////// Main //////
//////////////////
void App::run() {
    while (!glfwWindowShouldClose(windowEngine.getWindow())) {
        sceneEngine.update();
        cameraEngine.update();
        renderEngine.update(sceneEngine, cameraEngine);
        uiEngine.update(renderEngine, sceneEngine, cameraEngine);
        windowEngine.update();
    }
}
