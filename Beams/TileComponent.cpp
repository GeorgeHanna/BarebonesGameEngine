//
//  TileComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "TileComponent.hpp"

namespace Beams {
    void TileComponent::Initialize()
    {
        SpriteRenderComponentPtr sprite = SpriteRenderComponentPtr(new SpriteRenderComponent());
        sprite->_texturename = "Empty.png";
        sprite->_meshname = "testplane.obj";
        spriterenderer = sprite;
        _parent->AddComponent(sprite);
        
    }
    
    void TileComponent::Update(Timer *timer)
    {
        if(tiletype == Tiletype::empty)
            spriterenderer->_color = {0,0,0,1};
        if(tiletype == Tiletype::startbeam)
            spriterenderer->_color = {1,0,0,1};
        else if(tiletype == Tiletype::endbeam)
            spriterenderer->_color = {0,0,1,1};
        else if(tiletype == Tiletype::reflectbeam)
            spriterenderer->_color = {0,1,1,1};
        else if(tiletype == Tiletype::reflectbeamswitch)
            spriterenderer->_color = {1,1,0,1};
    }
}