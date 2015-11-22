//
//  MXOpenGLEngine.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//


#include "MXOpenGLUtilPrecompile.h"
#include "MXOpenGLEngine.h"

//
namespace MX {
	namespace OpenGL{
		
		//
		Engine::Engine()
		{
		
		}
		
		Engine::~Engine()
		{
		}
		
		GLboolean	Engine::Release()
		{
			return GL_TRUE;
		}
		
		GLboolean	Engine::Initialize()
		{
			return GL_TRUE;
		}
		
		GLvoid		Engine::Render()
		{
			DrawableT	drawable;
			drawable.OnDraw();
		}
		
	}; //namespace OpenGL
}; //namespace MX
