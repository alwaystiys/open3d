#include "GLBufferManager.h"

/*

*/
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

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void*)offsetof(VertexHolder, color));


	glBindVertexArray(0);
}

void GLVertexBufferHoder::deleteBuffer() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
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

/*

*/
void GLFrameBuffer::createBuffer(GLint width, GLint height) {
	mWidth = width;
	mHeight = height;

	if (mFBO) {
		deleteBuffer();
	}

	glGenFramebuffers(1, &mFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, mFBO);

	glCreateTextures(GL_TEXTURE_2D, 1, &mTexId);
	glBindTexture(GL_TEXTURE_2D, mTexId);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);













}

void GLFrameBuffer::deleteBuffer() {
	if (mFBO) {
		glDeleteFramebuffers(1, &mFBO);
		glDeleteTextures(1, &mTexId);
		glDeleteTextures(1, &mDepthId);
		mTexId = 0;
		mDepthId = 0;
	}
}


void GLFrameBuffer::bind() {
	glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
}

void GLFrameBuffer::unbind() {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLuint GLFrameBuffer::getTexture() {
	return 0;
}