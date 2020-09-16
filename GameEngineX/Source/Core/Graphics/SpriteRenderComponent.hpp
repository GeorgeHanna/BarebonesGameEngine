//
//  SpriteRenderComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef SpriteRenderComponent_hpp
#define SpriteRenderComponent_hpp

#include <stdio.h>
#include <iostream>
#include "../Component.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resources.hpp"

class SpriteRenderComponent : public Component
{
protected:
    SimpleShaderProgram* _shaderprogram;
public:
    MeshPtr _mesh;
    TexturePtr _texture;
    TexturePtr _normalmap;
    glm::vec4 _color;
    std::string _texturename;
    std::string _normalmapname;
    std::string _meshname;
    void Initialize();
    void Draw();
    
    SpriteRenderComponent();
    
    static unsigned int GetType_s()
    {
        static char type;
        void* adr = (void*)&type;
        return (uintptr_t)adr;
    };
    
    
    unsigned int GetType() const
    {
        return GetType_s();
    };
};

typedef std::shared_ptr<SpriteRenderComponent> SpriteRenderComponentPtr;

#endif /* SpriteRenderComponent_hpp */
