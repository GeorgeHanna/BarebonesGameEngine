//
//  PlayerComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 18/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PlayerComponent_hpp
#define PlayerComponent_hpp

#include <stdio.h>
#include "Component.hpp"
#include "PhysicsBody2DCircleComponent.hpp"
#include "InputHandler.hpp"

class PlayerComponent : public Component
{
private:
    glm::vec2 _startpos, _endpos;
    
public:
    PhysicsBody2DCircleComponentPtr _playerphysics;
    
    void Initialize();
    void Update(Timer *timer);
    
    void OnCollision(Contact* contact);
    void OnPressDown(InputHandler::InputPosition* position);
    void OnPressUp(InputHandler::InputPosition* position);
    
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
typedef std::shared_ptr<PlayerComponent> PlayerComponentPtr;
#endif /* PlayerComponent_hpp */
