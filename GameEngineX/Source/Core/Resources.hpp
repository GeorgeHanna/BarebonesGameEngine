//
//  Resources.hpp
//  GameEngineX
//
//  Created by George Hanna on 26/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Resources_hpp
#define Resources_hpp

#include <stdio.h>
#include <string>
#include "Graphics/ShaderProgramHandler.hpp"
#include "Graphics/MeshHandler.hpp"
#include "Graphics/TextureHandler.hpp"
#include "Physics/PhysicsWorldHandler.hpp"
#include "Graphics/LightHandler.hpp"


namespace Resources {
    
    

    void Initialize(std::string resourceroot);
    
    SimpleShaderProgram* AddSimpleShaderProgram(std::string vertshader, std::string fragshader);
    SimpleLightingShaderProgram* AddSimpleLightingShaderProgram(std::string vertshader, std::string fragshader);
    SimpleShaderProgram* GetSimpleShaderProgram();
    SimpleLightingShaderProgram* GetSimpleLightingShaderProgram();
    SimpleSwingShaderProgram* AddSimpleSwingShaderProgram(std::string vertshader, std::string fragshader);

    
    TexturePtr GetTexture(std::string texturename);
    
    MeshPtr GetMesh(std::string meshname);
    
    PhysicsWorld2DComponentPtr AddPhysicsWorld(std::string physicsworldname, PhysicsWorld2DComponentPtr physicsworld);
    PhysicsWorld2DComponentPtr GetPhysicsWorld(std::string physicsworldname);
    
    LightHandler* GetLightHandler();
    
    Entity* LoadGameOldEditor();
    
    std::string GetRootPath();
    std::string CombinePath(std::string a, std::string b);
}

#endif /* Resources_hpp */
