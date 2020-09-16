//
//  TileComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef TileComponent_hpp
#define TileComponent_hpp

#include <stdio.h>
#include "Component.hpp"
#include "SpriteRenderComponent.hpp"

namespace Beams {
    
    enum Tiletype { empty, obstacle, startbeam, endbeam, reflectbeam, reflectbeamswitch, splitbeam };
    
    class TileComponent : public Component
    {
    public:
        Tiletype tiletype;
        SpriteRenderComponentPtr spriterenderer;
        void Initialize();
        void Update(Timer* timer);
        
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
    typedef std::shared_ptr<TileComponent> TileComponentPtr;
}


#endif /* TileComponent_hpp */
