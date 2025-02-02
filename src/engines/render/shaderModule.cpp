#include <GL/glew.h>
#include <GL/gl.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <engines/render/shaderModule.hpp>


//////////////////////
////// Builders //////
//////////////////////
ShaderModule::ShaderModule() { }
ShaderModule::~ShaderModule() { }


//////////////////
////// Main //////
//////////////////
void ShaderModule::init(const ShaderCrate& crate) { }
void ShaderModule::useShader(const char* name) {
    glUseProgram(shaders.at(name));
}

void ShaderModule::setUniform(const char* shaderName, const char* uniformName, const float& value) {
    glUniform1f(glGetUniformLocation(shaders.at(shaderName), uniformName), value);
}

void ShaderModule::loadShader(const char* name, const char* vertPath, const char* fragPath) {
    GLuint vertexShader = compileShader(vertPath, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragPath, GL_FRAGMENT_SHADER);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    ////// Check for linking errors //////
    GLint success; glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar infoLog[512]; glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        throw std::runtime_error(std::string("Fatal Error: App::RenderEngine::ShaderModule::loadShader::glCreateProgram().\n-------- INFO LOG - INFO LOG - INFO LOG - INFO LOG --------: \n\n\n\n\n").append(infoLog).append("\n\n\n\n\n"));
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    shaders[name] = shaderProgram;
}

GLuint ShaderModule::compileShader(const char* path, GLenum shaderType) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string shaderSource = buffer.str();
    const char* src = shaderSource.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    ////// Check for compilation errors //////
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512]; glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        throw std::runtime_error(std::string("Fatal Error: App::RenderEngine::ShaderModule::compileShader::glCompileShader().\n-------- INFO LOG - INFO LOG - INFO LOG - INFO LOG --------: \n\n\n\n\n").append(infoLog).append("\n\n\n\n\n"));
    }

    return shader;
}
