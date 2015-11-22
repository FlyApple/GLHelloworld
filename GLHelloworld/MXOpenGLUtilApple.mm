//
//  MXOpenGLUtilApple.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "MXOpenGLUtilPrecompile.h"
#include "MXOpenGLUtil.h"
#include "MXOpenGLUtilApple.h"


#ifdef __APPLE__

//
APPKIT_EXTERN int MX_OSX_OpenGLApplicationMain(int argc, const char* argv[])
{
	MX_OSX_OpenGLUtil* util = [[MX_OSX_OpenGLUtil new] init];
	if(![util Initialize])
	{
		NSLog(@"<%s> MX OSX OpenGLUtil initialize fail.", __FUNCTION__);
		return 0;
	}
	
	//
	int result = NSApplicationMain(argc, argv);
	
	//
	//[util Release];
	return result;
}


//
APPKIT_EXTERN void MXGL_CallbackErrorLog(const char* log)
{
	NSLog(@"[Error] %@", [[NSString alloc] initWithCString:(const char*)log encoding:NSUTF8StringEncoding]);
}

APPKIT_EXTERN void MXGL_CallbackOutputLog(const char* log)
{
	NSLog(@"[Output] %@", [[NSString alloc] initWithCString:(const char*)log encoding:NSUTF8StringEncoding]);
}

//
namespace MX {
namespace OpenGL {
	
	//
	MX_CALLBACK_API void ErrorLogI(const char* log)
	{
		MXGL_CallbackErrorLog(log);
	}
	
	MX_CALLBACK_API void OutputLogI(const char* log)
	{
		MXGL_CallbackOutputLog(log);
	}
	
}; //namespace MX
}; //namespace OpenGL


//
static MX_OSX_OpenGLUtil* gs_pOpenGLUtil = NULL;

//
@implementation MX_OSX_OpenGLUtil

+(MX_OSX_OpenGLUtil*) SingletonPtr
{
	return gs_pOpenGLUtil;
}

-(MX_OSX_OpenGLUtil*)init
{
	self = [super init];
	if(self)
	{
		m_Context = NULL;
	}
	
	gs_pOpenGLUtil = self;
	return self;
}

-(void)dealloc
{
	gs_pOpenGLUtil = NULL;
}

@synthesize context = m_Context;
-(MX_OSX_OpenGLContext)context
{
	return m_Context;
}

-(BOOL)Release
{
	//
	if(!MX::OpenGL::Release())
	{
		NSLog(@"<%s> ReleaseOpenGL fail.", __FUNCTION__);
		return NO;
	}
	
	//
	CGLSetCurrentContext(NULL);
	if(m_Context)
	{
		CGLReleaseContext(m_Context);
		m_Context = NULL;
	}
	return YES;
}

-(BOOL)Initialize
{
	//
	CGLPixelFormatAttribute attributes[] =
	{
		//From : OpenGL Programming Guide for Apple's Mac
		//kCGLOGLPVersion_Legacy (OSX 10.7) choose a renderer compatible with OpenGL1.0
		//kCGLOGLPVersion_GL3_Core (OSX 10.7) choose a renderer capable of OpenGL3.2 or later
		//kCGLOGLPVersion_GL4_Core (OSX 10.9) choose a renderer capable of OpenGL4.1 or later
		kCGLPFAOpenGLProfile, (CGLPixelFormatAttribute)kCGLOGLPVersion_GL3_Core,
		kCGLPFAColorSize, (CGLPixelFormatAttribute)24,
		kCGLPFAAlphaSize, (CGLPixelFormatAttribute)8,
		kCGLPFADepthSize, (CGLPixelFormatAttribute)16,
		kCGLPFAStencilSize, (CGLPixelFormatAttribute)8,
		kCGLPFAAccelerated,
		kCGLPFADoubleBuffer,
		(CGLPixelFormatAttribute)0
	};
	
	//
	GLint				nPixFormatNum	= 0;
	CGLPixelFormatObj	PixFormatObj	= NULL;
	CGLError result = CGLChoosePixelFormat(attributes, &PixFormatObj, &nPixFormatNum);
	if (result != kCGLNoError || PixFormatObj == NULL)
	{
		NSLog(@"<%s> CGLChoosePixelFormat fail [ERROR %d]", __FUNCTION__, result);
		return NO;
	}
	
	//
	CGLContextObj		ContextObj		= NULL;
	result = CGLCreateContext(PixFormatObj, NULL, &ContextObj);
	if (result != kCGLNoError || ContextObj == NULL)
	{
		NSLog(@"<%s> CGLCreateContext fail [ERROR %d]", __FUNCTION__, result);
		return NO;
	}
	m_Context = ContextObj;
	
	//CGLDestroyPixelFormat : Calling this function is equivalent to calling CGLReleasePixelFormat.
	CGLReleasePixelFormat(PixFormatObj);
	
	//
	CGLSetCurrentContext(m_Context);
	
	//
	if(!MX::OpenGL::Initialize())
	{
		NSLog(@"<%s> InitializeOpenGL fail.", __FUNCTION__);
		return NO;
	}
	
	//
	return YES;
}

-(void) render
{
	if(m_Context)
	{
		MX::OpenGL::Render();
		
		CGLFlushDrawable(m_Context);
	}
}


@end


#endif //__APPLE__