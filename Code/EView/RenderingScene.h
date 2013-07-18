//
//  RenderingScene.h
//  HomewardJourney
//
//  Created by apple on 13-7-17.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#ifndef _RenderingScene_h
#define _RenderingScene_h

#include <iostream>
#include "Interfaces.h"
#include "ShaderManager.h"

class RenderingScene : public RenderingEngine
{
public:
    ShaderObject    *shader;
    
public:
    void Initialize() ;
    void Render()  ;
    
    ~RenderingScene();
    RenderingScene();
    
};




#endif




































































