//
//  SimpleSwingShaderProgram.cpp
//  GameEngineX
//
//  Created by Stefan Söderberg on 2016-07-17.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "SimpleSwingShaderProgram.hpp"

bool SimpleSwingShaderProgram::CompileShaders(const char *vertexshader, const char *fragmentshader)
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

void SimpleSwingShaderProgram::SetupAttribs()
{
    this->_positionattribute = glGetAttribLocation(_program, "Position");
    this->_normalattribute = glGetAttribLocation(_program, "Normal");
    this->_texcoordattribute = glGetAttribLocation(_program, "TextureCoord");
    this->_colorattribute = glGetAttribLocation(_program, "SourceColor");
    glEnableVertexAttribArray(_positionattribute);
    glEnableVertexAttribArray(_normalattribute);
    glEnableVertexAttribArray(_texcoordattribute);
    glEnableVertexAttribArray(_colorattribute);
}

void SimpleSwingShaderProgram::SetupUniforms()
{
    _mvpmatrix = glGetUniformLocation(_program, "MVPMatrix");
    _vpmatrix = glGetUniformLocation(_program, "VPMatrix");
    _mvmatrix = glGetUniformLocation(_program, "MVMatrix");
    _mmatrix = glGetUniformLocation(_program, "MMatrix");
    _texture = glGetUniformLocation(_program, "Texture");
    _normalmap = glGetUniformLocation(_program, "Normalmap");
    _directionallightdir = glGetUniformLocation(_program, "u_directionallightdir");
    _directionallightcol = glGetUniformLocation(_program, "u_directionallightcolor");
    _directionallightambient = glGetUniformLocation(_program, "u_directionallightambient");
    _pointlightpositions = glGetUniformLocation(_program, "u_pointlightspos");
    _pointlightcolors = glGetUniformLocation(_program, "u_pointlightscolor");
    _pointlightsizes = glGetUniformLocation(_program, "u_pointlightssize");
    
    _time = glGetUniformLocation(_program, "u_time");
    _offset = glGetUniformLocation(_program, "u_offset");
    _reverse = glGetUniformLocation(_program, "u_reverse");
    //_speed = glGetUniformLocation(_program, "u_speed");
    //_bend = glGetUniformLocation(_program, "u_bendFactor");
}