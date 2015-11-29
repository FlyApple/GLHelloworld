//
//  MXOpenGLEngine.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//


#include "MXOpenGLPrecompile.h"
#include "MXOpenGLEngine.h"
#include "MXOpenGLRenderer.h"


//
namespace MX {
	namespace OpenGL{
		
		//
		SINGLETON_IMPLE(Engine);
		Engine::Engine()
		{
			//clear background color:
			m_fClearBackgroundColor[0]	= 0.0f;	//Red
			m_fClearBackgroundColor[1]	= 0.0f;	//Green
			m_fClearBackgroundColor[2]	= 0.1f;	//Blue
			m_fClearBackgroundColor[3]	= 0.0f;	//Alpha
			
			//clear mask:
			m_nClearMask				= GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT;
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
			RendererT	renderer(this);
			if(renderer.OnDraw())
			{
				//nothing
			}
		}
		
		void		Engine::OnClearBackground( )
		{
			this->ClearBackground(m_fClearBackgroundColor[0],
								  m_fClearBackgroundColor[1],
								  m_fClearBackgroundColor[2],
								  m_fClearBackgroundColor[3]);
		}
		
		void		Engine::OnClearMask( )
		{
			this->ClearMask(m_nClearMask);
		}
	}; //namespace OpenGL
}; //namespace MX
