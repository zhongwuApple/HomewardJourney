//
//  EAGLView.h
//  HomewardJourney
//
//  Created by apple on 13-7-17.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

class RenderingScene;
@interface EAGLView : UIView
{
    
    RenderingScene  *scene;
    CADisplayLink   *displayLink;
    BOOL            animating;
    int             animationFrameInterval;
    
    
    EAGLContext     *m_context;
    
    GLuint          framebuffer;
    GLuint          colorRenderbuffer;
    GLuint          depthRenderbuffer;
    
    GLint           backingWidth;
    GLint           backingHeight;
    
}

@property(nonatomic)int animationFrameInterval;


- (void) startAnimation;
- (void) stopAnimation;





-(BOOL) initEAGLContext;

-(BOOL) initBuffers;

-(void) initDepthBuffer;

-(void) initOutEngine;






@end






















































































