/*
-- UiEngine of App --

- Manages ImGUI initialization and logic.
- Provides all of the expected user controls,
  like changing colors and positions.

*/

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <engines/window/windowEngine.hpp>
#include <engines/render/renderEngine.hpp>
#include <engines/scene/sceneEngine.hpp>


struct UiCrate {
    const WindowEngine* windowEngine;
};

class UiEngine {
public:
    UiEngine();
    ~UiEngine();

    void init(const UiCrate& crate);
    void update(RenderEngine& renderEngine, const SceneEngine& sceneEngine);

private:
    void dockingLayout();
    void uiLayout(RenderEngine& renderEngine, const SceneEngine& sceneEngine);
};
