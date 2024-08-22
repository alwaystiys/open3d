#pragma once
#include "RenderBase.h"
#include <imgui.h>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

/**
 * @brief Context for UI rendering.
 * test imgui
 */
class UIContext : public RenderContext
{
public:
    UIContext();
    ~UIContext();

    bool init(IWindow *);
    void pre_render();
    void post_render();
    void destroy();


private:

    void showMainMenuBar();
    void createHostWindow();

};