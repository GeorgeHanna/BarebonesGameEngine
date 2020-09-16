//
//  PhysicsBody2DCircleComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 31/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PhysicsBody2DCircleComponent_hpp
#define PhysicsBody2DCircleComponent_hpp

#include <stdio.h>
#include "PhysicsBody2DComponent.hpp"

class PhysicsBody2DCircleComponent : public PhysicsBody2DComponent {
    
public:
    float _radius;
    void Initialize();
    void Update(Timer* timer);
    void Draw();
    
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
typedef std::shared_ptr<PhysicsBody2DCircleComponent> PhysicsBody2DCircleComponentPtr;
#endif /* PhysicsBody2DCircleComponent_hpp */
