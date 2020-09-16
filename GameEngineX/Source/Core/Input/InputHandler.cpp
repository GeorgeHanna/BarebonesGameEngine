//
//  InputHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "InputHandler.hpp"

namespace InputHandler
{
    InputHandler* _inputhandler;
    
    void Initialize()
    {
        _inputhandler = new InputHandler();
    }
    
    InputHandler* GetInputHandler()
    {
        return _inputhandler;
    }
    
    // Add event listeners
    void AddMoveXEventListener(std::function<void(InputRange*)> eventfunction)
    {_inputhandler->AddMoveXEventListener(eventfunction);}
    void AddMoveYEventListener(std::function<void(InputRange*)> eventfunction)
    {_inputhandler->AddMoveYEventListener(eventfunction);}
    void AddLookXEventListener(std::function<void(InputRange*)> eventfunction)
    {_inputhandler->AddLookXEventListener(eventfunction);}
    void AddLookYEventListener(std::function<void(InputRange*)> eventfunction)
    {_inputhandler->AddLookYEventListener(eventfunction);}
    void AddZoomEventListener(std::function<void(InputRange*)> eventfunction)
    {_inputhandler->AddZoomEventListener(eventfunction);}
    
    void AddPressDownEventListener(std::function<void (InputPosition *)> eventfunction)
    {_inputhandler->AddPressDownEventListener(eventfunction);}
    void AddPressUpEventListener(std::function<void (InputPosition *)> eventfunction)
    {_inputhandler->AddPressUpEventListener(eventfunction);}
    
    void InputHandler::AddMoveXEventListener(std::function<void(InputRange*)> eventfunction)
    {
        AddRangeInputEventListener(_movexevent, eventfunction);
    }
    void InputHandler::AddMoveYEventListener(std::function<void(InputRange*)> eventfunction)
    {
        AddRangeInputEventListener(_moveyevent, eventfunction);
    }
    void InputHandler::AddLookXEventListener(std::function<void(InputRange*)> eventfunction)
    {
        AddRangeInputEventListener(_lookxevent, eventfunction);
    }
    void InputHandler::AddLookYEventListener(std::function<void(InputRange*)> eventfunction)
    {
        AddRangeInputEventListener(_lookyevent, eventfunction);
    }
    void InputHandler::AddZoomEventListener(std::function<void(InputRange*)> eventfunction)
    {
        AddRangeInputEventListener(_zoomevent, eventfunction);
    }
    
    void InputHandler::AddPressDownEventListener(std::function<void (InputPosition *)> eventfunction)
    {
        AddPositionInputEventListener(_pressdownevent, eventfunction);
    }
    void InputHandler::AddPressUpEventListener(std::function<void (InputPosition *)> eventfunction)
    {
        AddPositionInputEventListener(_pressupevent, eventfunction);
    }
    
    
    void InputHandler::AddPositionInputEventListener(Subject<InputPosition*> &subject, std::function<void(InputPosition*)> eventfunction)
    {
        subject += eventfunction;
    };
    void InputHandler::AddRangeInputEventListener(Subject<InputRange*> &subject, std::function<void(InputRange*)> eventfunction)
    {
        subject += eventfunction;
    };
}