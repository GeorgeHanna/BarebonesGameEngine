//
//  Physics2DContactListener.cpp
//  GameEngineX
//
//  Created by George Hanna on 29/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Physics2DContactListener.hpp"


void Physics2DContactListener::BeginContact(b2Contact *contact)
{
    b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);
    
    
    Contact _contact = {contact->GetFixtureA(), contact->GetFixtureB(), worldManifold.normal, worldManifold.points[0]};
    contacts_vec.push_back(_contact);
    
    _collisionEvent.notify(&_contact);
}
void Physics2DContactListener::EndContact(b2Contact *contact)
{
    Contact _contact = {contact->GetFixtureA(), contact->GetFixtureB()};
    std::vector<Contact>::iterator position;
    position = std::find(contacts_vec.begin(),contacts_vec.end(),_contact);
    if(position!=contacts_vec.end())
        contacts_vec.erase(position);
}
void Physics2DContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    
}
void Physics2DContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    Contact _contact = {contact->GetFixtureA(), contact->GetFixtureB()};
    std::vector<Contact>::iterator position = std::find(contacts_vec.begin(),contacts_vec.end(),_contact);
    position->collisionForce = impulse->normalImpulses[0];
}