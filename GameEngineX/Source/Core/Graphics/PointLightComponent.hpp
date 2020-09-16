//
//  PointLightComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 26/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef PointLightComponent_hpp
#define PointLightComponent_hpp

#include <stdio.h>
#include "BaseLightComponent.hpp"

class PointLightComponent : public BaseLight
{
public:
    float _size;
    
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
typedef std::shared_ptr<PointLightComponent> PointLightComponentPtr;
#endif /* PointLightComponent_hpp */
