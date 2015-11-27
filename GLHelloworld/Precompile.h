//
//  Precomplie.h
//  GLHelloworld
//
//  Created by enos sariel on 15/11/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __Precomplie_H__
#define __Precomplie_H__

#pragma once

//
#include <stdio.h>
#include <stdlib.h>


//
#include "MXOpenGLPrecompile.h"

//
#if defined(__GNUC__)

#define TErrorLog(x,...)	\
	if(MX::OpenGL::Utility::getSingletonPtr()) \
	{ MX::OpenGL::Utility::getSingletonPtr()->ErrorLog(x, __VA_ARGS__); }
#define TOutputLog(x,...)	\
	if(MX::OpenGL::Utility::getSingletonPtr()) \
	{ MX::OpenGL::Utility::getSingletonPtr()->OutputLog(x, __VA_ARGS__); }

#else

#define TErrorLog(x,...)	\
	if(MX::OpenGL::Utility::getSingletonPtr()) \
	{ MX::OpenGL::Utility::getSingletonPtr()->ErrorLog(x, __VA_ARGS__); }
#define TOutputLog(x,...)	\
	if(MX::OpenGL::Utility::getSingletonPtr()) \
	{ MX::OpenGL::Utility::getSingletonPtr()->OutputLog(x, __VA_ARGS__); }

#endif

#define ERROR_LOG	TErrorLog
#define OUTPUT_LOG	TOutputLog

//
#endif /* __Precomplie_H__ */
