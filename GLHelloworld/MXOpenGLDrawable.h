//
//  MXOpenGLDrawable.h
//  GLHelloworld
//
//  Created by enos sariel on 15/11/28.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLDrawable_H__
#define __MXOpenGLDrawable_H__

#pragma once

//
namespace MX {
	namespace OpenGL{
		
		//
		enum  DrawableFunctionIndex
		{
			FunctionIndex_Normal,
			FunctionIndex_Max,
		};
		
		//
		class DrawableI
		{
		public:
			DrawableI()
			{
				m_FunctionIndex = FunctionIndex_Normal;
			}
			virtual ~DrawableI(){ }
			
			DrawableFunctionIndex	FunctionIndex() { return m_FunctionIndex; }
			
		protected:
			DrawableFunctionIndex	m_FunctionIndex;
			void					FunctionIndex(DrawableFunctionIndex function_index){ m_FunctionIndex = function_index; }
			
		private:
			
		};
		
		
	}; //namespace OpenGL
}; //namespace MX

#endif /* __MXOpenGLDrawable_H__ */
