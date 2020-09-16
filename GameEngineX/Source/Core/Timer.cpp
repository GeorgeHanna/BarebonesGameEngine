//
//  Timer.cpp
//  GameEngineX
//
//  Created by George Hanna on 10/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Timer.hpp"

void Timer::Initialize()
{
    _dt = 0;
    _totalelapsedtime = 0;
}

void Timer::UpdateTimer(float elapsedtime)
{
    _dt = elapsedtime - _totalelapsedtime;
    _totalelapsedtime = elapsedtime;
}