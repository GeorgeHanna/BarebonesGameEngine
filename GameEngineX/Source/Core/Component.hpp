//
//  Component.hpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//


#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include <memory>
#include "Transformation.hpp"
#include "Entity.hpp"
#include "Timer.hpp"


class Component {
    
public:
    Entity* _parent;
    Transformation _transformation;
    bool _active;
    bool _initialized;
    
    Component();
    virtual ~Component();
    virtual void Initialize();
    virtual void Start();
    virtual void Update(Timer* timer);
    virtual void Draw();
    virtual void Destroy();
    virtual unsigned int GetType() const = 0;
    
};
typedef std::shared_ptr<Component> ComponentPtr;
#endif /* Component_hpp */

