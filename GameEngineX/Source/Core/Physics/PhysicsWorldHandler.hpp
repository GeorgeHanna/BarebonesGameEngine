//
//  PhysicsWorldHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 30/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PhysicsWorldHandler_hpp
#define PhysicsWorldHandler_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "PhysicsWorld2DComponent.hpp"

class PhysicsWorldHandler {
    
public:
    std::map<std::string, PhysicsWorld2DComponentPtr> _physicsworlds;
    
    void Initialize();
    PhysicsWorld2DComponentPtr AddPhysicsWorld(std::string physicsworldname, PhysicsWorld2DComponentPtr physicsworld);
    PhysicsWorld2DComponentPtr GetPhysicsWorld(std::string physicsworldname);
};






#endif /* PhysicsWorldHandler_hpp */
