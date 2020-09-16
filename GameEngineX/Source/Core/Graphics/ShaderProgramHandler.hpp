//
//  ShaderProgramHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef ShaderProgramHandler_hpp
#define ShaderProgramHandler_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <fstream>
#include "SimpleShaderProgram.hpp"
#include "SimpleLightingShaderProgram.hpp"
#include "SimpleSwingShaderProgram.hpp"


class ShaderProgramHandler 
{
    SimpleShaderProgram* _simpleshaderprogram;
    SimpleLightingShaderProgram* _simplelightingshaderprogram;
    SimpleSwingShaderProgram* _simpleswingshaderprogram;
    
    std::string getFileAsString(std::string filepath);
    
public:
    void Initialize();
    
    
    SimpleShaderProgram* AddSimpleShaderProgram(std::string vertexshader, std::string fragmentshader);
    SimpleLightingShaderProgram* AddSimpleLightingShaderProgram(std::string vertexshader, std::string fragmentshader);
    SimpleSwingShaderProgram* AddSimpleSwingShaderProgram(std::string vertexshader, std::string fragmentshader);

    
    SimpleShaderProgram* GetSimpleShaderProgram();
    SimpleLightingShaderProgram* GetSimpleLightingShaderProgram();
};



#endif /* ShaderProgramHandler_hpp */
