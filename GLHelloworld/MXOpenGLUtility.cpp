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
	SINGLETON_IMPLE(Utility);
	Utility::Utility()
	{
	}
	
	Utility::~Utility()
	{
	}
	
	//
	bool Utility::Release()
	{
		return true;
	}
	
	//
	bool Utility::Initialize()
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
		return true;
	}
	
	//
	bool Utility::Support()
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
		const char* extensions[] =
		{
			"GL_EXT_vertex_array_bgra",		//opengl 2.1
			NULL,
		};

		for (int i = 0; extensions[i] != NULL; i++)
		{
			GLboolean result = glewIsExtensionSupported(extensions[i]);
			if(!result)
			{
				OutputLog("[MXOpenGLUtil] OpenGL extension not support: %s", extensions[i]);
			}
		}
		
		const char* extensions_text = (const char*)glGetString(GL_EXTENSIONS);
		if(extensions_text)
		{
			return GL_FALSE;
		}
		//
		return GL_TRUE;
	}
	
	//
	void Utility::ErrorLog(const char* format, ...)
	{
		char text[256] = {0,};
		va_list val;
		va_start(val, format);
		vsnprintf(text, 255, format, val);
		va_end(val);
		
		if(m_fnCallbackError)
		{ m_fnCallbackError(text); }
	}
	
	void Utility::OutputLog(const char* format, ...)
	{
		char text[256] = {0,};
		va_list val;
		va_start(val, format);
		vsnprintf(text, 255, format, val);
		va_end(val);
		
		if(m_fnCallbackOutput)
		{ m_fnCallbackOutput(text); }
	}

}; }; //namespace MX { namespace OpenGL