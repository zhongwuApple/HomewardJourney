//
//  EAGLView.m
//  HomewardJourney
//
//  Created by apple on 13-7-17.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import "EAGLView.h"
#include "RenderingScene.h"


@implementation EAGLView
@synthesize animationFrameInterval;

- (void)dealloc
{
    [displayLink invalidate];
    displayLink = nil;
    [m_context release];
    [super dealloc];
}

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}


- (id) initWithFrame: (CGRect) frame
{
    if (self = [super initWithFrame:frame])
    {
        animating = FALSE;
        animationFrameInterval = 2;
        displayLink = nil;
    }
    return self;
}



/*
 *  @brief  opengl加载和初始化
 */
-(void) OpenGLConfig
{
    [self initEAGLContext];
    [self initBuffers];
    [self initDepthBuffer];
    [self initOutEngine];
    [self startAnimation];
    
}




/*
 *  @brief  图层 和 initEAGLContext
 */
-(BOOL) initEAGLContext
{
    CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
    eaglLayer.opaque = YES;
    eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                    [NSNumber numberWithBool:FALSE], kEAGLDrawablePropertyRetainedBacking,
                                    kEAGLColorFormatRGB565, kEAGLDrawablePropertyColorFormat, nil];
    
    EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
    m_context = [[EAGLContext alloc] initWithAPI:api];
    
    if (!m_context || ![EAGLContext setCurrentContext:m_context])
        return FALSE;
    
    return YES;
}






/*
 *  @brief  初始化缓冲区和绑定 以及一些设置
 */
-(BOOL) initBuffers
{
    //初始化缓冲区并绑定
    {
        glGenFramebuffers(1, &framebuffer);
        glGenRenderbuffers(1, &colorRenderbuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderbuffer);
    }
    
    //目前不明白 ，估计是 ios环境下的特有操作
    {
        CAEAGLLayer *eaglLayer = (CAEAGLLayer*)self.layer;
        glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
        [m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:eaglLayer];
    }
        
    //获取当前绑定的渲染缓存对象的参数,这里主要获取 宽和高
    {
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &backingWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &backingHeight);
    }
    
    //检查
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        return FALSE;
    
    return TRUE;
}



/*
 *  @brief   开启深度缓冲，(如果是2D 只有 X，Y 是没有必要的)
 */
-(void) initDepthBuffer
{
    glGenRenderbuffers(1, &depthRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, backingWidth, backingHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer);
    
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
}







/*
 *  @breif      外部引擎的一些初始化工作    
 */
-(void) initOutEngine
{
    glViewport(0, 0, backingWidth, backingHeight);      //opengl的视口 设置应该放到内部去处理的
    scene = new RenderingScene();
    scene->Initialize();
}



/*
 *  @breif      总的循环 以及最后的渲染
 */
- (void)gameLoop
{
    
//    glViewport(0, 0, backingWidth, backingHeight);
    scene->Render();
    [m_context presentRenderbuffer:GL_RENDERBUFFER];
}









//**************************************************************************************************************************************
//**************************************************************************************************************************************
//**************************************************************************************************************************************
-(void) startAnimation
{
    if (!animating)
    {
        displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(gameLoop)];
        [displayLink setFrameInterval:animationFrameInterval];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        animating = TRUE;
    }
}


-(void) stopAnimation
{
    if (animating)
    {
        [displayLink invalidate];
        displayLink = nil;
        animating = FALSE;
    }
}










































@end


































































