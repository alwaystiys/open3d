#include "GLWindow.h"
#include "spdlog/spdlog.h"

GLWindow::GLWindow()
{
    mWindow = nullptr;
    pCtx = std::make_unique<GLContext>();
    pUICtx = std::make_unique<UIContext>();
    pSceneView = std::make_unique<SceneView>();
    pInspectorPanel = std::make_unique<InspectorPanel>();
    pHostView = std::make_unique<HostView>();
}

GLWindow::~GLWindow()
{
    pHostView->destroy();
    pSceneView->destroy();
    // drawDestroyTest();
    pCtx->destroy();
    pUICtx->destroy();
}

void GLWindow::init(int width, int height, const char *title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    pCtx->init(this);
    pUICtx->init(this);
    pHostView->init(this->width, this->height);
    pSceneView->init(this->width, this->height);

    // drawInitTest();
    // drawCreateFramebuffer(this->width, this->height);
}

bool GLWindow::shouldClosed()
{
    return glfwWindowShouldClose(mWindow);
}

void GLWindow::render()
{
    pCtx->pre_render();
    pUICtx->pre_render();

    pInspectorPanel->render();
    pSceneView->render();

    pHostView->render();

    // drawToImGUITest();
    // drawTest();

    pUICtx->post_render();
    pCtx->post_render();
}

void GLWindow::drawInitTest()
{
    VBO = 0;
    VAO = 0;
    FBO = 0;
    RBO = 0;
    texture_id = 0;

    // std::string vsName = "test.vs";
    // std::string fsName = "test.fs";
    pShader = std::make_unique<Shader>("test.vs", "test.fs");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left
        0.5f, -0.5f, 0.0f,  // right
        0.0f, 0.5f, 0.0f    // top
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void GLWindow::drawToImGUITest()
{
    pShader->use();
    ImGui::Begin("Scene");

    float window_width = ImGui::GetContentRegionAvail().x;
    float window_height = ImGui::GetContentRegionAvail().y;

    // spdlog::info("IMGUI Scene Window size: {}x{}", window_width, window_height);

    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glViewport(0, 0, this->width, this->height);
    // glViewport(0, 0, window_width, window_height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glViewport(0, 0, window_width, window_height);
    ImGui::Image(reinterpret_cast<void *>(texture_id), ImVec2{window_width, window_height}, ImVec2{0, 1}, ImVec2{1, 0});
    ImGui::End();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GLWindow::drawTest()
{
    glViewport(0, 0, this->width, this->height);
    pShader->use();
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GLWindow::drawDestroyTest()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glDeleteFramebuffers(1, &FBO);
    glDeleteTextures(1, &texture_id);
    glDeleteRenderbuffers(1, &RBO);
}

void GLWindow::drawCreateFramebuffer(int window_width, int window_height)
{

    if (FBO)
    {
        glDeleteFramebuffers(1, &FBO);
        glDeleteTextures(1, &texture_id);
        texture_id = 0;
    }

    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, window_width, window_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id, 0);

    glBindFramebuffer(GL_RENDERBUFFER, 0);
}

void GLWindow::handleMsg()
{
    pHostView->update();

}

void GLWindow::onKeyCallback(int key, int scancode, int action, int mods)
{
    spdlog::info("onKeyCallback {} {} {} {}", key, scancode, action, mods);
}

void GLWindow::onScrollCallback(double delta)
{
    spdlog::info("onScrollCallback {}", delta);
}

void GLWindow::onMouseButtonCallback(int button, int action, int mods)
{
    spdlog::info("onMouseButtonCallback {} {} {}", button, action, mods);
}

void GLWindow::onWindowResizeCallback(int width, int height)
{
    spdlog::info("onWindowResizeCallback {} {}", width, height);
    this->width = width;
    this->height = height;
    pSceneView->resize(width, height);
    // drawCreateFramebuffer(this->width, this->height);
}