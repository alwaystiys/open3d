#pragma once

class Component
{

public:
    virtual void init(int width, int height) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void destroy() = 0;
};