#pragma once

class RenderContext
{
public:
    virtual bool init() = 0;
    virtual void pre_render() = 0;
    virtual void post_render() = 0;
    virtual void destroy() = 0;
};
