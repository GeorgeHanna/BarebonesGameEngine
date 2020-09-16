//
//  2DPhysicsWorldComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 29/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PhysicsWorld2DComponent_hpp
#define PhysicsWorld2DComponent_hpp

#include <stdio.h>

#include "../Component.hpp"

#include <Box2D.h>
#include "Physics2DContactListener.hpp"

class PhysicsWorld2DComponent : public Component {

public:
    b2World* _world;
    Physics2DContactListener* _collisionlistener;
    int _stepquality;
    b2Vec2 _gravity;
    
    void Initialize();
    void Update(Timer* timer);
    
    b2Body* AddPhysicsBody(b2BodyDef* bodydef, std::vector<b2FixtureDef> fixtures);
    void RemovePhysicsBody(b2Body* physicsbody);
    
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

typedef std::shared_ptr<PhysicsWorld2DComponent> PhysicsWorld2DComponentPtr;

#endif /* PhysicsWorld2DComponent_hpp */
