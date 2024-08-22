#pragma once
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include "IWindow.h"
#include "../render/GLContext.h"

class GLWindow : public IWindow
{

public:
    GLWindow();
    ~GLWindow();
    void init(int width, int height, const char *title);
    void render();
    bool shouldClosed();

private:
    void showWindowCenter();

private:
    GLFWwindow *window;
    GLFWmonitor *monitor;
    GLContext *pCtx;
};