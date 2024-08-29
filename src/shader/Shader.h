#pragma once

#include "../pch.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

enum COMPILE_TYPE
{
    VERTEX = 1,
    FRAGMENT = 2,
    GEOMETRY = 3,
    PROGRAM = 4,
};

class Shader
{
public:
    Shader();
    Shader(std::string vsFileName, std::string fsFileName);
    // Shader(std::string& vsFileName, std::string& fsFileName, std::string& gsFileName);
    Shader(Shader &) = delete;
    Shader &operator=(Shader &) = delete;

    ~Shader()
    {
        glDeleteProgram(this->ID);
    }

    void use()
    {
        glUseProgram(this->ID);
    }

    void setBool(const GLchar *name, GLboolean value);
    void setInt(const GLchar *name, GLint value);
    void setFloat(const GLchar *name, GLfloat value);
    void setVector2f(const GLchar *name, GLfloat x, GLfloat y);
    void setVector2f(const GLchar *name, const glm::vec2 &value);
    void setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z);
    void setVector3f(const GLchar *name, const glm::vec3 &value);
    void setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void setVector4f(const GLchar *name, const glm::vec4 &value);
    void setMatrix4(const GLchar *name, const glm::mat4 &matrix);

private:
    void checkCompileErrors(GLuint object, std::string type);
    std::string readFromFile(std::string &filePath);
    void compile(const GLchar *vertexStr, const GLchar *fragmentStr, const GLchar *geometryStr = nullptr);

public:
    GLuint ID;
};