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

private:
    GLFWwindow *mWindow;
    GLFWmonitor *mMonitor;
    std::unique_ptr<GLContext> pCtx;
    std::unique_ptr<UIContext> pUICtx;
};