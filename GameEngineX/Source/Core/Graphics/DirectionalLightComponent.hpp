//
//  DirectionalLightComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 26/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef DirectionalLightComponent_hpp
#define DirectionalLightComponent_hpp

#include <stdio.h>
#include "BaseLightComponent.hpp"

class DirectionalLightComponent : public BaseLight
{
public:
    glm::vec3 _direction;
    float _ambient;
    
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

typedef std::shared_ptr<DirectionalLightComponent> DirectionalLightComponentPtr;
#endif /* DirectionalLightComponent_hpp */
