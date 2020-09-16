//
//  SimpleSwingShaderProgram.hpp
//  GameEngineX
//
//  Created by Stefan Söderberg on 2016-07-17.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef SimpleSwingShaderProgram_hpp
#define SimpleSwingShaderProgram_hpp

#include <stdio.h>
#include "SimpleLightingShaderProgram.hpp"
class SimpleSwingShaderProgram : public ShaderProgram
{
    void SetupAttribs();
    void SetupUniforms();
public:
    //uniforms
    
    GLuint _projectionmatrix;
    GLuint _mvpmatrix;
    GLuint _vpmatrix;
    GLuint _mvmatrix;
    GLuint _mmatrix;
    GLuint _texture;
    GLuint _normalmap;
    GLuint _directionallightdir;
    GLuint _directionallightcol;
    GLuint _directionallightambient;
    GLuint _pointlightpositions;
    GLuint _pointlightcolors;
    GLuint _pointlightsizes;
    //attributes
    GLuint _positionattribute;
    GLuint _texcoordattribute;
    GLuint _normalattribute;
    GLuint _colorattribute;
    
    //Move
    GLuint _time;
    //GLuint _bend;
    //GLuint _speed;
    GLuint _offset;
    GLuint _reverse;
    
    bool CompileShaders(const char* vertexshader, const char* fragmentshader);
};
#endif /* SimpleSwingShaderProgram_hpp */
