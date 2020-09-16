//
//  PhysicsBody2DEdgeShapeComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 15/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "PhysicsBody2DEdgeShapeComponent.hpp"


void PhysicsBody2DEdgeShapeComponent::Initialize()
{
    std::vector<b2Vec2> vertices;
    MeshPtr mesh = Resources::GetMesh(_meshname);
    
    for (int i = 0; i < mesh->_vertices.size(); i++) {
        vertices.push_back({mesh->_vertices[i]._position[0], mesh->_vertices[i]._position[1]});
    }
    
    _bodydef.type = _bodytype;
    _bodydef.position = b2Vec2(_parent->_transformation._position.x, _parent->_transformation._position.y);
    
    
    _body = Resources::GetPhysicsWorld("1")->_world->CreateBody(&_bodydef);

    for (int i = 0; i < vertices.size()-1; i++) {
        
        b2EdgeShape edgeshape;
        b2Vec2 pos1 = vertices[i];
        b2Vec2 pos2 = vertices[i+1];
        
        edgeshape.Set(pos1, pos2);
        if(i==0)
        {
            edgeshape.m_hasVertex3 = true;
            edgeshape.m_vertex3 = vertices[i+2];
        }
        else if(i < vertices.size() - 2)
        {
            edgeshape.m_hasVertex0 = true;
            edgeshape.m_hasVertex3 = true;
            edgeshape.m_vertex0 = vertices[i-1];
            edgeshape.m_vertex3 = vertices[i+2];
        }
        else
        {
            edgeshape.m_hasVertex0 = true;
            edgeshape.m_vertex0 = vertices[i-1];
        }
        
        b2FixtureDef edgeshapefixturedef;
        edgeshapefixturedef.shape = &edgeshape;
        edgeshapefixturedef.friction = _friction;
        edgeshapefixturedef.density = _density;
        edgeshapefixturedef.restitution = _restitution;
        edgeshapefixturedef.userData = this;
        
        _body->CreateFixture(&edgeshapefixturedef);
        
    }
    //if(_bodytype == b2BodyType::b2_staticBody)
      //  _body->SetTransform(_body->GetWorldCenter(), _parent->_transformation._rotation.w);
}

void PhysicsBody2DEdgeShapeComponent::Update(Timer* timer)
{
    b2Transform bodytransform = _body->GetTransform();
    b2Vec2 worldpos = bodytransform.p;
    _parent->_transformation._position.x = worldpos.x;
    _parent->_transformation._position.y = worldpos.y;
    if(_bodytype == b2BodyType::b2_dynamicBody)
        _parent->_transformation._rotation = glm::rotate(glm::quat(), bodytransform.q.GetAngle(), glm::vec3(0,0,1));
}

void PhysicsBody2DEdgeShapeComponent::Draw()
{
    //printf("\nentity2 posx = %f, posy = %f", _parent->_transformation._position.x, _parent->_transformation._position.y);
}