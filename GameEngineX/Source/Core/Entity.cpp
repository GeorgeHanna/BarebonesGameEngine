//
//  Entity.cpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Entity.hpp"
#include "Component.hpp"

Entity::Entity()
{
    _transformation._scale = glm::vec3(1.0f,1.0f,1.0f);
    _initialized = false;
}
Entity::~Entity()
{
    _components.clear();

    for(Entity* e : _entities) {
        delete e;
        e = nullptr;
    }
    _entities.clear();


}

//Initialize the Components in the Entity, then Initialize the children
void Entity::Initialize()
{
    if(_initialized)
        return;
    _initialized = true;
    for(std::map<unsigned int, ComponentPtr>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        (*it).second->Initialize();
    }
    
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        (*it)->Initialize();
    }
}

void Entity::Start()
{
    for(std::map<unsigned int, ComponentPtr>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        (*it).second->Start();
    }
    
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        (*it)->Start();
    }
}

void Entity::Update(Timer* timer)
{
    _transformation.PushTransformation();

    for(std::map<unsigned int, ComponentPtr>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        (*it).second->Update(timer);
    }
    
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        (*it)->Update(timer);
    }

    _transformation.PopTransformation();
}

void Entity::Draw()
{

    for(std::map<unsigned int, ComponentPtr>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        (*it).second->Draw();
    }
    
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        (*it)->Draw();
    }
    
}

void Entity::Destroy()
{
    for(std::map<unsigned int, ComponentPtr>::iterator it = _components.begin(); it != _components.end(); ++it)
    {
        (*it).second->Destroy();
    }
    
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        (*it)->Destroy();
    }
}

void Entity::AddComponent(ComponentPtr component)
{
    _components[component->GetType()] = component;
    component->_parent = this;
    if(_initialized)
        component->Initialize();
}
void Entity::AddEntity(Entity *entity)
{
    _entities.push_back(entity);
    entity->_parent = this;
    entity->Initialize();
}

std::vector<Entity*> Entity::GetEntitiesWithComponent(const unsigned int componenttype)
{
    std::vector<Entity*> entitieswithcomponent;
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        if((*it)->_components.find(componenttype) != (*it)->_components.end())
            entitieswithcomponent.push_back((*it));
    }
    
    return entitieswithcomponent;
}
std::vector<Entity*> Entity::GetEntitiesWithComponentRecursive(const unsigned int componenttype)
{
    std::vector<Entity*> entitieswithcomponent;
    for(std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
        std::vector<Entity*> entitieswithcomponentinchild;
        entitieswithcomponentinchild = (*it)->GetEntitiesWithComponentRecursive(componenttype);
        for (int i = 0; i<entitieswithcomponentinchild.size(); i++) {
            entitieswithcomponent.push_back(entitieswithcomponentinchild[i]);
        }
        if((*it)->_components.find(componenttype) != (*it)->_components.end())
            entitieswithcomponent.push_back((*it));
    }
    
    return entitieswithcomponent;
}
