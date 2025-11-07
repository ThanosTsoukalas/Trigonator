#ifndef SHADER_H
#define SHADER_H
#include <g_header/gl_tools.h>

static unsigned int CompileShader(unsigned int type, const std::string &source);
static unsigned int CreateShader (std::string& vertexShader, std::string& fragmentShader);
#endif