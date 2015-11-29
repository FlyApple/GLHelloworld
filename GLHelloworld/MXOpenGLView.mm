//
//  MXOpenGLView.m
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "MXOpenGLPrecompile.h"
#import "MXOpenGLView.h"



//
@implementation MXOpenGLView

//+ (NSOpenGLPixelFormat*)defaultPixelFormat;
//{
//	if(!ms_pPixelFormat)
//	{
//		NSOpenGLPixelFormatAttribute	attrubutes[] =
//		{
//			//From : OpenGL Programming Guide for Apple's Mac
//			//NSOpenGLProfileVersionLegacy (OSX 10.7) choose a renderer compatible with OpenGL1.0
//			//NSOpenGLProfileVersion3_2Core (OSX 10.7) choose a renderer capable of OpenGL3.2 or later
//			//NSOpenGLProfileVersion4_1Core (OSX 10.9) choose a renderer capable of OpenGL4.1 or later
//			NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersionLegacy,
//			NSOpenGLPFAColorSize, (NSOpenGLPixelFormatAttribute)32,
//			NSOpenGLPFAAlphaSize, (NSOpenGLPixelFormatAttribute)8,
//			NSOpenGLPFADepthSize, (NSOpenGLPixelFormatAttribute)16,
//			NSOpenGLPFAStencilSize, (NSOpenGLPixelFormatAttribute)8,
//			NSOpenGLPFAAccelerated,
//			NSOpenGLPFADoubleBuffer,
//			(NSOpenGLPixelFormatAttribute)0
//		};
//		
//		ms_pPixelFormat = [[NSOpenGLPixelFormat alloc]initWithAttributes:attrubutes];
//	}
//	return ms_pPixelFormat;
//}

//
- (MX_OSX_OpenGLContext*)getOpenGLContext
{
	return [[MX_OSX_OpenGLContext alloc] init];
}

//
- (id)initWithCoder:(NSCoder *)coder
{
	self = [super initWithCoder:coder];
	if(self != nil)
	{
		m_pOpenGLContext	= [self getOpenGLContext];
		
		NSOpenGLPixelFormat*	pixel_format	= [[NSOpenGLPixelFormat alloc] initWithCGLPixelFormatObj:[m_pOpenGLContext pixelFormatObj]];
		NSOpenGLContext*		context			= [[NSOpenGLContext alloc] initWithCGLContextObj:[m_pOpenGLContext contextObj]];
		if(context)
		{
			[self setPixelFormat:pixel_format];
			[self setOpenGLContext:context];
		}
	}
	return self;
}

//
- (void)clearGLContext
{
	[self releaseOpenGL];
	
	[super clearGLContext];
}

- (void)prepareOpenGL
{
	[super prepareOpenGL];
	
	//
	m_pTimer = [NSTimer timerWithTimeInterval:(1.0f/60.0f)target:self selector:@selector(idle:) userInfo:nil repeats:YES];
	[[NSRunLoop currentRunLoop]addTimer:m_pTimer forMode:NSDefaultRunLoopMode];
	
	//
	[self initializeOpenGL];
}

- (void)idle:(NSTimer*)pTimer
{
	[self drawRect:[self bounds]];
}

- (void)reshape
{
	m_fWidth = [self bounds].size.width;
	m_fHeight= [self bounds].size.height;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    
    // Drawing code here.
	glViewport(0, 0, m_fWidth, m_fHeight);
	
	[self render];
}

-(void)render
{
	if(m_pOpenGLContext)
	{
		[m_pOpenGLContext render];
	}
}

-(BOOL)initializeOpenGL
{
	const char* version = (const char*)glGetString(GL_VERSION);
	if(version == NULL){ version = "version null"; }
	NSLog(@"<%s> check opengl version: %@", __FUNCTION__,
		  [[NSString alloc]initWithCString:version encoding:NSUTF8StringEncoding]);
	
	const char* extensions = (const char*)glGetString(GL_EXTENSIONS);
	if(extensions == NULL){ extensions = "externsions null"; }
	NSLog(@"<%s> check opengl extensions: %@", __FUNCTION__,
		  [[NSString alloc]initWithCString:extensions encoding:NSUTF8StringEncoding]);
	return YES;
}

-(BOOL)releaseOpenGL
{
	//nothing
	return YES;
}

@end
