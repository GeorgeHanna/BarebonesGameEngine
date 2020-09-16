//
//  CameraPointsFollowComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 22/08/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef CameraPointsFollowComponent_hpp
#define CameraPointsFollowComponent_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Camera.hpp"

typedef struct
{
    glm::vec3 _point;
    float _time;
}CameraFollowPoint;


class CameraPointsFollowComponent : public Component
{
private:
    float _elapsedtime;
    CameraPtr _camera;
    glm::vec3 _prevpoint;
    
    #define degreesToRadians(x) x*(3.141592f/180.0f)
    glm::vec3 tween(glm::vec3 start, glm::vec3 end, float tweenfactor);
    
public:
    std::vector<CameraFollowPoint> _camerapoints;
    int _currentpointindex;
    bool _smooth;
    
    void Initialize();
    void Update(Timer* timer);
    
    
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

typedef std::shared_ptr<CameraPointsFollowComponent> CameraPointsFollowComponentPtr;


#endif /* CameraPointsFollowComponent_hpp */
