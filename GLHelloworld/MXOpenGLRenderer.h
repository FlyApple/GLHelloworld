//
//  MXOpenGLRenderer.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/28.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLRenderer_H__
#define __MXOpenGLRenderer_H__

#pragma once

//
namespace MX {
	namespace OpenGL{
		
		//
		class DrawableI;
		
		class Engine;
		
		//
		class Renderer
		{
		public:
			Renderer(Engine* pEngine = NULL)
			:	m_pEngine(pEngine)
			{
				this->OnBeginDraw();
			};
			virtual ~Renderer()
			{
				this->OnEndDraw();
			};
			
			virtual bool	OnBeginDraw();
			virtual bool	OnEndDraw();
			virtual bool	OnDraw(DrawableI* drawableI = NULL);
			
		protected:
			virtual bool	OnDrawBase(DrawableI* drawableI);
			
		protected:
			Engine*		m_pEngine;
		};
		
		//
		class WIN_Renderer : public Renderer
		{
		public:
			WIN_Renderer(Engine* pEngine = NULL)
			: Renderer(pEngine)
			{ };
			virtual ~WIN_Renderer()
			{ };
		};
		
		//在osx 中flush仅仅只能执行一次
		class OSX_Renderer : public Renderer
		{
		public:
			OSX_Renderer(Engine* pEngine = NULL)
			: Renderer(pEngine)
			{ };
			virtual ~OSX_Renderer()
			{
				glFlush(); //在这个函数之后执行，结束绘图OnEndDraw()
			};
		};
		
		//
#if defined(__APPLE__)
		class RendererT : public OSX_Renderer
#else
		class RendererT : public WIN_Renderer
#endif
		{
		public:
			RendererT(Engine* pEngine = NULL)
#if defined(__APPLE__)
			: OSX_Renderer(pEngine)
#else
			: WIN_Renderer(pEngine)
#endif
			{ }
			virtual ~RendererT()
			{ }
		};
		
	}; //namespace OpenGL
}; //namespace MX

#endif /* __MXOpenGLRenderer_H__ */
