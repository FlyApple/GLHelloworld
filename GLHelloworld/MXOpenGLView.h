//
//  MXOpenGLView.h
//  GLHelloworld
//
//  Created by enos sariel on 15/11/21.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "MXOpenGLApple.h"

//
@interface MXOpenGLView : NSOpenGLView
{
@protected
	float					m_fWidth;
	float					m_fHeight;
	
@private
	NSTimer*				m_pTimer;
	MX_OSX_OpenGLContext*	m_pOpenGLContext;
}

-(MX_OSX_OpenGLContext*)getOpenGLContext;
-(BOOL)initializeOpenGL;
-(BOOL)releaseOpenGL;
-(void)render;

@end
