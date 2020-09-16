//
//  Component.cpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Component.hpp"

Component::Component()
{
}
Component::~Component()
{
}
void Component::Initialize()
{
}
void Component::Start()
{
}
void Component::Update(Timer* timer)
{
    _transformation.SetupMatrices();
}
void Component::Draw()
{
    
}
void Component::Destroy()
{
}

