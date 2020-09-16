//
//  BeamComponent.hpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef BeamComponent_hpp
#define BeamComponent_hpp

#include <stdio.h>
#include "Component.hpp"
#include "SpriteRenderComponent.hpp"

namespace Beams {
    class BeamComponent : public Component
    {
    private:
        float elapsedtime;

    public:
        bool moving;
        float timetodestination;
        glm::vec2 movementdir;
        glm::vec3 startpos;
        glm::vec3 endpos;
        
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
    typedef std::shared_ptr<BeamComponent> BeamComponentPtr;
}

#endif /* BeamComponent_hpp */
