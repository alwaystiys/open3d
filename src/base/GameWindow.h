#pragma once
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

class GameWindow{

public:
    GameWindow(int width, int height, const std::string &title);
    ~GameWindow();

private:
    GLFWwindow* window;
    int width;
    int height;
    const std::string &title;
};