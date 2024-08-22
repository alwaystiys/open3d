#include "GLContext.h"
#include "../pch.h"
#include "../window/GLWindow.h"
#include <assert.h>

GLContext::GLContext()
{
}

GLContext::~GLContext()
{
}

bool GLContext::init(IWindow *window)
{
    RenderContext::init(window);

    if (!glfwInit())
    {
        // fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
        std::cout << "glfw init failed" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    GLFWwindow *nativeWindow = glfwCreateWindow(window->width, window->height, window->title, nullptr, nullptr);
    window->setNativeWindow(nativeWindow);

    auto monitor = glfwGetPrimaryMonitor();
    if (!monitor)
    {
        std::cout << "monitor is null" << std::endl;
        return false;
    }

    window->setNativeMonitor(monitor);
    float xscale, yscale;
    glfwGetMonitorContentScale(monitor, &xscale, &yscale);
    std::cout << "[INFO INIT]: " << xscale << "x" << yscale << std::endl;
    std::cout << "[INFO INIT]: " << window->width << "x" << window->height << std::endl;

    if (!nativeWindow)
    {
        std::cout << "GLFWwindow init failed" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(nativeWindow);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if (!mode)
    {
        std::cout << "mode is null" << std::endl;
        return false;
    }

    int monitorX, monitorY;
    glfwGetMonitorPos(monitor, &monitorX, &monitorY);

    int windowWidth, windowHeight;
    glfwGetWindowSize(nativeWindow, &windowWidth, &windowHeight);

    std::cout << "[INFO MONITOR]: " << monitorX << " " << monitorY << std::endl;
    std::cout << "[INFO SCALE_SIZE]: " << windowWidth << "x" << windowHeight << std::endl;

    glfwSetWindowPos(
        nativeWindow,
        monitorX + (mode->width - windowWidth) / 2,
        monitorY + (mode->height - windowHeight) / 2);

    glfwShowWindow(nativeWindow);
    return true;
}

void GLContext::pre_render()
{
    glViewport(0, 0, mWindow->width, mWindow->height);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLContext::post_render()
{
    glfwPollEvents();
    glfwSwapBuffers((GLFWwindow *)mWindow->getNativeWindow());
}

void GLContext::destroy()
{
    glfwDestroyWindow((GLFWwindow *)mWindow->getNativeWindow());
    glfwTerminate();
}