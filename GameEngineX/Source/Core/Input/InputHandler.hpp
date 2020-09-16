//
//  InputHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <stdio.h>
#include "glm.hpp"
#include "../Subject.hpp"

namespace InputHandler
{
    struct InputPosition
    {
        glm::vec2 _position;
    };
    
    struct InputRange
    {
        float _range;
    };
    
    class InputHandler
    {
    private:
        Subject<InputRange*> _lookxevent;
        Subject<InputRange*> _lookyevent;
        Subject<InputRange*> _movexevent;
        Subject<InputRange*> _moveyevent;
        Subject<InputRange*> _zoomevent;
        //Change names later
        Subject<InputPosition*> _pressdownevent;
        Subject<InputPosition*> _pressupevent;
        
    public:
        
        /*
        void SetPressDown(glm::vec2 position)
        {
            
        }
        void SetPressUp(bool active, glm::vec2 position)
        {
            
        }
         */
        void SetLookXRange(float range)
        {
            InputRange lookx = {range};
            _lookxevent.notify(&lookx);
        }
        void SetLookYRange(float range)
        {
            InputRange looky = {range};
            _lookyevent.notify(&looky);
        }
        void SetZoomRange(float range)
        {
            InputRange zoom = {range};
            _zoomevent.notify(&zoom);
        }
        
        void SetMoveXRange(float range)
        {
            InputRange movex = {range};
            _movexevent.notify(&movex);
        }
        void SetMoveYRange(float range)
        {
            InputRange movex = {range};
            _movexevent.notify(&movex);
        }
        
        void SetPressDownPosition(glm::vec2 position)
        {
            InputPosition pressdown = {position};
            _pressdownevent.notify(&pressdown);
        }
        void SetPressUpPosition(glm::vec2 position)
        {
            InputPosition pressup = {position};
            _pressupevent.notify(&pressup);
        }
        
        // Add event listeners
        void AddMoveXEventListener(std::function<void(InputRange*)> eventfunction);
        void AddMoveYEventListener(std::function<void(InputRange*)> eventfunction);
        void AddLookXEventListener(std::function<void(InputRange*)> eventfunction);
        void AddLookYEventListener(std::function<void(InputRange*)> eventfunction);
        void AddZoomEventListener(std::function<void(InputRange*)> eventfunction);
        void AddPressDownEventListener(std::function<void(InputPosition*)> eventfunction);
        void AddPressUpEventListener(std::function<void(InputPosition*)> eventfunction);

        
        void AddPositionInputEventListener(Subject<InputPosition*> &subject, std::function<void(InputPosition*)> eventfunction);
        
        void AddRangeInputEventListener(Subject<InputRange*> &subject, std::function<void(InputRange*)> eventfunction);
    };
    
    void Initialize();
    InputHandler* GetInputHandler();
    
    // Add event listeners
    void AddMoveXEventListener(std::function<void(InputRange*)> eventfunction);
    void AddMoveYEventListener(std::function<void(InputRange*)> eventfunction);
    void AddLookXEventListener(std::function<void(InputRange*)> eventfunction);
    void AddLookYEventListener(std::function<void(InputRange*)> eventfunction);
    void AddZoomEventListener(std::function<void(InputRange*)> eventfunction);
    void AddPressDownEventListener(std::function<void(InputPosition*)> eventfunction);
    void AddPressUpEventListener(std::function<void(InputPosition*)> eventfunction);

}

#endif /* InputHandler_hpp */
