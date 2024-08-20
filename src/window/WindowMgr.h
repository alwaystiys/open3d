#pragma once
#pragma once

#include "IWindow.h"

#define USE_OPENGL_WND

#ifdef USE_OPENGL_WND
#include "GLWindow.h"
using CurrWindow = GLWindow;
#endif

class WindowMgr
{

public:
    static CurrWindow *getWindow(int width, int height, const char *title)
    {
        return new CurrWindow(width, height, title);
    }

private:
    int width;
    int height;
    const char *title;
};