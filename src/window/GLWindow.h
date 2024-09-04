#pragma once
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include "IWindow.h"
#include "../render/GLContext.h"
#include "../render/UIContext.h"
#include "../ui/SceneView.h"
#include "../ui/InspectorPanel.h"
#include "../ui/HostView.h"
#include "../shader/Shader.h"
#include "../render/GLBufferManager.h"

class GLWindow : public IWindow
{

public:
    GLWindow();
    ~GLWindow();
    void init(int width, int height, const char *title) override;
    void render() override;
    bool shouldClosed() override;

    void setNativeWindow(void *window) override { mWindow = (GLFWwindow *)window; }
    void *getNativeWindow() override { return mWindow; }
    void setNativeMonitor(void *monitor) override { mMonitor = (GLFWmonitor *)monitor; }
    void *getNativeMonitor() override { return mMonitor; }
    void handleMsg() override;
    void onKeyCallback(int key, int scancode, int action, int mods) override;
    void onScrollCallback(double delta) override;
    void onMouseButtonCallback(int button, int action, int mods) override;
    void onWindowResizeCallback(int width, int height) override;

    void drawInitTest();
    void drawTest();
    void drawToImGUITest();
    void drawDestroyTest();
    void drawCreateFramebuffer(int window_width, int window_height);
    void drawRescaleFramebuffer(float width, float height);
private:
    GLFWwindow *mWindow;
    GLFWmonitor *mMonitor;
    std::unique_ptr<GLContext> pCtx;
    std::unique_ptr<UIContext> pUICtx;
    std::unique_ptr<SceneView> pSceneView;
    std::unique_ptr<InspectorPanel> pInspectorPanel;
    std::unique_ptr<HostView> pHostView;

    std::unique_ptr<GLVertexBufferHoder> pBufferMgr;

private:
    std::unique_ptr<Shader> pShader;
    GLuint VBO, VAO, FBO, RBO, texture_id;
};