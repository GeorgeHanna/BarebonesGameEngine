//
//  TileHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef TileHandlerComponent_hpp
#define TileHandlerComponent_hpp

#include <stdio.h>
#include "../Common/stringhelpers.h"
#include "TileComponent.hpp"
#include "BeamComponent.hpp"

namespace Beams {
    class TileHandlerComponent : public Component
    {
    private:
        std::vector<TileComponentPtr> tiles;
        std::vector<BeamComponentPtr> beams;
        
    public:
        int rows;
        int columns;
        
        void Initialize();
        void Update(Timer* timer);
        
        void SendBeam(TileComponentPtr fromtile, glm::vec2 direction);
        
        void SendBeamsFromStart();

        void CreateTileBoardFromFile(std::string filepath);
        
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
    typedef std::shared_ptr<TileHandlerComponent> TileHandlerComponentPtr;
}

#endif /* TileHandlerComponent_hpp */
