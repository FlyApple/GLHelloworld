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

@interface MX_OSX_OpenGLContext : NSObject
{
@private
	CGLPixelFormatObj	m_PixelFormatObj;
	CGLContextObj		m_ContextObj;
}

//
@property(assign,readonly) CGLPixelFormatObj	pixelFormatObj;
@property(assign,readonly) CGLContextObj		contextObj;


-(void) render;

@end


//
@interface MX_OSX_OpenGLUtility : NSObject
{
}

//
+(MX_OSX_OpenGLUtility*) SingletonPtr; //定义静态方法

//
-(BOOL) Initialize;
-(BOOL) Release;

-(void)	draw;

@end


#endif //__APPLE__


//
#endif /* __MXOpenGLApple_H__ */
