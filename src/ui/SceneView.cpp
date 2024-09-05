#include "SceneView.h"
#include <imgui.h>
#include "spdlog/spdlog.h"

SceneView::SceneView()
{
}

SceneView::~SceneView()
{
}

void SceneView::init(int width, int height)
{

    mShader = std::make_unique<Shader>("test.vs", "test.fs");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left
        0.5f, -0.5f, 0.0f,  // right
        0.0f, 0.5f, 0.0f    // top
    };

    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(mVAO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    resize(width, height);

}



void SceneView::resize(int width, int height)
{
    if (mFBO)
    {
        glDeleteFramebuffers(1, &mFBO);
        glDeleteTextures(1, &mTextureId);
        mTextureId = 0;
    }

    glGenFramebuffers(1, &mFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
    glGenTextures(1, &mTextureId);
    glBindTexture(GL_TEXTURE_2D, mTextureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTextureId, 0);

    glBindFramebuffer(GL_RENDERBUFFER, 0);
}

void SceneView::update()
{
}

void SceneView::render()
{
    // ImGui::Begin("Scene");
    // ImGui::End();
    mShader->use();
    // ImGui::SetNextWindowSize(ImVec2(800, 600));
    ImGui::Begin("Scene");

    float window_width = ImGui::GetContentRegionAvail().x;
    float window_height = ImGui::GetContentRegionAvail().y;

    // spdlog::info("IMGUI Scene Window size: {}x{}", window_width, window_height);

    glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
    double time = glfwGetTime();
    //glViewport(0, 0, mWindow->width, mWindow->height);
    glClearColor(sin(time), cos(time), 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindVertexArray(mVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glViewport(0, 0, window_width, window_height);
    ImGui::Image(reinterpret_cast<void *>(mTextureId), ImVec2{window_width, window_height}, ImVec2{0, 1}, ImVec2{1, 0});
    ImGui::End();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void SceneView::destroy()
{
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
    glDeleteFramebuffers(1, &mFBO);
    glDeleteTextures(1, &mTextureId);
}