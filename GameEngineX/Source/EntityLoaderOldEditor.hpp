//
//  EntityLoaderOldEditor.hpp
//  GameEngineX
//
//  Created by George Hanna on 18/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef EntityLoaderOldEditor_hpp
#define EntityLoaderOldEditor_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

#include "Entity.hpp"
#include "PhysicsBody2DEdgeShapeComponent.hpp"
#include "PhysicsBody2DCircleComponent.hpp"
#include "SpriteRenderComponent.hpp"
#include "AnimationComponent.hpp"
#include "PlayerComponent.hpp"
#include "Resources.hpp"

typedef struct {
    std::string id;
    std::string texturename;
}ActorInfo;

//load entities
//------------------------
Entity* LoadGame();
Entity* LoadKindler(const std::string& kindlerinfo);
Entity* LoadSwingingMushrooms(const std::string& mushroominfo);
Entity* LoadGround(const std::string& groundinfo);
Entity* LoadSprite(const std::string& spriteinfo);
Entity* LoadAnimation(const std::string& animationinfo);
//load entities end
//-------------------------


#endif /* EntityLoaderOldEditor_hpp */
