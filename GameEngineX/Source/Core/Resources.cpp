//
//  Resources.cpp
//  GameEngineX
//
//  Created by George Hanna on 26/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Resources.hpp"

namespace Resources {

std::string _root;

//Graphics Handlers
ShaderProgramHandler* _shaderprogramhandler;
TextureHandler* _texturehandler;
MeshHandler* _meshhandler;

//Physics Handler
PhysicsWorldHandler* _physicsworldhandler;

//Light Handler
LightHandler* _lighthandler;

void Initialize(std::string resourceroot)
{
    _root = resourceroot;
    _shaderprogramhandler = new ShaderProgramHandler();
    _texturehandler = new TextureHandler();
    _meshhandler = new MeshHandler();
    _physicsworldhandler = new PhysicsWorldHandler();
    _lighthandler = new LightHandler();

    _shaderprogramhandler->Initialize();
    _texturehandler->Initialize();
    _meshhandler->Initialize();
    _physicsworldhandler->Initialize();
    _lighthandler->Initialize();
}


    SimpleShaderProgram* AddSimpleShaderProgram(std::string vertshader, std::string fragshader)
    {
#ifdef OPEN_GL_DESKTOP
        return _shaderprogramhandler->AddSimpleShaderProgram(CombinePath(_root + "Shader", vertshader), CombinePath(_root + "Shader", fragshader));
#else
        return _shaderprogramhandler->AddSimpleShaderProgram(CombinePath(_root, vertshader), CombinePath(_root, fragshader));
#endif
    }
    SimpleLightingShaderProgram* AddSimpleLightingShaderProgram(std::string vertshader, std::string fragshader)
    {
#ifdef OPEN_GL_DESKTOP
        return _shaderprogramhandler->AddSimpleLightingShaderProgram(CombinePath(_root + "Shader", vertshader), CombinePath(_root + "Shader", fragshader));
#else
        return _shaderprogramhandler->AddSimpleLightingShaderProgram(CombinePath(_root, vertshader), CombinePath(_root, fragshader));
#endif
    }
    SimpleShaderProgram* GetSimpleShaderProgram()
    {
        return _shaderprogramhandler->GetSimpleShaderProgram();
    }
    SimpleLightingShaderProgram* GetSimpleLightingShaderProgram()
    {
        return _shaderprogramhandler->GetSimpleLightingShaderProgram();
    }
    SimpleSwingShaderProgram* AddSimpleSwingShaderProgram(std::string vertshader, std::string fragshader)
    {
        return _shaderprogramhandler->AddSimpleSwingShaderProgram(CombinePath(_root, vertshader), CombinePath(_root, fragshader));
    }
    
    TexturePtr GetTexture(std::string texturename)
    {
#ifdef OPEN_GL_DESKTOP
        return (_texturehandler->GetTexture(texturename, CombinePath(_root + "Texture", texturename)));
#else
        return (_texturehandler->GetTexture(texturename, CombinePath(_root, texturename)));
#endif
    }
    
    MeshPtr GetMesh(std::string meshname)
    {
#ifdef OPEN_GL_DESKTOP
        return _meshhandler->GetMesh(meshname, CombinePath(_root + "Mesh", meshname));
#else
        return _meshhandler->GetMesh(meshname, CombinePath(_root , meshname));
#endif
    }
    
    PhysicsWorld2DComponentPtr AddPhysicsWorld(std::string physicsworldname, PhysicsWorld2DComponentPtr physicsworld)
    {
        return _physicsworldhandler->AddPhysicsWorld(physicsworldname, physicsworld);
    }
    PhysicsWorld2DComponentPtr GetPhysicsWorld(std::string physicsworldname)
    {
        return _physicsworldhandler->GetPhysicsWorld(physicsworldname);
    }
    
    LightHandler* GetLightHandler()
    {
        return _lighthandler;
    }
    
    std::string GetRootPath()
    {
        return _root;
    }
    
    std::string CombinePath(std::string a, std::string b)
    {
        return a + "/" + b;
    }
}
