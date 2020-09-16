//
//  CameraPointsFollowComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 22/08/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "CameraPointsFollowComponent.hpp"

void CameraPointsFollowComponent::Initialize()
{
    _currentpointindex = 0;
    _elapsedtime = 0;
    _smooth = true;
    _camera = std::dynamic_pointer_cast<Camera>(_parent->_components[Camera::GetType_s()]);
    _prevpoint = _camera->_transformation._position;
}
void CameraPointsFollowComponent::Update(Timer* timer)
{
    _elapsedtime+=timer->_dt;
    
    
    if(_currentpointindex < _camerapoints.size())
        
    {
        
        CameraFollowPoint currentfollowpoint = _camerapoints[_currentpointindex];
        
        float lerpfactor = _elapsedtime/currentfollowpoint._time;
        
        
        if(lerpfactor < 1.0f)
            
        {
            if(_smooth)
                _camera->_transformation._position = tween(_prevpoint, currentfollowpoint._point, lerpfactor);
            else
                _camera->_transformation._position = _prevpoint * (1.0f-lerpfactor) + (lerpfactor)*currentfollowpoint._point;
            
                //a=b+(a-b)*\ \frac{\left(\cos (c\cdot 180\ +181)+1.0\right)}{2.0}
        }
        
        else
            
        {
            
            _prevpoint = _camerapoints[_currentpointindex]._point;
            
            _currentpointindex++;
            
            _elapsedtime = 0;
            
        }
        
        //printf("camposX %f, camposY %f, camposZ %f\n", _camera->_transformation._position.x,_camera->_transformation._position.y,_camera->_transformation._position.z);
    }
}

// tween should be moved to common code file
glm::vec3 CameraPointsFollowComponent::tween(glm::vec3 start, glm::vec3 end, float tweenfactor)
{
    float degrees181torad = degreesToRadians(181);
    
    float x = start.x + (end.x - start.x) * (glm::cos(tweenfactor * glm::pi<float>() + degrees181torad) + 1.0f) / 2.0;
    float y = start.y + (end.y - start.y) * (glm::cos(tweenfactor * glm::pi<float>() + degrees181torad) + 1.0f) / 2.0;
    float z = start.z + (end.z - start.z) * (glm::cos(tweenfactor * glm::pi<float>() + degrees181torad) + 1.0f) / 2.0;
    
    return {x,y,z};
}
