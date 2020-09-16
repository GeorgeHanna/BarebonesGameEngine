//
//  SpriteLightRenderComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 02/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef SpriteLightRenderComponent_hpp
#define SpriteLightRenderComponent_hpp

#include <stdio.h>
#include "SpriteRenderComponent.hpp"

class SpriteLightRenderComponent : public SpriteRenderComponent
{
protected:
    SimpleLightingShaderProgram* _lightshaderprogram;
public:
    void Initialize();
    void Draw();
    
    void Collided(Contact* contact);
    
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
typedef std::shared_ptr<SpriteLightRenderComponent> SpriteLightRenderComponentPtr;
#endif /* SpriteLightRenderComponent_hpp */
