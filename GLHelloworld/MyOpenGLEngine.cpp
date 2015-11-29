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
	MX_OPENGL_DELETE_POINTER(m_pTriangle);
	
	//
	OpenGL::Engine::Release();
	return GL_TRUE;
}

GLboolean	MyOpenGLEngine::Initialize()
{
	if(!OpenGL::Engine::Initialize())
	{ return GL_FALSE; }
	
	m_pTriangle = new MX::OpenGL::Triangle();
	
	//
	return GL_TRUE;
}

GLvoid		MyOpenGLEngine::Render()
{
	MX::OpenGL::RendererT	renderer(this);
	if(renderer.OnDraw(m_pTriangle))
	{
		//nothing
	}
}
