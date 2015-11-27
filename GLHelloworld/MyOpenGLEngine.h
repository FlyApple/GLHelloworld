//
//  MyOpenGLEngine.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MyOpenGLEngine_H__
#define __MyOpenGLEngine_H__

#include "MXOpenGLEngine.h"


//
using namespace MX;

//
class MyOpenGLEngine : public MX::OpenGL::Engine
{
public:
	MyOpenGLEngine();
	virtual ~MyOpenGLEngine();
	
	//
	GLboolean	Initialize();
	GLboolean	Release();
};


//
#endif /* __MyOpenGLEngine_H__ */
