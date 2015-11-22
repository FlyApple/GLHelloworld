//
//  MyOpenGLEngine.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/22.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef MyOpenGLEngine_hpp
#define MyOpenGLEngine_hpp

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

#endif /* MyOpenGLEngine_hpp */
