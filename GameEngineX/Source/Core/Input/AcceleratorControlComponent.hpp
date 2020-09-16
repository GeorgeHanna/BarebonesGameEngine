//
//  AcceleratorControlComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 25/08/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef AcceleratorControlComponent_hpp
#define AcceleratorControlComponent_hpp

#include <stdio.h>
#include "Component.hpp"
#include "PhysicsBody2DCircleComponent.hpp"
#include "InputHandler.hpp"

class AcceleratorControlComponent : public Component
{
private:
    PhysicsBody2DCircleComponentPtr _body;
    
public:
    
    void Initialize();
    void Update(Timer* timer);
    
    void OnAcceleratorX(InputHandler::InputRange* range);
    void OnAcceleratorY(InputHandler::InputRange* range);
    
    static unsigned int GetType_s()
    {
        static char type;
        void* adr = (void*)&type;
        return (uintptr_t)adr;
    };
    
    unsigned int GetType() const
    {
        return GetType_s();
    };
};
typedef std::shared_ptr<AcceleratorControlComponent> AcceleratorControlComponentPtr;
#endif /* AcceleratorControlComponent_hpp */
