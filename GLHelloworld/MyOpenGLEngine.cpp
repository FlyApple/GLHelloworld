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
using namespace MX;

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