//
//  AppDelegate.m
//  GLHelloworld
//
//  Created by enos sariel on 15/11/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "AppDelegate.h"
#import "MXOpenGLApple.h"

//
@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationWillFinishLaunching:(NSNotification *)aNotification
{
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
	// Insert code here to tear down your application
	
	if([MX_OSX_OpenGLUtil SingletonPtr])
	{
		[[MX_OSX_OpenGLUtil SingletonPtr] Release];
	}
}

// 再关闭主窗口时退出程序，嗯就这酱紫的。
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
	return YES;
}


@end
