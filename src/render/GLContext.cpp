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

static void onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    auto glWindow = static_cast<IWindow *>(glfwGetWindowUserPointer(window));
    glWindow->onKeyCallback(key, scancode, action, mods);
}

static void onScrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
    auto glWindow = static_cast<IWindow *>(glfwGetWindowUserPointer(window));
    glWindow->onScrollCallback(yoffset);
}

static void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    auto glWindow = static_cast<IWindow *>(glfwGetWindowUserPointer(window));
    glWindow->onMouseButtonCallback(button, action, mods);
}

static void onWindowResizeCallback(GLFWwindow *window, int width, int height)
{
    auto glWindow = static_cast<IWindow *>(glfwGetWindowUserPointer(window));
    glWindow->onWindowResizeCallback(width, height);
    glViewport(0, 0, width, height);
}

static void onFramebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    auto glWindow = static_cast<IWindow *>(glfwGetWindowUserPointer(window));
    std::cout << "gl onFramebufferResizeCallback " << width << " " << height << std::endl;

}


static void onWindowContentScaleCallback(GLFWwindow *window, float xscale, float yscale){
    auto glWindow = static_cast<IWindow *>(glfwGetWindowUserPointer(window));
    // glWindow->onWindowContentScaleCallback(xscale, yscale);
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
    glfwWindowHint(GLFW_SCALE_FRAMEBUFFER, GLFW_TRUE);

    GLFWwindow *nativeWindow = glfwCreateWindow(window->width, window->height, window->title, nullptr, nullptr);
    window->setNativeWindow(nativeWindow);

    // associate the window with the context
    glfwSetWindowUserPointer(nativeWindow, window);

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

    float cxscale, cyscale;
    glfwGetWindowContentScale(nativeWindow, &cxscale, &cyscale);
    std::cout << "[INFO CONTENT SCALE]: " << cxscale << "x" << cyscale << std::endl;


    if (!nativeWindow)
    {
        std::cout << "GLFWwindow init failed" << std::endl;
        glfwTerminate();
        return false;
    }

    // callback
    glfwSetKeyCallback(nativeWindow, onKeyCallback);
    glfwSetScrollCallback(nativeWindow, onScrollCallback);
    glfwSetMouseButtonCallback(nativeWindow, onMouseButtonCallback);
    glfwSetWindowSizeCallback(nativeWindow, onWindowResizeCallback);
    glfwSetFramebufferSizeCallback(nativeWindow, onFramebufferResizeCallback);
    glfwSetWindowContentScaleCallback(nativeWindow, onWindowContentScaleCallback);

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

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(nativeWindow, &fbWidth, &fbHeight);

    std::cout << "[INFO FB_SIZE]: " << fbWidth << "x" << fbHeight << std::endl;

    glfwSetWindowPos(
        nativeWindow,
        monitorX + (mode->width - windowWidth) / 2,
        monitorY + (mode->height - windowHeight) / 2);

    glfwShowWindow(nativeWindow);
    return true;
}

void GLContext::pre_render()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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