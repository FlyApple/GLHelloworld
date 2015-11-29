//
//  AppDelegate.m
//  GLHelloworld
//
//  Created by enos sariel on 15/11/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "AppDelegate.h"

//
@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationWillFinishLaunching:(NSNotification *)aNotification
{
	m_pOpenGLUtility = [[MyOpenGLUtility new] init];
	if(![m_pOpenGLUtility Initialize])
	{
		NSLog(@"<%s> OpenGLUtil initialize fail.", __FUNCTION__);
		return;
	}
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
	// Insert code here to tear down your application
	if(m_pOpenGLUtility)
	{
		if(![m_pOpenGLUtility Release])
		{
			NSLog(@"<%s> OpenGLUtil initialize release.", __FUNCTION__);
		}
		m_pOpenGLUtility = nil;
	}
}

// 再关闭主窗口时退出程序，嗯就这酱紫的。
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
	return YES;
}


@end
