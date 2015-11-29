//
//  AppDelegate.h
//  GLHelloworld
//
//  Created by enos sariel on 15/11/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

//
#import <Cocoa/Cocoa.h>
#import "MyOpenGLUtility.h"


//
@interface AppDelegate : NSObject <NSApplicationDelegate>
{
@private
	MyOpenGLUtility*		m_pOpenGLUtility;
}
@end

