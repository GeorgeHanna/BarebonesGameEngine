//
//  Physics2DContactListener.hpp
//  GameEngineX
//
//  Created by George Hanna on 29/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Physics2DContactListener_hpp
#define Physics2DContactListener_hpp

#include <stdio.h>
#include <vector>
#include <Box2D.h>
#include "../Subject.hpp"

struct Contact
{
    b2Fixture* A;
    b2Fixture* B;
    
    b2Vec2 normal;
    b2Vec2 point;
    
    float collisionForce;
    
    bool operator==(const Contact& otherC)const
    {
        return (A == otherC.A) && (B == otherC.B);
    }
};

class Physics2DContactListener : public b2ContactListener{
private:
    Subject<Contact*> _collisionEvent;

public:
    std::vector<Contact> contacts_vec;
    
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact * contact, const b2Manifold* oldManifold);
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
    virtual void AddCollisionEventListener(std::function<void(Contact*)> eventfunction)
    {
        _collisionEvent += eventfunction;
    };
    
};

#endif /* Physics2DContactListener_hpp */
