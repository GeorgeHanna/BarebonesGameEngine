//
//  PhysicsWorld2DComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 29/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "PhysicsWorld2DComponent.hpp"

void PhysicsWorld2DComponent::Initialize()
{
    _stepquality = 32;
    
    _collisionlistener = new Physics2DContactListener();
    
    // Create a world
    _world = new b2World(_gravity);
    
    _world->SetContactListener(_collisionlistener);
}
void PhysicsWorld2DComponent::Update(Timer* timer)
{
    _world->Step(timer->_dt, _stepquality, _stepquality);
}

void PhysicsWorld2DComponent::RemovePhysicsBody(b2Body *physicsbody)
{
    _world->DestroyBody(physicsbody);
}