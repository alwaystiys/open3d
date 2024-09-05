#pragma once
#include "Component.h"
#include "../shader/Shader.h"
#include <memory>
#include "../render/GLBufferManager.h"

class HostView : public Component
{

public:
    HostView();
    ~HostView();

    void init(int width, int height);
    void update();
    void render();
    void destroy();

private:
    std::unique_ptr<Shader> mShader;
    std::unique_ptr<GLVertexBufferHoder> pBufferMgr;
    GLuint mVAO, mVBO, mTextureId;
};