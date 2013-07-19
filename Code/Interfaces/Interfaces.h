//
//  Interfaces.h
//  MiniDota
//
//  Created by apple on 12-12-10.
//  Copyright (c) 2012年 apple. All rights reserved.
//

#ifndef _Interfaces_h
#define _Interfaces_h

#include "VectorCustom.h"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <string>
using std::string;


/*
 *  @breif      渲染引擎定义
 */
struct RenderingEngine
{
    virtual void Initialize() = 0;
    virtual void Render()  = 0;
    virtual ~RenderingEngine(){}
};




/*
 *  @breif     平台接口声明
 */
struct PlatformInterfaceManager
{
    virtual string GetResourcePath() const = 0;
    virtual ~PlatformInterfaceManager() {}
};






//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//平台接口
namespace PlatformInterface       { PlatformInterfaceManager* CreateInterfaceManager(); }




























































#endif


















































