//
//  PhysicsWorldHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 30/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "PhysicsWorldHandler.hpp"

void PhysicsWorldHandler::Initialize()
{
}

PhysicsWorld2DComponentPtr PhysicsWorldHandler::AddPhysicsWorld(std::string physicsworldname, PhysicsWorld2DComponentPtr physicsworld)
{
    //If already loaded
    auto it = _physicsworlds.find(physicsworldname);
    if(it != _physicsworlds.end())
        return it->second;
    else
        _physicsworlds[physicsworldname] = physicsworld;
    return physicsworld;
}

PhysicsWorld2DComponentPtr PhysicsWorldHandler::GetPhysicsWorld(std::string physicsworldname)
{
    //If already loaded
    auto it = _physicsworlds.find(physicsworldname);
    if(it != _physicsworlds.end())
        return it->second;
    else
        printf((std::string("\n ERROR : Could not find PhysicsWorld") + physicsworldname).c_str());
    return NULL;
}
