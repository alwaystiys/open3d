#pragma once

#include "../pch.h"
#include "VertexHolder.h"


/**
 * 顶点缓冲区管理器
 * 包含顶点数据以及索引数据
*/
class GLVertexBufferHoder
{

public:
	GLVertexBufferHoder(): mVBO(0), mVAO(0), mIBO(0){}
	void createBuffer(std::vector<VertexHolder>& vertices, std::vector<GLuint>& indices);
	void deleteBuffer();
	void bind();
	void unbind();
	void draw(GLsizei count);
protected:
	GLuint mVBO;
	GLuint mIBO;
	GLuint mVAO;
};

/**
 * 帧对象
 */
class GLFrameBuffer
{

protected:
	GLuint mFBO;
	GLuint mTexId;
	GLuint mDepthId;

	GLint mWidth;
	GLint mHeight;


};