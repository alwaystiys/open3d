#pragma once
#include "Component.h"
#include "../shader/Shader.h"
#include <memory>

class SceneView : public Component
{

public:
    SceneView();
    ~SceneView();

    void init(int width, int height);
    void update();
    void render();
    void destroy();

    void resize(int width, int height);

private:
    std::unique_ptr<Shader> mShader;
    GLuint mVAO, mVBO, mFBO, mTextureId;
};