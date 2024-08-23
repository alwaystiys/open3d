#pragma once

class IWindow
{
public:
    // IWindow(int width, int height, const std::string &title);
    // ~IWindow();
    virtual void init(int width, int height, const char *title) = 0;
    virtual void render() = 0;
    virtual bool shouldClosed() = 0;
    virtual void setNativeWindow(void *window) = 0;
    virtual void *getNativeWindow() = 0;
    virtual void setNativeMonitor(void *monitor) {}
    virtual void *getNativeMonitor() { return nullptr; }
    virtual void handleMsg() = 0;

    // input
    virtual void onKeyCallback(int key, int scancode, int action, int mods) = 0;
    virtual void onScrollCallback(double delta) = 0;
    virtual void onMouseButtonCallback(int button, int action, int mods) = 0;
    virtual void onWindowResizeCallback(int width, int height) = 0;

public:
    int width;
    int height;
    const char *title;
};