#pragma once
#include "../window/IWindow.h"

class RenderContext
{
public:
    RenderContext() : mWindow(nullptr) {}
    virtual bool init(IWindow *window)
    {
        mWindow = window;
        return true;
    }
    virtual void pre_render() = 0;
    virtual void post_render() = 0;
    virtual void destroy() = 0;

protected:
    IWindow *mWindow;
};
