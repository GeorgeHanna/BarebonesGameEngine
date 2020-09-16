//
//  BaseLightComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 26/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef BaseLightComponent_hpp
#define BaseLightComponent_hpp

#include <stdio.h>
#include "glm.hpp"
#include "../Component.hpp"

class BaseLight : public Component
{
public:
    glm::vec3 _color;
};

#endif /* BaseLightComponent_hpp */
