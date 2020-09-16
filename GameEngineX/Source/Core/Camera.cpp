//
//  Camera.cpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Camera.hpp"

void Camera::Initialize()
{
    _fov = glm::radians(45.0f);
    _aspectratio = _screenwidth / _screenheight;
    _nearclipping = 0.1f;
    _farclipping = 100.0f;
    
    _forward = glm::vec3(0,0,-1);
    _right = glm::vec3(1,0,0);
    _up = glm::vec3(0,1,0);
    
    _transformation._position = glm::vec3(0,0,10);
    
    //_projection = glm::perspective(_fov, _aspectratio, _nearclipping, _farclipping);
    _view = glm::lookAt(_transformation._position, _transformation._position + _forward, _up);

    
    //_projection = glm::perspective(_fov, _aspectratio, _nearclipping, _farclipping);
    _projection = glm::ortho(0.0f,1.0f,0.0f,1.0f,0.001f,100.0f);
    
    InputHandler::AddLookXEventListener(std::bind(&Camera::OnLookX, this, std::placeholders::_1));
    InputHandler::AddLookYEventListener(std::bind(&Camera::OnLookY, this, std::placeholders::_1));
    InputHandler::AddZoomEventListener(std::bind(&Camera::OnZoom, this, std::placeholders::_1));


}

void Camera::Update(Timer* timer)
{
    _view = glm::lookAt(_transformation._position, _transformation._position + _forward, _up);
    TransformationMatrixStack::SetViewMatrix(_view);
}

void Camera::Draw()
{
    
}

void Camera::OnLookX(InputHandler::InputRange* range)
{
    _transformation._position.x += range->_range / _screenwidth;
}
void Camera::OnLookY(InputHandler::InputRange* range)
{
    _transformation._position.y += range->_range / _screenheight;
}
void Camera::OnZoom(InputHandler::InputRange* range)
{
    _transformation._position.z += range->_range / _screenwidth;
}
