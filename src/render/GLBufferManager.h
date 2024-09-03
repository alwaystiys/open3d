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
	void createBuffer(std::vector<VertexHolder>, std::vector<GLuint> indices);
	void deleteBuffer();
	void bind();
	void unbind();
	void draw();


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
};