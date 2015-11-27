//
//  MyOpenGLUtil.m
//  GLHelloworld
//
//  Created by enos sariel on 15/11/28.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "MXOpenGLUtility.h"
#include "MyOpenGLUtil.h"
#include "MyOpenGLEngine.h"


//
MyOpenGLEngine*		g_pEngine = NULL;

//
@implementation MyOpenGLUtil

-(BOOL) Initialize
{
	if (![super Initialize])
	{
		return NO;
	}
	
	g_pEngine = new MyOpenGLEngine();
	if(!g_pEngine->Initialize())
	{
		MX_OPENGL_DELETE_POINTER(g_pEngine);
		
		ERROR_LOG("<%s> Engine initialize fail.", __FUNCTION__);
		return GL_FALSE;
	}
	OUTPUT_LOG("<%s> Engine initialize ok.", __FUNCTION__);
	
	return YES;
}

-(BOOL) Release
{
	if(g_pEngine)
	{
		g_pEngine->Release();
		OUTPUT_LOG("<%s> Engine release ok", __FUNCTION__);
		
		MX_OPENGL_DELETE_POINTER(g_pEngine);
	}
	
	//
	return [super Release];
}

-(void) draw
{
	if (g_pEngine)
	{
		g_pEngine->Render();
	}
}

@end
