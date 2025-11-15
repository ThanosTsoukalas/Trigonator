#include "shader.hpp"

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
        
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) // σε περίπτωση αποτυχίας στο compilation
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "OpenGL: αποτυχία μεταγλώττισης "<<
        (type == GL_VERTEX_SHADER? "Vertex" : "Fragment")
        <<" shader!" << std::endl;

        std::cout << message << std::endl;

        glDeleteShader(id);

        return 0;
    }


    return id;
}

unsigned int CreateShader (std::string& vertexShader, std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();

    unsigned int v_shader = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int f_shader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(v_shader);
    glDeleteShader(f_shader);

    return program;
}