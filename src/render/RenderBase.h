#pragma once
#include "../window/IWindow.h"

class RenderContext
{
public:
    virtual bool init(IWindow*) = 0;
    virtual void pre_render() = 0;
    virtual void post_render() = 0;
    virtual void destroy() = 0;
};
