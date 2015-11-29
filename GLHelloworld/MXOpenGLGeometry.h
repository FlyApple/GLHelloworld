//
//  MXOpenGL MXOpenGLGeometry Geometry.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/28.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLGeometry_H__
#define __MXOpenGLGeometry_H__

#pragma once


#include "MXOpenGLDrawable.h"

//
namespace MX {
	namespace OpenGL{
		
		//
		class Triangle : public DrawableI
		{
		public:
			Triangle(){ }
			virtual ~Triangle(){ }
		};
		
		
	}; //namespace OpenGL
}; //namespace MX

#endif /* __MXOpenGLGeometry_H__ */
