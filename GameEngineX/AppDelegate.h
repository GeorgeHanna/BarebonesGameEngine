//
//  AppDelegate.h
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ViewController.h"
#import "OpenGLESView.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    OpenGLESView* _glView;
}

@property (nonatomic, retain) IBOutlet OpenGLESView *glView;

@property (strong, nonatomic) UIWindow *window;


@end

