//
//  SimpleShaderProgram.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef SimpleShaderProgram_hpp
#define SimpleShaderProgram_hpp

#include <stdio.h>
#include "ShaderProgram.hpp"


class SimpleShaderProgram : public ShaderProgram
{
    void SetupAttribs();
    void SetupUniforms();
public:
    //uniforms
    GLuint _projectionmatrix;
    GLuint _mvpmatrix;
    GLuint _vpmatrix;
    GLuint _mvmatrix;
    GLuint _texture;
    GLuint _color;
    //attributes
    GLuint _positionattribute;
    GLuint _texcoordattribute;
    
    bool CompileShaders(const char* vertexshader, const char* fragmentshader);
};

#endif /* SimpleShaderProgram_hpp */
