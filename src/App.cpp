#include "App.h"
#include "window/WindowMgr.h"

App::App()
{
    // wnd = new GLWindow(600, 400, "Open3D");
    wnd = WindowMgr::getWindow(600, 400, "Open3D");
}

App::~App()
{
    delete wnd;
}

void App::loop()
{
    wnd->render();
}

void App::doFrame(float dt)
{
}

void App::handleInput(float dt)
{
}
