//
//  SpriteSwingRenderComponent.hpp
//  GameEngineX
//
//  Created by Stefan Söderberg on 2016-07-17.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef SpriteSwingRenderComponent_hpp
#define SpriteSwingRenderComponent_hpp

#include <stdio.h>
#include "SpriteRenderComponent.hpp"
#include "SimpleSwingShaderProgram.hpp"
class SpriteSwingRenderComponent : public SpriteRenderComponent
{
private:
    float offset;
    
    float time, bend, speed;
    bool expand, sync, reverse;
    
protected:
    SimpleSwingShaderProgram* _lightshaderprogram;
    
public:
    SpriteSwingRenderComponent(float theBendFactor, float theSpeed, bool willExpand, bool inSync, bool reverseBend);
    void Initialize();
    void Draw();
    void Update(Timer* timer);
    
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
typedef std::shared_ptr<SpriteSwingRenderComponent> SpriteSwingRenderComponentPtr;
#endif /* SpriteSwingRenderComponent_hpp */
