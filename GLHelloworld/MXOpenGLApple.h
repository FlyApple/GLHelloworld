//
//  MXOpenGLUtilApple.h
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXOpenGLApple_H__
#define __MXOpenGLApple_H__


#import <Cocoa/Cocoa.h>

#ifdef __APPLE__

//
typedef CGLContextObj		MX_OSX_OpenGLContext;

//
@interface MX_OSX_OpenGLUtil : NSObject
{
@private
	MX_OSX_OpenGLContext		m_Context;
}

//
@property(assign,readonly) MX_OSX_OpenGLContext context;

//
+(MX_OSX_OpenGLUtil*) SingletonPtr; //定义静态方法

//
-(BOOL) Initialize;
-(BOOL) Release;

-(void) render;

-(void)	draw;

@end


#endif //__APPLE__


//
#endif /* __MXOpenGLApple_H__ */
