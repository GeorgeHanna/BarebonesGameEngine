//
//  ShaderProgram.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef ShaderProgram_hpp
#define ShaderProgram_hpp

#include <stdio.h>
#include <string.h>


#include "openglinclude.h"

class ShaderProgram
{

    GLuint CompileVertexShader(const char* vertexshader);
    GLuint CompileFragmentShader(const char* fragmentshader);
    GLuint CompileShader(const char* shader, GLenum shadertype);
//    void SetupAttribs();
//    void SetupUniforms();

public:    
    GLuint _program;
    bool CompileShaders(const char* vertexshader, const char* fragmentshader);

};

#endif /* ShaderProgram_hpp */
