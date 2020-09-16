//
//  BeamsGame.cpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "BeamsGame.hpp"

namespace Beams{
    Entity* BeamsGame::CreateGame(int framewidth, int frameheight)
    {
        framew = framewidth;
        frameh = frameheight;
        
        Entity* game = new Entity();
        //game->_transformation._scale.x = 1.0f/5.0f;
        //game->_transformation._scale.y = (1.0f/5.0f)*((float)framewidth/(float)frameheight);
        
        Entity* tilehandler = new Entity();
        tilehandlercomponent = TileHandlerComponentPtr(new TileHandlerComponent());
        tilehandler->AddComponent(tilehandlercomponent);
        
        tilehandlercomponent->CreateTileBoardFromFile(Resources::GetRootPath() + "/level1");
        tilehandler->_transformation._scale.x = 1.0f/tilehandlercomponent->columns;
        tilehandler->_transformation._scale.y = 0.8f/tilehandlercomponent->rows;
        tilehandler->_transformation._position.y = 0;
        
        game->AddEntity(tilehandler);
        
        tilehandlercomponent->SendBeamsFromStart();
        
        return game;
    }
}