//
//  BeamsGame.hpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef BeamsGame_hpp
#define BeamsGame_hpp

#include <stdio.h>
#include "../Common/stringhelpers.h"
#include "TileHandlerComponent.hpp"

namespace Beams {
    class BeamsGame
    {
    private:
        int framew;
        int frameh;
        Entity* game;
        TileHandlerComponentPtr tilehandlercomponent;
        
    public:
        Entity* CreateGame(int framewidth, int frameheight);
        Entity* LoadLevel(std::string level);
    };
}

#endif /* BeamsGame_hpp */
