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

public:
    int width;
    int height;
    const char *title;
};