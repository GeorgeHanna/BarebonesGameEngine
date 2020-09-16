//
//  ShaderProgram.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "ShaderProgram.hpp"
#include <iostream>

bool ShaderProgram::CompileShaders(const char *vertexshader, const char *fragmentshader)
{
    
    // 1
    GLuint vertexShader = CompileVertexShader(vertexshader);
    GLuint fragmentShader = CompileFragmentShader(fragmentshader);
    
    // 2
    _program = glCreateProgram();
    glAttachShader(_program, vertexShader);
    glAttachShader(_program, fragmentShader);
    glLinkProgram(_program);
    
    // 3
    GLint linkSuccess;
    glGetProgramiv(_program, GL_LINK_STATUS, &linkSuccess);
    if (linkSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetProgramInfoLog(_program, sizeof(messages), 0, &messages[0]);
        printf(messages);
        return false;
    }

    return true;
}


GLuint ShaderProgram::CompileVertexShader(const char *vertexshader)
{
    return CompileShader(vertexshader, GL_VERTEX_SHADER);
}

GLuint ShaderProgram::CompileFragmentShader(const char *fragmentshader)
{
    return CompileShader(fragmentshader, GL_FRAGMENT_SHADER);
}

GLuint ShaderProgram::CompileShader(const char *shader, GLenum shadertype)
{
    // 2
    GLuint shaderHandle = glCreateShader(shadertype);
    
    // 3
    int shaderStringLength = strlen(shader);
    glShaderSource(shaderHandle, 1, &shader, &shaderStringLength);
    
    // 4
    glCompileShader(shaderHandle);
    
    // 5
    GLint compileSuccess;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
    if (compileSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetShaderInfoLog(shaderHandle, sizeof(messages), 0, &messages[0]);
        printf(messages);
    }
    
    return shaderHandle;

}
