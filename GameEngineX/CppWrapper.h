//
//  CppWrapper.h
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CppWrapper : NSObject

-(void) Update;
-(void) Draw;

- (id)initWithFrame : (CGRect)frame;

//Input
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event fromView:(UIView *)view;
- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event fromView:(UIView *)view;
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event fromView:(UIView *)view;
- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)accelerometerUpdate;
@end
