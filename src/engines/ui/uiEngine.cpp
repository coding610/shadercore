#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <vmmlib/vector.hpp>
#include <unordered_map>
#include <cwctype>

#include <engines/render/renderEngine.hpp>
#include <engines/scene/sceneEngine.hpp>
#include <engines/ui/uiEngine.hpp>
#include <debug.hpp>


//////////////////////
////// BUILDERS //////
//////////////////////
UiEngine::UiEngine()  { }
UiEngine::~UiEngine() { }

//////////////////
////// MAIN //////
//////////////////
void UiEngine::init(const UiCrate& crate) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void) io;

    ImGui_ImplGlfw_InitForOpenGL(crate.windowEngine->getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 430 core");

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();

}

void UiEngine::update(RenderEngine& renderEngine, const SceneEngine& sceneEngine) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGuiID dockspaceID = ImGui::DockSpaceOverViewport(ImGui::GetID(ImGui::GetMainViewport()), ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
    uiLayout(renderEngine, sceneEngine);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UiEngine::uiLayout(RenderEngine& renderEngine, const SceneEngine& sceneEngine) {
    ImGui::Begin("Shader");

    if (ImGui::CollapsingHeader("Shader Program")) { ImGui::Indent();
        std::unordered_map<const char*, bool> shaders = renderEngine.getShaderStatuses();

        for (auto& [key, value] : shaders) {
            if (ImGui::RadioButton(key, value)) {
                for (auto& [k, v] : shaders) v = false;
                shaders[key] = true;
            }
        }

        renderEngine.setShaderStatuses(shaders);
    }

    ImGui::End();

    ImGui::Begin("World");
    ImGui::End();
}
