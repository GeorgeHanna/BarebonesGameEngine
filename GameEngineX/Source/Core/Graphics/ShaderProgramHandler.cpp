//
//  ShaderProgramHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "ShaderProgramHandler.hpp"



void ShaderProgramHandler::Initialize()
{
}

SimpleShaderProgram* ShaderProgramHandler::AddSimpleShaderProgram(std::string vertexshader, std::string fragmentshader)
{
    if(_simpleshaderprogram == NULL)
    {
        //Load new
        std::string vshader = getFileAsString(vertexshader);
        std::string fshader = getFileAsString(fragmentshader);
        
        _simpleshaderprogram = new SimpleShaderProgram();
        _simpleshaderprogram->CompileShaders(vshader.c_str(), fshader.c_str());
        return _simpleshaderprogram;
    }
    else
        return _simpleshaderprogram;
}

SimpleLightingShaderProgram* ShaderProgramHandler::AddSimpleLightingShaderProgram(std::string vertexshader, std::string fragmentshader)
{
    if(_simplelightingshaderprogram == NULL)
    {
        //Else load new
        std::string vshader = getFileAsString(vertexshader);
        std::string fshader = getFileAsString(fragmentshader);
        
        _simplelightingshaderprogram = new SimpleLightingShaderProgram();
        _simplelightingshaderprogram->CompileShaders(vshader.c_str(), fshader.c_str());
        return _simplelightingshaderprogram;
    }
    else
        return _simplelightingshaderprogram;
}

SimpleSwingShaderProgram* ShaderProgramHandler::AddSimpleSwingShaderProgram(std::string vertexshader, std::string fragmentshader)
{
    if(_simpleswingshaderprogram == NULL)
    {
        //Else load new
        std::string vshader = getFileAsString(vertexshader);
        std::string fshader = getFileAsString(fragmentshader);
        
        _simpleswingshaderprogram = new SimpleSwingShaderProgram();
        _simpleswingshaderprogram->CompileShaders(vshader.c_str(), fshader.c_str());
        return _simpleswingshaderprogram;
    }
    else
        return _simpleswingshaderprogram;
}

std::string ShaderProgramHandler::getFileAsString(std::string filepath)
{
    std::ifstream ifs(filepath);
    std::string fullstring( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>()    ) );
    return fullstring;
}

SimpleShaderProgram* ShaderProgramHandler::GetSimpleShaderProgram()
{
    return _simpleshaderprogram;
}

SimpleLightingShaderProgram* ShaderProgramHandler::GetSimpleLightingShaderProgram()
{
    return _simplelightingshaderprogram;
}