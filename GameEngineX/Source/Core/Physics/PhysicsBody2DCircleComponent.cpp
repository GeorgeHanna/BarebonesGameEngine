//
//  PhysicsBody2DCircleComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 31/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "PhysicsBody2DCircleComponent.hpp"

void PhysicsBody2DCircleComponent::Initialize()
{
    
    b2CircleShape circle;
    circle.m_radius = (_radius);
    
    b2FixtureDef circlefixturedef;
    circlefixturedef.shape = &circle;
    circlefixturedef.friction = _friction;
    circlefixturedef.density = _density;
    circlefixturedef.restitution = _restitution;
    circlefixturedef.userData = this;
    
    
    _bodydef.type = _bodytype;
    _bodydef.position = b2Vec2(_parent->_transformation._position.x, _parent->_transformation._position.y);
    
    _body = Resources::GetPhysicsWorld("1")->_world->CreateBody(&_bodydef);
    _body->CreateFixture(&circlefixturedef);
}

void PhysicsBody2DCircleComponent::Update(Timer* timer)
{
    b2Transform bodytransform = _body->GetTransform();
    b2Vec2 worldpos = bodytransform.p;
    _parent->_transformation._position.x = worldpos.x;
    _parent->_transformation._position.y = worldpos.y;
    if(_bodytype == b2BodyType::b2_dynamicBody)
        _parent->_transformation._rotation = glm::rotate(glm::quat(), bodytransform.q.GetAngle(), glm::vec3(0,0,1));
}

void PhysicsBody2DCircleComponent::Draw()
{
    
    //printf("\nentity1 posx = %f, posy = %f", _parent->_transformation._position.x, _parent->_transformation._position.y);
}