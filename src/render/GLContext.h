#pragma once
#include "RenderBase.h"

class GLContext : public RenderContext
{
public:
    GLContext();
    ~GLContext();

    bool init();
    void pre_render();
    void post_render();
    void destroy();
};