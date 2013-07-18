//
//  AppDelegate.h
//  HomewardJourney
//
//  Created by apple on 13-7-17.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EAGLView;
@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    EAGLView            *eaglView;
    UIWindow            *window;
}
@property (retain, nonatomic) UIWindow *window;

@end
