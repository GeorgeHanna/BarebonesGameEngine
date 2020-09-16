//
//  PhysicsBody2DComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 29/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PhysicsBody2DComponent_hpp
#define PhysicsBody2DComponent_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "../Component.hpp"
#include "Box2D.h"
#include "../Resources.hpp"

class PhysicsBody2DComponent : public Component {

public:
    b2Body* _body;
    b2BodyDef _bodydef;
    b2BodyType _bodytype;
    float _friction;
    float _density;
    float _restitution;
    
    std::string _physicsworldname;
    
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
typedef std::shared_ptr<PhysicsBody2DComponent> PhysicsBody2DComponentPtr;
#endif /* PhysicsBody2DComponent_hpp */
