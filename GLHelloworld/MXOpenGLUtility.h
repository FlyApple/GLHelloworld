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
	namespace OpenGL{
		
		//
#if defined(__GNUC__)
		#define MX_OPENGL_CALLBACK
#elif defined(_MSC_VER)
		#define MX_OPENGL_CALLBACK		__stdcall
#else
		#define MX_OPENGL_CALLBACK
#endif

		//
		#define MX_OPENGL_DELETE_POINTER(pointer) if(pointer){ delete pointer; pointer = NULL; }
		
		//
		template<typename _Ty>
		class Singleton
		{
		public:
			Singleton()
			{
				ms_Singleton	= (_Ty*)this;
			}
			virtual ~Singleton()
			{
				ms_Singleton	= NULL;
			}
			
			static _Ty*		getSingletonPtr(){ return ms_Singleton; }
			static _Ty&		getSingleton(){ return *ms_Singleton; }
		private:
			static _Ty*		ms_Singleton;
		};
		#define SINGLETON_IMPLE(_Ty)	template<typename _Ty>	_Ty* Singleton<_Ty>::ms_Singleton = NULL;
	
		//
		typedef void (MX_OPENGL_CALLBACK *CallbackOutput)(const char* text);
		
		//
		class Utility : public Singleton<Utility>
		{
		public:
			Utility();
			virtual ~Utility();
			
			virtual bool	Initialize();
			virtual bool	Release();
			
		public:
			bool	Support();
			
			void	ErrorLog(const char* format, ...);
			void	OutputLog(const char* format, ...);
			
			void	SetCallbackOutput(CallbackOutput func){ m_fnCallbackOutput = func; }
			void	SetCallbackError(CallbackOutput func){ m_fnCallbackError = func; }
		private:
			CallbackOutput		m_fnCallbackOutput;
			CallbackOutput		m_fnCallbackError;
		};
		
	
	}; //namespace OpenGL
}; //namespace MX

#endif /* __MXOpenGLUtility_H__ */
