//
//  MXOpenGLUtil.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLUtility_H__
#define __MXOpenGLUtility_H__

//
#pragma once

//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//
namespace MX {
	
#define MX_CALLBACK_API
	
	namespace OpenGL{
		
		//
		class Engine;
	
		//
		GLboolean Initialize();
		GLboolean Release();
		
		GLboolean Render();
		
		//
		GLboolean Support();
		
		//
		MX_CALLBACK_API void		ErrorLogI(const char* log);
		MX_CALLBACK_API void		OutputLogI(const char* log);
		
		//
		MX_CALLBACK_API Engine*		CreateEngineI();
		MX_CALLBACK_API GLboolean	DestroyEngineI(Engine* pEngine);
	
	}; //namespace OpenGL
}; //namespace MX

#endif /* __MXOpenGLUtility_H__ */
