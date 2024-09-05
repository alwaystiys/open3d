#include "HostView.h"
#include "../render/VertexHolder.h"

HostView::HostView() : mVAO(0), mVBO(0), mTextureId(0)
{
    pBufferMgr = std::make_unique<GLVertexBufferHoder>();
}

HostView::~HostView()
{
}

void HostView::init(int width, int height)
{
    mShader = std::make_unique<Shader>("test_color.vs", "test_color.fs");

    //float vertices[] = {
    //    -0.5f, -0.5f, 0.0f, // left
    //    0.5f, -0.5f, 0.0f,  // right
    //    0.0f, 0.5f, 0.0f    // top
    //};

    //glGenVertexArrays(1, &mVAO);
    //glGenBuffers(1, &mVBO);
    //// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    //glBindVertexArray(mVAO);

    //glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    //glEnableVertexAttribArray(0);

    //// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    //// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    //// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    //glBindVertexArray(0);

    VertexHolder hoder;
    hoder.postion = glm::vec3(-0.5f, -0.5f, 0.0f);
    hoder.color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    VertexHolder hoder2;
    hoder2.postion = glm::vec3(0.5f, -0.5f, 0.0f);
    hoder2.color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    VertexHolder hoder3;
    hoder3.postion = glm::vec3(0.0f, 0.5f, 0.0f);
    hoder3.color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
    std::vector<VertexHolder> vertices;
    vertices.push_back(hoder);
    vertices.push_back(hoder2);
    vertices.push_back(hoder3);

    std::vector<GLuint> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    pBufferMgr->createBuffer(vertices, indices);

}

void HostView::update()
{
}

void HostView::render()
{
    mShader->use();
    glBindVertexArray(mVAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    pBufferMgr->draw(3);
}

void HostView::destroy()
{
    pBufferMgr->deleteBuffer();
    //glDeleteVertexArrays(1, &mVAO);
    //glDeleteBuffers(1, &mVBO);
}