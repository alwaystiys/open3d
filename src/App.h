
#include "base/GameWindow.h"

class App
{

public:
    App(const std::string& app_name);
    ~App();

private:
    void loop();
    void doFrame(float dt);
    void handleInput(float dt);

private:
    GameWindow wnd;
};