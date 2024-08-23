#pragma once
#include "window/GLWindow.h"

class App
{

public:
    App();
    ~App();
    int loop();
private:
    std::unique_ptr<IWindow> pWindow;
};