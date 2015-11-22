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
		class Drawable
		{
		public:
			Drawable() { };
			virtual ~Drawable() { };
			
			virtual void OnDraw() { };
		};
		
		//在osx 中flush仅仅只能执行一次
		class OSX_Drawable : public Drawable
		{
		public:
			OSX_Drawable() {};
			virtual ~OSX_Drawable()
			{
				glFlush();
			};
		};
		
		//
#if defined(__APPLE__)
		class DrawableT : public OSX_Drawable
#else
		class DrawableT : public Drawable
#endif
		{
		public:
			DrawableT(float r = 0.0f, float g = 0.0f, float b = 0.1f, float a = 0.0f,
					  GLbitfield mask = GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT)
			{
				glClearColor(r, g, b, a);
				glClear(mask);
			}
			virtual ~DrawableT()
			{
			}
		};
		
		//
		class Engine
		{
		public:
			Engine();
			virtual ~Engine();
			
			//
			GLboolean	Initialize();
			GLboolean	Release();
			
			GLvoid		Render();
			
		protected:
			
		};

	}; //namespace OpenGL
}; //namespace MX



#endif /* __MXOpenGLEngine_H__*/
