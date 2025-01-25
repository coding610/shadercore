/*
-- Application --

- Main application.
- Manages engines and orchestrates the main loop.

*/

#pragma once

#include <engines/window/engine.hpp>
#include <engines/render/engine.hpp>
#include <engines/scene/engine.hpp>
#include <engines/ui/engine.hpp>


class App {
public:
    App();
    ~App();

    void run();

private:
    WindowEngine    windowEngine;
    // RenderEngine    renderEngine;
    // SceneEngine     sceneEngine;
    // UiEngine        uiEngine;
};
