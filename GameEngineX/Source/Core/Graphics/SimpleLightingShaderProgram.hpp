//
//  SimpleLightingShaderProgram.hpp
//  GameEngineX
//
//  Created by George Hanna on 29/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef SimpleLightingShaderProgram_hpp
#define SimpleLightingShaderProgram_hpp

#include <stdio.h>
#include "ShaderProgram.hpp"

class SimpleLightingShaderProgram : public ShaderProgram
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
    
    bool CompileShaders(const char* vertexshader, const char* fragmentshader);
};

#endif /* SimpleLightingShaderProgram_hpp */
