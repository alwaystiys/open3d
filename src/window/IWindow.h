#pragma once

class IWindow
{
public:
    // IWindow(int width, int height, const std::string &title);
    // ~IWindow();
    virtual void render() = 0;
    virtual void showWindowCenter() = 0;
    virtual bool shouldClosed() = 0;

protected:
    int width;
    int height;
    const char *title;
};