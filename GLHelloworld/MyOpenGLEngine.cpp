//
//  MyOpenGLEngine.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "MyOpenGLEngine.h"


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

