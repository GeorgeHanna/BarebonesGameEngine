//
//  Game.hpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#include "Entity.hpp"
#include "Camera.hpp"
#include "Camera/CameraPointsFollowComponent.hpp"
#include "Timer.hpp"
//test graphics
#include "TransformationMatrixStack.hpp"
#include "BeamsGame.hpp"


namespace Game
{
    class Game {
        
    public:
        CameraPtr _maincamera;
        Timer* _maintimer;
        Entity _game;
        
        Game();
        void Initialize();
        void Update(float elapsedtime);
        void Draw();
        void Loop();
    };
    
    void Instantiate(Entity* entity);
    void Destroy(Entity* entity);
    void Destroy(Component* component);
}

#endif /* Game_hpp */
