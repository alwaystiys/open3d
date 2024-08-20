#pragma once
#include "window/GLWindow.h"

class App
{

public:
    App();
    ~App();
    int loop();

private:
    void doFrame(float dt);
    void handleInput(float dt);

private:
    IWindow *pWindow;
};