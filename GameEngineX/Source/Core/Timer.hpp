//
//  Timer.hpp
//  GameEngineX
//
//  Created by George Hanna on 10/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>

class Timer
{
public:
    float _dt;
    float _totalelapsedtime;
    
    void Initialize();
    void UpdateTimer(float elapsedtime);
};

#endif /* Timer_hpp */
