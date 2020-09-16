//
//  AcceleratorControlComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 25/08/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "AcceleratorControlComponent.hpp"

void AcceleratorControlComponent::Initialize()
{
    _body = std::dynamic_pointer_cast<PhysicsBody2DCircleComponent>(_parent->_components[PhysicsBody2DCircleComponent::GetType_s()]);
    InputHandler::AddMoveXEventListener(std::bind(&AcceleratorControlComponent::OnAcceleratorX, this, std::placeholders::_1));
    InputHandler::AddMoveYEventListener(std::bind(&AcceleratorControlComponent::OnAcceleratorY, this, std::placeholders::_1));
}

void AcceleratorControlComponent::Update(Timer *timer)
{
    
}

void AcceleratorControlComponent::OnAcceleratorX(InputHandler::InputRange *range)
{
    _body->_body->ApplyForce(b2Vec2(range->_range*20,0), _body->_body->GetWorldCenter(), true);
}

void AcceleratorControlComponent::OnAcceleratorY(InputHandler::InputRange *range)
{
    _body->_body->ApplyForce(b2Vec2(0,range->_range*20), _body->_body->GetWorldCenter(), true);
}