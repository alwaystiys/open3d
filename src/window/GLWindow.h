#pragma once
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include "IWindow.h"
#include <memory>

class GLWindow : public IWindow{

public:
    GLWindow(int width, int height, const std::string &title);
    ~GLWindow();
    void render();
private:
    void showWindowCenter();

private:
    GLFWwindow* window;
    GLFWmonitor* monitor;
    int width;
    int height;
    const std::string &title;
};