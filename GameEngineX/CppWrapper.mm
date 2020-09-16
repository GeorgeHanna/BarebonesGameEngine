//
//  CppWrapper.m
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#import "CppWrapper.h"
#import <CoreMotion/CoreMotion.h>
#include "Game.hpp"
#include "Source/Core/Resources.hpp"
#include "Source/Core/Input/InputHandler.hpp"

@interface CppWrapper() {
    Game::Game* _game;
    float _prevtime;
    CMMotionManager *_motionmanager;
    float _prevaccX, _prevaccY, _prevaccZ;
}

@end



@implementation CppWrapper

- (id)initWithFrame : (CGRect)frame
{
    self = [super init];
    if ( self )
    {

        NSString* rootpath = [[NSBundle mainBundle] bundlePath];
        
        Resources::Initialize([rootpath UTF8String]);
        

        //init game
        _game = new Game::Game();
        _game->_maincamera->_screenwidth = frame.size.width;
        _game->_maincamera->_screenheight = frame.size.height;
        _game->Initialize();
        
        //timer initial time
        _prevtime = CACurrentMediaTime();
        
        //accelerometer init
        _motionmanager = [[CMMotionManager alloc] init];
        _motionmanager.accelerometerUpdateInterval = 1/60;
        [_motionmanager startAccelerometerUpdates];
        
        NSLog(@"%d", 1);
    }
    return self;
}

-(void) Update
{
    CFTimeInterval timeinterval = CACurrentMediaTime() - _prevtime;
    [self accelerometerUpdate];
    _game->Update(timeinterval);
}

-(void) Draw
{
    _game->Draw();
}

//Input
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event fromView:(UIView *)view
{
    if([[event allTouches] count] == 1)
    {
        
        UITouch *touch = [[event allTouches] anyObject];
        CGPoint touchLocation = [touch locationInView:view];
        CGPoint prevTouchLocation = [touch previousLocationInView:view];
        CGPoint deltaTouchLocation = CGPointMake(touchLocation.x - prevTouchLocation.x, touchLocation.y - prevTouchLocation.y);
        InputHandler::GetInputHandler()->SetPressDownPosition({touchLocation.x, touchLocation.y});
         
    }
    
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event fromView:(UIView *)view
{
    if([[event allTouches] count] == 1)
    {
        UITouch *touch = [[event allTouches] anyObject];
        CGPoint touchLocation = [touch locationInView:view];
        CGPoint prevTouchLocation = [touch previousLocationInView:view];
        CGPoint deltaTouchLocation = CGPointMake(touchLocation.x - prevTouchLocation.x, touchLocation.y - prevTouchLocation.y);

        (InputHandler::GetInputHandler())->SetLookXRange(deltaTouchLocation.x);
        (InputHandler::GetInputHandler())->SetLookYRange(-deltaTouchLocation.y);
    }
    else if([[event allTouches] count] == 2)
    {
        UITouch *touch1 = [[event allTouches] allObjects][0];
        CGPoint touchLocation1 = [touch1 locationInView:view];
        CGPoint prevTouchLocation1 = [touch1 previousLocationInView:view];
        
        UITouch *touch2 = [[event allTouches] allObjects][1];
        CGPoint touchLocation2 = [touch2 locationInView:view];
        CGPoint prevTouchLocation2 = [touch2 previousLocationInView:view];
        
        CGPoint prevtouchdist = CGPointMake(prevTouchLocation2.x - prevTouchLocation1.x, prevTouchLocation2.y - prevTouchLocation1.y);
        CGPoint currtouchdist = CGPointMake(touchLocation2.x - touchLocation1.x, touchLocation2.y - touchLocation1.y);
        float prevtouchdeltadist = sqrtf((prevtouchdist.x*prevtouchdist.x) + (prevtouchdist.y*prevtouchdist.y));
        float currtouchdeltadist = sqrtf((currtouchdist.x*currtouchdist.x) + (currtouchdist.y*currtouchdist.y));
        float deltaTouchDistSize = prevtouchdeltadist - currtouchdeltadist;
        
        (InputHandler::GetInputHandler())->SetZoomRange(deltaTouchDistSize);
    }
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event fromView:(UIView *)view
{
    
    if([[event allTouches] count] == 1)
    {
        
        UITouch *touch = [[event allTouches] anyObject];
        CGPoint touchLocation = [touch locationInView:view];
        CGPoint prevTouchLocation = [touch previousLocationInView:view];
        CGPoint deltaTouchLocation = CGPointMake(touchLocation.x - prevTouchLocation.x, touchLocation.y - prevTouchLocation.y);
        InputHandler::GetInputHandler()->SetPressUpPosition({touchLocation.x, touchLocation.y});
        
    }
     
}

- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
}

- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
}

- (void)accelerometerUpdate
{
    CMAccelerometerData *data = _motionmanager.accelerometerData;
    b2Vec3 acceleration = b2Vec3(data.acceleration.x, data.acceleration.y, data.acceleration.z);
    
#define kFilterFactor 0.5
    
    float accelX = (float) acceleration.x * kFilterFactor + (1- kFilterFactor)*_prevaccX;
    float accelY = (float) acceleration.y * kFilterFactor + (1- kFilterFactor)*_prevaccY;
    float accelZ = (float) acceleration.z * kFilterFactor + (1- kFilterFactor)*_prevaccZ;
    
    _prevaccX = accelX;
    _prevaccY = accelY;
    _prevaccZ = accelZ;
    
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    
    if(orientation == UIInterfaceOrientationPortrait)
    {
    }
    else if(orientation == UIInterfaceOrientationLandscapeLeft)
        (InputHandler::GetInputHandler())->SetMoveXRange(accelY);

    else if(orientation == UIInterfaceOrientationLandscapeRight)
        (InputHandler::GetInputHandler())->SetMoveXRange(-accelY);
    
    //(InputHandler::GetInputHandler())->SetMoveYRange(1);
}

@end
