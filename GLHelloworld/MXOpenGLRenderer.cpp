//
//  MXOpenGLRenderer.cpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/28.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "MXOpenGLPrecompile.h"
#include "MXOpenGLRenderer.h"
#include "MXOpenGLDrawable.h"
#include "MXOpenGLEngine.h"


//
namespace MX {
	namespace OpenGL{
		
		//
		bool	Renderer::OnBeginDraw()
		{
			if(m_pEngine)
			{
				m_pEngine->OnClearBackground();
				m_pEngine->OnClearMask();
			}
			return true;
		}
		
		bool	Renderer::OnEndDraw()
		{
			return true;
		}
		
		bool	Renderer::OnDraw(DrawableI* drawableI)
		{
			if(drawableI == NULL){ return false; }
			
			switch(drawableI->FunctionIndex())
			{
				case DrawableFunctionIndex::FunctionIndex_Normal:
				{
					return this->OnDrawBase(drawableI);
					break;
				}
				default:
				{
					break;
				}
			}
			return true;
		}
		
		bool	Renderer::OnDrawBase(DrawableI* drawableI)
		{
			return true;
		}
	}; //namespace OpenGL
}; //namespace MX