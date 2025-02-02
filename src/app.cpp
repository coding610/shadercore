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
    SceneCrate sceneCrate;
    sceneEngine.init(sceneCrate);

    CameraCrate cameraCrate;
    cameraCrate.position    = {0, 0, 0};
    cameraCrate.direction   = {0, 0, -1};
    cameraCrate.fov         = 90;
    cameraCrate.focalLength = 2;
    cameraEngine.init(cameraCrate);

    WindowCrate windowCrate;
    windowCrate.dimensions = {1920, 1080};
    windowCrate.title = "pathtracer";
    windowEngine.init(windowCrate);

    RenderCrate renderCrate;
    renderCrate.shaderStatuses = {{"debug", 0}, {"wave", 1}, {"pathtracer", 0}};
    renderEngine.init(renderCrate, sceneEngine);

    UiCrate uiCrate;
    uiEngine.init(uiCrate, windowEngine);

}; App::~App() { }


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
