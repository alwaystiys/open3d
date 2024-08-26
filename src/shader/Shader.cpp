#include "Shader.h"
#include "spdlog/spdlog.h"
#include <fstream>
#include <sstream>

Shader::Shader()
{
}

Shader::Shader(std::string& vsFileName, std::string& fsFileName)
{
    std::string vertexCode = readFromFile(vsFileName);
    std::string fragmentCode = readFromFile(fsFileName);

    compile(vertexCode.c_str(), fragmentCode.c_str());  
}

// Shader::Shader(std::string& vsFileName, std::string& fsFileName, std::string& gsFileName)
// {
//     std::string vertexCode = readFromFile(vsFileName);
//     std::string fragmentCode = readFromFile(fsFileName);
// }

std::string Shader::readFromFile(std::string& fileName){
    std::string source;
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        file.open("res/shaders/" + fileName);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        source = stream.str();
        return source;
    }
    catch (std::ifstream::failure &e)
    {
        spdlog::error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: {}", e.what());
        return "";
    }
}

void Shader::compile(const GLchar *vertexSource, const GLchar *fragmentSource, const GLchar *geometrySource)
{
    GLuint sVertex, sFragment, gShader;
    // 1. Compile shaders
    // Vertex shader
    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vertexSource, nullptr);
    glCompileShader(sVertex);
    checkCompileErrors(sVertex, "VERTEX");
    // Fragment shader
    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fragmentSource, nullptr);
    glCompileShader(sFragment);
    checkCompileErrors(sFragment, "FRAGMENT");
    // If geometry shader is given, compile geometry shader
    if (geometrySource != nullptr)
    {
        gShader = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(gShader, 1, &geometrySource, nullptr);
        glCompileShader(gShader);
        checkCompileErrors(gShader, "GEOMETRY");
    }
    // 2. Link shaders
    this->ID = glCreateProgram();
    glAttachShader(this->ID, sVertex);
    glAttachShader(this->ID, sFragment);
    if (geometrySource != nullptr)
    {
        glAttachShader(this->ID, gShader);
    }
    glLinkProgram(this->ID);
    checkCompileErrors(this->ID, "PROGRAM");
    // Delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
    if (geometrySource != nullptr)
    {
        glDeleteShader(gShader);
    }
}

void Shader::checkCompileErrors(GLuint object, std::string type)
{
    GLint success;
    GLchar infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, NULL, infoLog);
            spdlog::error("| ERROR::SHADER: Compile-time error: Type: {0}\n{1}\n -- --------------------------------------------------- -- ", type, infoLog);
            // std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
            //           << infoLog << "\n -- --------------------------------------------------- -- "
            //           << std::endl;
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            spdlog::error("| ERROR::Shader: Link-time error: Type: {0}\n{1}\n -- --------------------------------------------------- -- ", type, infoLog);
            // std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
            //           << infoLog << "\n -- --------------------------------------------------- -- "
            //           << std::endl;
        }
    }
}

void Shader::setBool(const GLchar *name, GLboolean value)
{
    glUniform1i(glGetUniformLocation(this->ID, name), (GLint)value);
}

void Shader::setInt(const GLchar *name, GLint value)
{

    glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::setFloat(const GLchar *name, GLfloat value)
{

    glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::setVector2f(const GLchar *name, GLfloat x, GLfloat y)
{

    glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::setVector2f(const GLchar *name, const glm::vec2 &value)
{

    glUniform2fv(glGetUniformLocation(this->ID, name), 1, glm::value_ptr(value));
}

void Shader::setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z)
{

    glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::setVector3f(const GLchar *name, const glm::vec3 &value)
{

    glUniform3fv(glGetUniformLocation(this->ID, name), 1, glm::value_ptr(value));
}

void Shader::setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{

    glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}

void Shader::setVector4f(const GLchar *name, const glm::vec4 &value)
{

    glUniform4fv(glGetUniformLocation(this->ID, name), 1, glm::value_ptr(value));
}

void Shader::setMatrix4(const GLchar *name, const glm::mat4 &matrix)
{
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}