//
//  SimpleLightingShaderProgram.cpp
//  GameEngineX
//
//  Created by George Hanna on 29/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "SimpleLightingShaderProgram.hpp"
#include <iostream>

bool SimpleLightingShaderProgram::CompileShaders(const char *vertexshader, const char *fragmentshader)
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

void SimpleLightingShaderProgram::SetupAttribs()
{
    this->_positionattribute = glGetAttribLocation(_program, "Position");
    this->_normalattribute = glGetAttribLocation(_program, "Normal");
    this->_texcoordattribute = glGetAttribLocation(_program, "TextureCoord");
    this->_colorattribute = glGetAttribLocation(_program, "SourceColor");

  glEnableVertexAttribArray(_positionattribute);
    glEnableVertexAttribArray(_normalattribute);
    glEnableVertexAttribArray(_texcoordattribute);
    //glEnableVertexAttribArray(_colorattribute);
}

void SimpleLightingShaderProgram::SetupUniforms()
{
    _mvpmatrix = glGetUniformLocation(_program, "MVPMatrix");
    _vpmatrix = glGetUniformLocation(_program, "VPMatrix");
    _mvmatrix = glGetUniformLocation(_program, "MVMatrix");
    _mmatrix = glGetUniformLocation(_program, "MMatrix");
    _texture = glGetUniformLocation(_program, "Texture");
    _directionallightdir = glGetUniformLocation(_program, "u_directionallightdir");
    _directionallightcol = glGetUniformLocation(_program, "u_directionallightcolor");
    _directionallightambient = glGetUniformLocation(_program, "u_directionallightambient");
    _pointlightpositions = glGetUniformLocation(_program, "u_pointlightspos");
    _pointlightcolors = glGetUniformLocation(_program, "u_pointlightscolor");
    _pointlightsizes = glGetUniformLocation(_program, "u_pointlightssize");
}
