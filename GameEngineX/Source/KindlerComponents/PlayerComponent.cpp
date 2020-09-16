//
//  PlayerComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 18/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "PlayerComponent.hpp"

void PlayerComponent::Initialize()
{
    _playerphysics = std::static_pointer_cast<PhysicsBody2DCircleComponent>(_parent->_components[PhysicsBody2DCircleComponent::GetType_s()]);
    Resources::GetPhysicsWorld("1")->_collisionlistener->AddCollisionEventListener(std::bind(&PlayerComponent::OnCollision, this, std::placeholders::_1));
    InputHandler::AddPressDownEventListener(std::bind(&PlayerComponent::OnPressDown, this, std::placeholders::_1));
    InputHandler::AddPressUpEventListener(std::bind(&PlayerComponent::OnPressUp, this, std::placeholders::_1));
}

void PlayerComponent::Update(Timer *timer)
{
    Component::Update(timer);
    
}

void PlayerComponent::OnCollision(Contact *contact)
{
    
}

void PlayerComponent::OnPressDown(InputHandler::InputPosition *position)
{
    _startpos = position->_position;
    //printf("Press down - x:%f, y:%f", _startpos.x,_startpos.y);
}
void PlayerComponent::OnPressUp(InputHandler::InputPosition *position)
{
    _endpos = position->_position;
    glm::vec2 delta = _startpos-_endpos;
    _playerphysics->_body->ApplyForce({-delta.x,delta.y}, _playerphysics->_body->GetWorldCenter(), true);
    //printf("Press up - x:%f, y:%f", _endpos.x,_endpos.y);
}