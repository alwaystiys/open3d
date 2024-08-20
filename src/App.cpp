#include "App.h"
#include "window/WindowMgr.h"

App::App()
{
    // wnd = new GLWindow(600, 400, "Open3D");
    pWindow = WindowMgr::getWindow(600, 400, "Open3D");
}

App::~App()
{
    delete pWindow;
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
