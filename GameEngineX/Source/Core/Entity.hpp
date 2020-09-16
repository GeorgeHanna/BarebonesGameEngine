//
//  Entity.hpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <typeinfo>
#include <memory>
#include "Transformation.hpp"
#include "Timer.hpp"

class Component;
typedef std::shared_ptr<Component> ComponentPtr;

class Entity {
public:
    Entity* _parent;
    Transformation _transformation;
    bool _active;
    bool _initialized;
    std::vector<Entity*> _entities;
    std::map<unsigned int ,ComponentPtr> _components;
    
    
    Entity();
    ~Entity();
    void Initialize();
    void Start();
    void Update(Timer* timer);
    void Draw();
    void Destroy();
        
    
    //static Component FindComponent();
    
    void AddComponent(ComponentPtr component);
    void AddEntity(Entity* entity);
    
    std::vector<Entity*> GetEntitiesWithComponent(const unsigned int componenttype);
    std::vector<Entity*> GetEntitiesWithComponentRecursive(const unsigned int componenttype);
    
};

#endif /* Entity_hpp */
