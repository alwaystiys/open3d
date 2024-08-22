#include "GLContext.h"
#include "../pch.h"

GLContext::GLContext()
{
}

GLContext::~GLContext()
{
}

bool GLContext::init(IWindow* window)
{
    if (!glfwInit())
    {
        std::cout << "glfw init failed" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    return true;
}

void GLContext::pre_render()
{
}

void GLContext::post_render()
{
}

void GLContext::destroy()
{
}