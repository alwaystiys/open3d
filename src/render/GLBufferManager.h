#pragma once

#include "../pch.h"

/**
 * 顶点缓冲区管理器
 * 包含顶点数据以及索引数据
*/
class GLVertexBufferHoder
{

public:
	void createBuffer();
	void deleteBuffer();
	void bind();
	void unbind();


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