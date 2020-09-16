//
//  LightHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 27/06/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "LightHandler.hpp"

void LightHandler::Initialize()
{
}

void LightHandler::SetDirectionalLight(DirectionalLightComponentPtr directionallight)
{
    _directionallight = directionallight;
}
DirectionalLightComponentPtr LightHandler::GetDirectionalLight()
{
    return _directionallight;
}

std::vector<PointLightComponentPtr> LightHandler::GetPointLights()
{
    return _pointlights;
}
void LightHandler::AddPointLight(PointLightComponentPtr pointlight)
{
    _pointlights.push_back(pointlight);
}

std::vector<float> LightHandler::GetDirectionalLightDirection()
{
    glm::vec3 directionallightdirection = _directionallight->_direction;
    return {directionallightdirection.x, directionallightdirection.y, directionallightdirection.z};
}
std::vector<float> LightHandler::GetDirectionalLightColor()
{
    glm::vec3 directionallightcolor = _directionallight->_color;
    return {directionallightcolor.x, directionallightcolor.y, directionallightcolor.z};
}
float LightHandler::GetDirectionalLightAmbient()
{
    return _directionallight->_ambient;
}

std::vector<float> LightHandler::GetPointLightPositions()
{
    // Inefficient to calculate this everytime anyone calls this function
    // Should be done once in each pointlight perhaps
    
    std::vector<float> pointlightpositions;
    for (int i = 0; i<_pointlights.size(); i++) {
        glm::vec4 plightpos4 = _pointlights[i]->_transformation._mmatrix * glm::vec4(_pointlights[i]->_transformation._position, 1);
        glm::vec3 plightpos3 = glm::vec3(plightpos4);
        pointlightpositions.push_back(plightpos3.x);
        pointlightpositions.push_back(plightpos3.y);
        pointlightpositions.push_back(plightpos3.z);
    }
    
    return pointlightpositions;
}
std::vector<float> LightHandler::GetPointLightColors()
{
    std::vector<float> pointlightcolors;
    for (int i = 0; i<_pointlights.size(); i++) {
        pointlightcolors.push_back(_pointlights[i]->_color.x);
        pointlightcolors.push_back(_pointlights[i]->_color.y);
        pointlightcolors.push_back(_pointlights[i]->_color.z);
    }
    
    return pointlightcolors;
}
std::vector<float> LightHandler::GetPointLightSizes()
{
    std::vector<float> pointlightsizes;
    for (int i = 0; i<_pointlights.size(); i++) {
        pointlightsizes.push_back(_pointlights[i]->_size);
    }
    
    return pointlightsizes;
}
