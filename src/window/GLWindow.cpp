#include "GLWindow.h"

GLWindow::GLWindow()
{
    mWindow = nullptr;
    pCtx = std::make_unique<GLContext>();
    pUICtx = std::make_unique<UIContext>();
    pSceneView = std::make_unique<SceneView>();
    pInspectorPanel = std::make_unique<InspectorPanel>();
}

GLWindow::~GLWindow()
{
    pCtx->destroy();
    pUICtx->destroy();
}

void GLWindow::init(int width, int height, const char *title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    pCtx->init(this);
    pUICtx->init(this);
}

bool GLWindow::shouldClosed()
{
    return glfwWindowShouldClose(mWindow);
}

void GLWindow::render()
{
    pCtx->pre_render();
    pUICtx->pre_render();

    pInspectorPanel->render();
    pSceneView->render();

    pUICtx->post_render();
    pCtx->post_render();
}

void GLWindow::handleMsg()
{
}

void GLWindow::onKeyCallback(int key, int scancode, int action, int mods)
{
    std::cout << "gl onKeyCallback " << key << " " << scancode << " " << action << " " << mods << std::endl;
}

void GLWindow::onScrollCallback(double delta)
{
    std::cout << "gl onScrollCallback " << delta << std::endl;
}

void GLWindow::onMouseButtonCallback(int button, int action, int mods)
{
    std::cout << "gl onMouseButtonCallback " << button << " " << action << " " << mods << std::endl;
}

void GLWindow::onWindowResizeCallback(int width, int height)
{
    std::cout << "gl onWindowResizeCallback " << width << " " << height << std::endl;
}