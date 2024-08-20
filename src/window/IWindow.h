
#pragma once
class IWindow
{
public:
    // IWindow(int width, int height, const std::string &title);
    // ~IWindow();
    virtual void render() = 0;
    virtual void showWindowCenter() = 0;

    // int width;
    // int height;
    // const std::string &title;
};