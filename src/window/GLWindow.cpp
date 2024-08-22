#include "GLWindow.h"
#include "../render/GLContext.h"

GLWindow::GLWindow()
{
    mWindow = nullptr;
    // pCtx = new GLContext();
    pCtx = std::make_unique<GLContext>();
}

GLWindow::~GLWindow()
{
    // delete pCtx;
    //
    pCtx->destroy();
    // glfwDestroyWindow(mWindow);
    // glfwTerminate();
}

void GLWindow::init(int width, int height, const char *title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    pCtx->init(this);

    // if (!glfwInit())
    // {
    //     std::cout << "glfw init failed" << std::endl;
    //     // return -1;
    // }

    // glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    // glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    // monitor = glfwGetPrimaryMonitor();
    // float xscale, yscale;
    // glfwGetMonitorContentScale(monitor, &xscale, &yscale);
    // std::cout << "[INFO INIT]: " << xscale << "x" << yscale << std::endl;
    // std::cout << "[INFO INIT]: " << width << "x" << height << std::endl;
    // window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    // if (!window)
    // {
    //     std::cout << "window init failed" << std::endl;
    //     // glfwTerminate();
    //     // return -1;
    // }

    // showWindowCenter();
    // glfwMakeContextCurrent(mWindow);
    // gladLoadGL(glfwGetProcAddress);
    // glfwSwapInterval(1);
}

void GLWindow::showWindowCenter()
{

    // if (!mMonitor)
    //     return;

    // const GLFWvidmode *mode = glfwGetVideoMode(mMonitor);
    // if (!mode)
    //     return;

    // int monitorX, monitorY;
    // glfwGetMonitorPos(monitor, &monitorX, &monitorY);

    // int windowWidth, windowHeight;
    // glfwGetWindowSize(mWindow, &windowWidth, &windowHeight);

    // std::cout << "monitorX: " << monitorX << " monitorY: " << monitorY << std::endl;
    // std::cout << "windowWidth: " << windowWidth << " windowHeight: " << windowHeight << std::endl;

    // glfwSetWindowPos(
    //     mWindow,
    //     monitorX + (mode->width - windowWidth) / 2,
    //     monitorY + (mode->height - windowHeight) / 2);

    // glfwShowWindow(mWindow);
}

bool GLWindow::shouldClosed()
{
    return glfwWindowShouldClose(mWindow);
}

void GLWindow::render()
{

    pCtx->pre_render();

    pCtx->post_render();

    // glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glfwPollEvents();
    // glfwSwapBuffers(window);
}