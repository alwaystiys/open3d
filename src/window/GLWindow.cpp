#include "GLWindow.h"

GLWindow::GLWindow()
{
    mWindow = nullptr;
    pCtx = std::make_unique<GLContext>();
    // pUICtx = std::make_unique<UIContext>();
    pSceneView = std::make_unique<SceneView>();
    pInspectorPanel = std::make_unique<InspectorPanel>();
}

GLWindow::~GLWindow()
{
    drawDestroyTest();
    pCtx->destroy();
    // pUICtx->destroy();

}

void GLWindow::init(int width, int height, const char *title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    pCtx->init(this);
    // pUICtx->init(this);


    drawInitTest();

}

bool GLWindow::shouldClosed()
{
    return glfwWindowShouldClose(mWindow);
}

void GLWindow::render()
{
    pCtx->pre_render();
    // pUICtx->pre_render();

    // pInspectorPanel->render();
    // pSceneView->render();

    drawTest();

    // pUICtx->post_render();
    pCtx->post_render();
}

void GLWindow::drawInitTest(){

    std::string vsName = "test.vs";
    std::string fsName = "test.fs";
    pShader = std::make_unique<Shader>(vsName, fsName);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
}


void GLWindow::drawTest(){

    pShader->use();
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);




}


void GLWindow::drawDestroyTest(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void GLWindow::handleMsg()
{
}

void GLWindow::onKeyCallback(int key, int scancode, int action, int mods)
{
    std::cout << "gl onKeyCallback " << key << " " << scancode << " " << action << " " << mods << std::endl;
}

void GLWindow::onScrollCallback(double delta)
{
    std::cout << "gl onScrollCallback " << delta << std::endl;
}

void GLWindow::onMouseButtonCallback(int button, int action, int mods)
{
    std::cout << "gl onMouseButtonCallback " << button << " " << action << " " << mods << std::endl;
}

void GLWindow::onWindowResizeCallback(int width, int height)
{
    std::cout << "gl onWindowResizeCallback " << width << " " << height << std::endl;
}