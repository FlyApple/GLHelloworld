//
//  MXOpenGLEngine.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//


#include "MXOpenGLPrecompile.h"
#include "MXOpenGLEngine.h"

//
namespace MX {
	namespace OpenGL{
		
		//
		bool	DrawableT::OnBeginDraw()
		{
			if(m_pEngine)
			{
				m_pEngine->ClearBackground();
				m_pEngine->ClearMask();
			}
			return true;
		}
		
		bool	DrawableT::OnEndDraw()
		{
			return true;
		}
		
		
		//
		SINGLETON_IMPLE(Engine);
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
			DrawableT	drawable(this);
			if(drawable.OnDraw())
			{
				//nothing
			}
		}
		
		void		Engine::ClearBackground(float red, float green, float blue, float alpha)
		{
			glClearColor(red, green, blue, alpha);
		}
		
		void		Engine::ClearMask(int mask)
		{
			glClear(mask);
		}
	}; //namespace OpenGL
}; //namespace MX
