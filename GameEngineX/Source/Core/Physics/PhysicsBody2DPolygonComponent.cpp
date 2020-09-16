//
//  PhysicsBody2DPolygonComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 31/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "PhysicsBody2DPolygonComponent.hpp"

void PhysicsBody2DPolygonComponent::Initialize()
{
    std::vector<b2Vec2> vertices;
    MeshPtr mesh = Resources::GetMesh(_meshname);
    
    for (int i = 0; i < mesh->_vertices.size(); i++) {
        vertices.push_back({mesh->_vertices[i]._position[0], mesh->_vertices[i]._position[1]});
    }
    
    //box
    b2PolygonShape polygon;
    polygon.Set(&vertices[0], vertices.size());
    
    b2FixtureDef polygonfixturedef;
    polygonfixturedef.shape = &polygon;
    polygonfixturedef.friction = _friction;
    polygonfixturedef.density = _density;
    polygonfixturedef.restitution = _restitution;
    polygonfixturedef.userData = this;
    

    
    _bodydef.type = _bodytype;
    _bodydef.position = b2Vec2(_parent->_transformation._position.x, _parent->_transformation._position.y);
    
    _body = Resources::GetPhysicsWorld("1")->_world->CreateBody(&_bodydef);
    _body->CreateFixture(&polygonfixturedef);
    
    if(_bodytype == b2BodyType::b2_staticBody)
        _body->SetTransform(_body->GetWorldCenter(), _parent->_transformation._rotation.w);

}

void PhysicsBody2DPolygonComponent::Update(Timer* timer)
{
    b2Transform bodytransform = _body->GetTransform();
    b2Vec2 worldpos = bodytransform.p;
    _parent->_transformation._position.x = worldpos.x;
    _parent->_transformation._position.y = worldpos.y;
    if(_bodytype == b2BodyType::b2_dynamicBody)
        _parent->_transformation._rotation = glm::rotate(glm::quat(), bodytransform.q.GetAngle(), glm::vec3(0,0,1));
}

void PhysicsBody2DPolygonComponent::Draw()
{
        //printf("\nentity2 posx = %f, posy = %f", _parent->_transformation._position.x, _parent->_transformation._position.y);
}