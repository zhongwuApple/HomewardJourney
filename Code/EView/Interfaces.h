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




struct RenderingEngine
{
    virtual void Initialize() = 0;
    virtual void Render()  = 0;
    virtual ~RenderingEngine(){}
};











//资源管理




























































#endif


















































