//
//  MyOpenGLEngine.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "MyOpenGLEngine.hpp"



//
namespace MX {
namespace OpenGL {
	
	//
	MX_CALLBACK_API MX::OpenGL::Engine*		CreateEngineI()
	{
		return (MX::OpenGL::Engine*)new MyOpenGLEngine();
	}
	
	MX_CALLBACK_API GLboolean	DestroyEngineI(MX::OpenGL::Engine* pEngine)
	{
		if(pEngine)
		{
			delete pEngine;
			pEngine = NULL;
		}
		return GL_TRUE;
	}
}; //namespace OpenGL
}; //namespace MX


//
MyOpenGLEngine::MyOpenGLEngine()
{
}

MyOpenGLEngine::~MyOpenGLEngine()
{
	
}

GLboolean	MyOpenGLEngine::Release()
{
	
	//
	OpenGL::Engine::Release();
	return GL_TRUE;
}

GLboolean	MyOpenGLEngine::Initialize()
{
	if(!OpenGL::Engine::Initialize())
	{ return GL_FALSE; }
	
	//
	return GL_TRUE;
}

