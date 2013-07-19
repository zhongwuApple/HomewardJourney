//
//  IOSInterface.m
//  HomewardJourney
//
//  Created by apple on 13-7-19.
//  Copyright (c) 2013年 apple. All rights reserved.
//
//  这里面提供 IOS平台的统一接口， 比如 在IOS下 读取 文件， 路径等等。
//
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <string>
#import <iostream>
#import "Interfaces.h"
#include <OpenGLES/ES2/gl.h>



namespace PlatformInterface
{
    
    class IOSInterfaceManager : public PlatformInterfaceManager
    {
    public:
        
        static IOSInterfaceManager &Instance()
        {
            static IOSInterfaceManager rm;
            return rm;
        }
        //获取IOS平台的当前路径
        string GetResourcePath() const
        {
            NSString* bundlePath =[[NSBundle mainBundle] resourcePath];
            return [bundlePath UTF8String];
        }
    };
    
    PlatformInterfaceManager* CreateInterfaceManager()
    {
        return  &IOSInterfaceManager::Instance();
    }
    
}





























































