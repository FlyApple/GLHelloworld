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
		class Engine;
		
		//
		class Drawable
		{
		public:
			Drawable(Engine* pEngine = NULL)
				:	m_pEngine(pEngine)
			{ };
			virtual ~Drawable()
			{ };
			
		protected:
			Engine*		m_pEngine;
		};
		
		//
		class WIN_Drawable : public Drawable
		{
		public:
			WIN_Drawable(Engine* pEngine = NULL)
				: Drawable(pEngine)
			{ };
			virtual ~WIN_Drawable()
			{ };
		};
		
		//在osx 中flush仅仅只能执行一次
		class OSX_Drawable : public Drawable
		{
		public:
			OSX_Drawable(Engine* pEngine = NULL)
				: Drawable(pEngine)
			{ };
			virtual ~OSX_Drawable()
			{
				glFlush();
			};
		};
		
		//
#if defined(__APPLE__)
		class DrawableT : public OSX_Drawable
#else
		class DrawableT : public WIN_Drawable
#endif
		{
		public:
			DrawableT(Engine* pEngine = NULL)
#if defined(__APPLE__)
				: OSX_Drawable(pEngine)
#else
				: WIN_Drawable(pEngine)
#endif
			{
				this->OnBeginDraw();
			}
			virtual ~DrawableT()
			{
				this->OnEndDraw();
			}
			
			virtual bool	OnBeginDraw();
			virtual bool	OnEndDraw();
			virtual bool	OnDraw() { return true; }
		};
		
		//
		class Engine : public Singleton<Engine>
		{
			friend class DrawableT;
		public:
			Engine();
			virtual ~Engine();
			
			//
			GLboolean	Initialize();
			GLboolean	Release();
			
			GLvoid		Render();
			
		protected:
			virtual void	ClearBackground(float red = 0.0f, float green = 0.0f, float blue = 0.1f, float alpha = 0.0f);
			virtual void	ClearMask(int mask = GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		};

	}; //namespace OpenGL
}; //namespace MX



#endif /* __MXOpenGLEngine_H__*/
