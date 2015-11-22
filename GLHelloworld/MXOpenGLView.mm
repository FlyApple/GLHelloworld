//
//  MXOpenGLView.m
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "Precompile.h"
#import "MXOpenGLView.h"

#import "MXOpenGLUtilApple.h"

//
@implementation MXOpenGLView


//
- (void)clearGLContext
{
	[super clearGLContext];
}

- (void)prepareOpenGL
{
	[super prepareOpenGL];
		
	//
	m_pTimer = [NSTimer timerWithTimeInterval:(1.0f/60.0f)target:self selector:@selector(idle:) userInfo:nil repeats:YES];
	[[NSRunLoop currentRunLoop]addTimer:m_pTimer forMode:NSDefaultRunLoopMode];
}

- (void)idle:(NSTimer*)pTimer
{
	[self drawRect:[self bounds]];
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    
    // Drawing code here.
	glViewport(0, 0, dirtyRect.size.width, dirtyRect.size.height);
	
	[self render];
}

-(void)render
{
	if([MX_OSX_OpenGLUtil SingletonPtr])
	{
		[[MX_OSX_OpenGLUtil SingletonPtr] render];
	}
}

@end
