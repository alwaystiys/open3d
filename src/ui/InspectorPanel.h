#pragma once
#include "Component.h"

class InspectorPanel : public Component
{

public:
    InspectorPanel();
    ~InspectorPanel();
    
    void init(int width, int height);
    void update();
    void render();
    void destroy();
};