//
//  AnimationComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 17/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef AnimationComponent_hpp
#define AnimationComponent_hpp

#include <stdio.h>
#include "SpriteRenderComponent.hpp"

class AnimationComponent : public SpriteRenderComponent
{
private:
    int _currentframe;
    int _currentoffsetx;
    int _currentoffsety;
    
    void SetupAnimationMesh();
        
public:
    int _offsetx;
    int _offsety;
    int _framewidth;
    int _frameheight;
    int _nrframes;
    
    bool _loop;
    
    float _duration;
    float _timeelapsed;

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
typedef std::shared_ptr<AnimationComponent> AnimationComponentPtr;
#endif /* AnimationComponent_hpp */
