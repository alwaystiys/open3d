#pragma once
#include "Component.h"

class SceneView : public Component
{

public:
    SceneView();
    ~SceneView();

    void render();
};