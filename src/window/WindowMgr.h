#pragma once
#pragma once

#include "IWindow.h"

// #define GRAPHICS_API_DX11
// #define GRAPHICS_API_DX12
// #define GRAPHICS_API_VULKAN
#define GRAPHICS_API_OPENGL

#ifdef GRAPHICS_API_OPENGL
#include "GLWindow.h"
using CurrWindow = GLWindow;
#elif USE_DIRECT_WND

#endif

class WindowMgr
{

public:
    // static CurrWindow *getWindow(int width, int height, const char *title)
    // {
    //     return new CurrWindow(width, height, title);
    // }
    static std::unique_ptr<CurrWindow> createWindow()
    {
        return std::make_unique<CurrWindow>();
    }
};