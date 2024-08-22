#pragma once
#include "RenderBase.h"
#include "../window/IWindow.h"

class GLContext : public RenderContext
{
public:
    GLContext();
    ~GLContext();

    bool init(IWindow*);
    void pre_render();
    void post_render();
    void destroy();


private:
    
};