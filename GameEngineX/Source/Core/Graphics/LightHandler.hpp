//
//  LightHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 27/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef LightHandler_hpp
#define LightHandler_hpp

#include <stdio.h>
#include <vector>
#include "PointLightComponent.hpp"
#include "DirectionalLightComponent.hpp"

class LightHandler
{
    DirectionalLightComponentPtr _directionallight;
    std::vector<PointLightComponentPtr> _pointlights;
public:
    void SetDirectionalLight(DirectionalLightComponentPtr directionallight);
    DirectionalLightComponentPtr GetDirectionalLight();
    
    std::vector<PointLightComponentPtr> GetPointLights();
    void AddPointLight(PointLightComponentPtr pointlight);
    
    std::vector<float> GetDirectionalLightDirection();
    std::vector<float> GetDirectionalLightColor();
    float GetDirectionalLightAmbient();
    
    std::vector<float> GetPointLightPositions();
    std::vector<float> GetPointLightColors();
    std::vector<float> GetPointLightSizes();
    
    void Initialize();
};


#endif /* LightHandler_hpp */
