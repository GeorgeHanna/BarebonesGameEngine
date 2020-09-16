//
//  PhysicsBody2DPolygonComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 31/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PhysicsBody2DPolygonComponent_hpp
#define PhysicsBody2DPolygonComponent_hpp

#include <stdio.h>
#include <string>
#include "PhysicsBody2DComponent.hpp"

class PhysicsBody2DPolygonComponent : public PhysicsBody2DComponent {
    
public:
    std::string _meshname;
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
typedef std::shared_ptr<PhysicsBody2DPolygonComponent> PhysicsBody2DPolygonComponentPtr;
#endif /* PhysicsBody2DPolygonComponent_hpp */
