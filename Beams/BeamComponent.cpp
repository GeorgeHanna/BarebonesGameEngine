//
//  BeamComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "BeamComponent.hpp"

namespace Beams{
    
    void BeamComponent::Initialize()
    {
        SpriteRenderComponentPtr sprite = SpriteRenderComponentPtr(new SpriteRenderComponent());
        sprite->_texturename = "Empty.png";
        sprite->_meshname = "testplane.obj";
        sprite->_color = {1,1,1,1};
        _parent->AddComponent(sprite);
        startpos = _parent->_transformation._position;
        endpos = _parent->_transformation._position;
        endpos += glm::vec3(movementdir.x, movementdir.y, 0);
        elapsedtime = 0;
        moving = true;
        _parent->_transformation._scale = {0.1,0.1,1};
    }
    
    void BeamComponent::Update(Timer *timer)
    {
        elapsedtime += timer->_dt;
        
        float lerpfactor = elapsedtime/timetodestination;
        
        if(lerpfactor >= 1)
            lerpfactor = 1;
        
        if(moving)
        {
            _parent->_transformation._position = (startpos * (1.0f-lerpfactor*0.5f) + (lerpfactor*0.5f)*endpos);

            if(movementdir.x != 0)
            {
                _parent->_transformation._scale.x = lerpfactor;
            }
            else if(movementdir.y != 0)
            {
                _parent->_transformation._scale.y = lerpfactor;
            }
            
            if(lerpfactor == 1)
                moving = false;
        }

    }
}