//
//  Camera.hpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Input/InputHandler.hpp"


class Camera : public Component
{
public:
    float _fov;
    float _aspectratio;
    float _nearclipping;
    float _farclipping;
    float _screenwidth;
    float _screenheight;
    glm::vec3 _forward;
    glm::vec3 _right;
    glm::vec3 _up;
    glm::mat4x4 _projection;
    glm::mat4x4 _view;
    
    void Initialize();
    void Draw();
    void Update(Timer* timer);
    
    void OnLookX(InputHandler::InputRange* range);
    void OnLookY(InputHandler::InputRange* range);
    void OnZoom(InputHandler::InputRange* range);
    
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
typedef std::shared_ptr<Camera> CameraPtr;
#endif /* Camera_hpp */
