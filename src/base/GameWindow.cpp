#include "GameWindow.h"

GameWindow::GameWindow(int width, int height, const std::string &title) : width(width), height(height), title(title) {



    // if (!glfwInit())
    // {
    //     std::cout << "glfw init failed" << std::endl;
    //     // return -1;
    // }

    // glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    // glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
    
    // GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    // float xscale, yscale;
    // glfwGetMonitorContentScale(monitor, &xscale, &yscale);
    // std::cout << "[INFO] Monitor scale: " << xscale << "x" << yscale << std::endl;


    // GLFWwindow *window = glfwCreateWindow(880, 480, "Open3D", NULL, NULL);
}

GameWindow::~GameWindow() {
    
}