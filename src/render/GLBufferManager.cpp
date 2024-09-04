#include "GLBufferManager.h"

void GLVertexBufferHoder::createBuffer(std::vector<VertexHolder>& vertices, std::vector<GLuint>& indices) {

	glGenVertexArrays(1, &mVAO);

	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexHolder), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void*)0);


	glBindVertexArray(0);
}

void GLVertexBufferHoder::deleteBuffer() {
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &mVBO);
	glDeleteBuffers(1, &mIBO);
	glDeleteVertexArrays(1, &mVAO);

}

void GLVertexBufferHoder::bind() {
	glBindVertexArray(mVAO);
}

void GLVertexBufferHoder::unbind() {
	glBindVertexArray(0);
}

void GLVertexBufferHoder::draw(GLsizei count) {
	bind();
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	unbind();
}

