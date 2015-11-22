
//
//  MXOpenGLWapper.hpp
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLPrecompile_H__
#define __MXOpenGLPrecompile_H__

//
//opengl

//
#define GLEW_STATIC
#define GLEW_NO_GLU
#include <GL/glew.h>

//仅仅用于msvc
//VC++ 13.0 _MSC_VER = 1900 (Visual C++ 2015)
//VC++ 12.0 _MSC_VER = 1800 (Visual C++ 2013)
//VC++ 11.0 _MSC_VER = 1700 (Visual C++ 2012)
//VC++ 10.0 _MSC_VER = 1600 (Visual C++ 2010)
//VC++ 9.0  _MSC_VER = 1500 (Visual C++ 2008)
//VC++ 8.0  _MSC_VER = 1400 (Visual C++ 2005)
//VC++ 7.1  _MSC_VER = 1310 (Visual C++ 2003)
#if defined(_MSC_VER)
#ifdef _DEBUG
#pragma comment(lib, "libglew_d.lib")
#else //_DEBUG
#pragma comment(lib, "libglew.lib")
#endif //_DEBUG
#elif defined(__GNUC__)

#ifdef __APPLE__
//#include <OpenGL/gl3.h>
//#include <OpenGL/gl3ext.h>
#endif //__APPLE__

#endif //_MSC_VER


//
#endif /* __MXOpenGLPrecompile_H__ */
