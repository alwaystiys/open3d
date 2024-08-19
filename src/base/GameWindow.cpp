#include "GameWindow.h"

GameWindow::GameWindow(int width, int height, const char* title) : width(width), height(height), title(title) {

    if (!glfwInit())
    {
        std::cout << "glfw init failed" << std::endl;
        // return -1;
    }
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    float xscale, yscale;
    glfwGetMonitorContentScale(monitor, &xscale, &yscale);
    std::cout << "[INFO] Monitor scale: " << xscale << "x" << yscale << std::endl;

    // if (xscale > 1 || yscale > 1)
    // {
    //     highDPIscaleFactor = xscale;
    //     glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
    // }
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
    GLFWwindow *window = glfwCreateWindow(880, 480, "Open3D", NULL, NULL);
}

GameWindow::~GameWindow() {
    
}