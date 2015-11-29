//
//  MXOpenGLUtilApple.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "MXOpenGLPrecompile.h"
#include "MXOpenGLUtility.h"
#include "MXOpenGLApple.h"


#ifdef __APPLE__


//
APPKIT_EXTERN void MX_OSX_CallbackErrorLog(const char* log)
{
	NSLog(@"[Error] %@", [[NSString alloc] initWithCString:(const char*)log encoding:NSUTF8StringEncoding]);
}

APPKIT_EXTERN void MX_OSX_CallbackOutputLog(const char* log)
{
	NSLog(@"[Output] %@", [[NSString alloc] initWithCString:(const char*)log encoding:NSUTF8StringEncoding]);
}

//
namespace MX {
namespace OpenGL {
	
	//
	Utility*		g_pUtility	= NULL;
	
	//
	MX_OPENGL_CALLBACK void CBErrorLog(const char* log)
	{
		MX_OSX_CallbackErrorLog(log);
	}
	
	MX_OPENGL_CALLBACK void CBOutputLog(const char* log)
	{
		MX_OSX_CallbackOutputLog(log);
	}
	
}; //namespace MX
}; //namespace OpenGL



//
@implementation MX_OSX_OpenGLContext

@synthesize pixelFormatObj = m_PixelFormatObj;
-(CGLPixelFormatObj)pixelFormatObj
{
	return m_PixelFormatObj;
}

@synthesize contextObj = m_ContextObj;
-(CGLContextObj)contextObj
{
	return m_ContextObj;
}

- (MX_OSX_OpenGLContext*)init
{
	self = [super init];
	if (self != nil)
	{
		[self InitializeCGL];
	}
	return self;
}

- (void)dealloc
{
	[self ReleaseCGL];
}

- (BOOL)ReleaseCGL
{
	if(m_ContextObj)
	{
		CGLContextObj	ContextObj = CGLGetCurrentContext();
		if(ContextObj == m_ContextObj)
		{
			CGLSetCurrentContext(NULL);
		}
		
		CGLReleaseContext(m_ContextObj);
		m_ContextObj = NULL;
	}
	
	if(m_PixelFormatObj)
	{
		//CGLDestroyPixelFormat : Calling this function is equivalent to calling CGLReleasePixelFormat.
		CGLReleasePixelFormat(m_PixelFormatObj);
		m_PixelFormatObj = NULL;
	}
	return YES;
}

- (BOOL)InitializeCGL
{
	//
	CGLPixelFormatAttribute attributes[] =
	{
		//From : OpenGL Programming Guide for Apple's Mac
		//kCGLOGLPVersion_Legacy (OSX 10.7) choose a renderer compatible with OpenGL1.0
		//kCGLOGLPVersion_GL3_Core (OSX 10.7) choose a renderer capable of OpenGL3.2 or later
		//kCGLOGLPVersion_GL4_Core (OSX 10.9) choose a renderer capable of OpenGL4.1 or later
		kCGLPFAOpenGLProfile, (CGLPixelFormatAttribute)kCGLOGLPVersion_3_2_Core,
		kCGLPFAColorSize, (CGLPixelFormatAttribute)32,
		kCGLPFAAlphaSize, (CGLPixelFormatAttribute)8,
		kCGLPFADepthSize, (CGLPixelFormatAttribute)16,
		kCGLPFAStencilSize, (CGLPixelFormatAttribute)8,
		kCGLPFAAccelerated,
		kCGLPFADoubleBuffer,
		(CGLPixelFormatAttribute)0
	};
	
	//
	GLint	nPixelFormatNum	= 0;
	m_PixelFormatObj		= NULL;
	CGLError result = CGLChoosePixelFormat(attributes, &m_PixelFormatObj, &nPixelFormatNum);
	if (result != kCGLNoError || m_PixelFormatObj == NULL)
	{
		NSLog(@"<%s> CGLChoosePixelFormat fail [ERROR %d]", __FUNCTION__, result);
		return NO;
	}

	m_ContextObj			= NULL;
	result = CGLCreateContext(m_PixelFormatObj, NULL, &m_ContextObj);
	if (result != kCGLNoError || m_ContextObj == NULL)
	{
		NSLog(@"<%s> CGLCreateContext fail [ERROR %d]", __FUNCTION__, result);
		return NO;
	}
	
	//
	result = CGLSetCurrentContext(m_ContextObj);
	
	//
	return YES;
}

-(void) render
{
	if(m_ContextObj)
	{
		if([MX_OSX_OpenGLUtility SingletonPtr])
		{
			[[MX_OSX_OpenGLUtility SingletonPtr] draw];
		}
		CGLFlushDrawable(m_ContextObj);
	}
}

@end

//
static MX_OSX_OpenGLUtility* gs_pOpenGLUtility = NULL;

//
@implementation MX_OSX_OpenGLUtility

+(MX_OSX_OpenGLUtility*) SingletonPtr
{
	return gs_pOpenGLUtility;
}

-(MX_OSX_OpenGLUtility*)init
{
	self = [super init];
	if(self)
	{
	}
	
	gs_pOpenGLUtility = self;
	return self;
}

-(void)dealloc
{
	gs_pOpenGLUtility = NULL;
}

-(BOOL)Release
{
	//
	if (!MX::OpenGL::g_pUtility->Release())
	{
		NSLog(@"<%s> OpenGLUtility release fail.", __FUNCTION__);
		return NO;
	}
	
	return YES;
}

-(BOOL)Initialize
{	
	//
	MX::OpenGL::g_pUtility = new MX::OpenGL::Utility();
	MX::OpenGL::g_pUtility->SetCallbackOutput(MX::OpenGL::CBOutputLog);
	MX::OpenGL::g_pUtility->SetCallbackError(MX::OpenGL::CBErrorLog);
	if (!MX::OpenGL::g_pUtility->Initialize())
	{
		NSLog(@"<%s> OpenGLUtility initialize fail.", __FUNCTION__);
		return NO;
	}
	
	//
	return YES;
}

-(void) draw
{
	//nothing
}

@end


#endif //__APPLE__