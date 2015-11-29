//
//  MXOpenGLEngine.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLEngine_H__
#define __MXOpenGLEngine_H__

#pragma once

//
#include "MXOpenGLUtility.h"

//
namespace MX {
	namespace OpenGL{
		
		//
		class Renderer;
		
		//
		class Engine : public Singleton<Engine>
		{
			friend class Renderer;
		public:
			Engine();
			virtual ~Engine();
			
			//
			virtual GLboolean	Initialize();
			virtual GLboolean	Release();
			
			virtual GLvoid		Render();
			
			void		SetClearBackgroundColor(float red = 0.0f, float green = 0.0f, float blue = 0.1f, float alpha = 0.0f);
			void		SetClearMask(int mask = GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
			void		ClearBackground(float red = 0.0f, float green = 0.0f, float blue = 0.1f, float alpha = 0.0f);
			void		ClearMask(int mask = GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
			
		protected:
			virtual void	OnClearBackground( );
			virtual void	OnClearMask( );
			
		private:
			float		m_fClearBackgroundColor[4];
			int			m_nClearMask;
		};
		
		//
		__inline void	Engine::SetClearBackgroundColor(float red, float green, float blue, float alpha)
		{
			m_fClearBackgroundColor[0] = red;
			m_fClearBackgroundColor[1] = green;
			m_fClearBackgroundColor[2] = blue;
			m_fClearBackgroundColor[3] = alpha;
		}
		
		__inline void	Engine::SetClearMask(int mask)
		{
			m_nClearMask = mask;
		}

		__inline void	Engine::ClearBackground(float red, float green, float blue, float alpha)
		{
			glClearColor(red, green, blue, alpha);
		}
		
		__inline void	Engine::ClearMask(int mask)
		{
			glClear(mask);
		}
		
	}; //namespace OpenGL
}; //namespace MX



#endif /* __MXOpenGLEngine_H__*/
