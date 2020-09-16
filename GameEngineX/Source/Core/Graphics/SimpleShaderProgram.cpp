//
//  SimpleShaderProgram.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "SimpleShaderProgram.hpp"

bool SimpleShaderProgram::CompileShaders(const char *vertexshader, const char *fragmentshader)
{
    if(ShaderProgram::CompileShaders(vertexshader, fragmentshader))
    {
        glUseProgram(_program);
        SetupAttribs();
        SetupUniforms();
        return true;
    }
    else
        return false;
}

void SimpleShaderProgram::SetupAttribs()
{
    this->_positionattribute = glGetAttribLocation(_program, "Position");
    this->_texcoordattribute = glGetAttribLocation(_program, "TextureCoord");
    glEnableVertexAttribArray(_positionattribute);
    glEnableVertexAttribArray(_texcoordattribute);
}

void SimpleShaderProgram::SetupUniforms()
{
    _mvpmatrix = glGetUniformLocation(_program, "MVPMatrix");
    _vpmatrix = glGetUniformLocation(_program, "VPMatrix");
    _mvmatrix = glGetUniformLocation(_program, "MVMatrix");
    _texture = glGetUniformLocation(_program, "Texture");
    _color = glGetUniformLocation(_program, "SourceColor");
}