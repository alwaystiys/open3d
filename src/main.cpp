#include "App.h"
#include "glm/glm.hpp"
#include "spdlog/spdlog.h"

int main()
{
    spdlog::info("Welcome to spdlog!");
    return App().loop();
}