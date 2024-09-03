#include "GLBufferManager.h"

void GLVertexBufferHoder::createBuffer(std::vector<VertexHolder>, std::vector<GLuint> indices) {

	glGenVertexArrays(1, &mVAO);

	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	//

	glBindVertexArray(0);
}

void GLVertexBufferHoder::deleteBuffer() {

}

void GLVertexBufferHoder::bind() {

}

void GLVertexBufferHoder::unbind() {

}

void GLVertexBufferHoder::draw() {

}

