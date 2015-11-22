//
//  MXOpenGLUtil.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//


#include "MXOpenGLPrecompile.h"
#include "MXOpenGLUtility.h"
#include "MXOpenGLEngine.h"



//
namespace MX { namespace OpenGL {

//
Engine*	g_pEngine = NULL;
	
//
void ErrorLog(const char* format, ...)
{
	char text[256] = {0,};
	va_list val;
	va_start(val, format);
	vsnprintf(text, 255, format, val);
	va_end(val);
	
	ErrorLogI(text);
}

void OutputLog(const char* format, ...)
{
	char text[256] = {0,};
	va_list val;
	va_start(val, format);
	vsnprintf(text, 255, format, val);
	va_end(val);
	
	OutputLogI(text);
}
	
//
GLboolean Release()
{
	if(g_pEngine)
	{
		g_pEngine->Release();
		OutputLog("<%s> Engine release ok", __FUNCTION__);
		
		DestroyEngineI(g_pEngine);
		g_pEngine = NULL;
	}
	return GL_TRUE;
}

//
GLboolean Initialize()
{
	//
	GLenum result = glewInit();
	if(result != GLEW_OK)
	{
		ErrorLog("<%s> glewInit fail (ERROR:%d)", __FUNCTION__, result);
		return GL_FALSE;
	}
	OutputLog("<%s> glewInit ok", __FUNCTION__);
	
	// OpenGL support check.
	Support();
	
	//
	g_pEngine = CreateEngineI();
	if(!g_pEngine)
	{
		ErrorLog("<%s> CreateEngine fail (ERROR:%d)", __FUNCTION__, result);
		return GL_FALSE;
	}
	
	if(!g_pEngine->Initialize())
	{
		DestroyEngineI(g_pEngine);
		g_pEngine = NULL;
		
		ErrorLog("<%s> g_pEngine->Initialize fail (ERROR:%d)", __FUNCTION__, result);
		return GL_FALSE;
	}
	OutputLog("<%s> Engine initialize ok", __FUNCTION__);
	
	//
	return GL_TRUE;
}
	
//
GLboolean Support()
{
	//
	const GLubyte* desc_version		= glGetString(GL_VERSION);
	const GLubyte* desc_vendor		= glGetString(GL_VENDOR);
	const GLubyte* desc_renderer	= glGetString(GL_RENDERER);
	const GLubyte* desc_shading_lang= glGetString(GL_SHADING_LANGUAGE_VERSION);
	OutputLog("[MXOpenGLUtil] OpenGL version %s", desc_version);
	OutputLog("[MXOpenGLUtil] OpenGL vendor %s", desc_vendor);
	OutputLog("[MXOpenGLUtil] OpenGL renderer %s", desc_renderer);
	OutputLog("[MXOpenGLUtil] OpenGL GLSL Version %s", desc_shading_lang);
	
	//
	const char* versions[][2] =
	{
		{"1.2","GL_VERSION_1_2"},
		{"1.5","GL_VERSION_1_5"},
		{"2.0","GL_VERSION_2_0"},
		{"2.1","GL_VERSION_2_1"},
		{"3.0","GL_VERSION_3_0"},
		{"3.1","GL_VERSION_3_1"},
		{"3.2","GL_VERSION_3_2"},
		{"3.3","GL_VERSION_3_3"},
		{"4.0","GL_VERSION_4_0"},
		{"4.1","GL_VERSION_4_1"},
		{"4.2","GL_VERSION_4_2"},
		{"4.3","GL_VERSION_4_3"},
		{NULL, NULL},
	};
	
	for (int i = 0; versions[i][0] != NULL; i++)
	{
		OutputLog("[MXOpenGLUtil] OpenGL version %s %s support", versions[i][0],
					  !glewIsSupported(versions[i][1]) ? "not" : "");
	}
	
	
	//
	return GL_TRUE;
}
	
//
GLboolean Render()
{
	//
	if (g_pEngine)
	{
		g_pEngine->Render();
	}
	
	//
	return GL_TRUE;
}

}; }; //namespace MX { namespace OpenGL