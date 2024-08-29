#include "App.h"
#include "window/WindowMgr.h"

App::App()
{
    pWindow = WindowMgr::createWindow(); 
    pWindow->init(900, 500, "Simple Renderer");
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
        pWindow->handleMsg();
        pWindow->render();
    }
    return 0;
}

