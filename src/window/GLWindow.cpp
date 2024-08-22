#include "GLWindow.h"
#include "../render/GLContext.h"

GLWindow::GLWindow()
{
    pCtx = new GLContext();
}

GLWindow::~GLWindow()
{
    delete pCtx; 
    //   
    glfwDestroyWindow(window);
    glfwTerminate();
}

void GLWindow::init(int width, int height, const char *title)
{
    width = width;
    height = height;
    title = title;

    pCtx->init(this);
    

    if (!glfwInit())
    {
        std::cout << "glfw init failed" << std::endl;
        // return -1;
    }

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    monitor = glfwGetPrimaryMonitor();
    float xscale, yscale;
    glfwGetMonitorContentScale(monitor, &xscale, &yscale);
    std::cout << "[INFO INIT]: " << xscale << "x" << yscale << std::endl;
    std::cout << "[INFO INIT]: " << width << "x" << height << std::endl;
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (!window)
    {
        std::cout << "window init failed" << std::endl;
        // glfwTerminate();
        // return -1;
    }

    showWindowCenter();
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);
}

void GLWindow::showWindowCenter()
{
    if (!monitor)
        return;

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if (!mode)
        return;

    int monitorX, monitorY;
    glfwGetMonitorPos(monitor, &monitorX, &monitorY);

    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    std::cout << "monitorX: " << monitorX << " monitorY: " << monitorY << std::endl;
    std::cout << "windowWidth: " << windowWidth << " windowHeight: " << windowHeight << std::endl;

    glfwSetWindowPos(
        window,
        monitorX + (mode->width - windowWidth) / 2,
        monitorY + (mode->height - windowHeight) / 2);

    glfwShowWindow(window);
}

bool GLWindow::shouldClosed()
{
    return glfwWindowShouldClose(window);
}

void GLWindow::render()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}