#include "App.h"
#include "window/WindowMgr.h"

App::App()
{
    pWindow = WindowMgr::createWindow();
    pWindow->init(600, 400, "Simple Renderer");
}

App::~App()
{
}

int App::loop()
{

    while (true)
    {
        if (pWindow->shouldClosed())
        {
            return 1;
        }
        pWindow->render();
    }
    return 0;
}

void App::doFrame(float dt)
{
}

void App::handleInput(float dt)
{
}
