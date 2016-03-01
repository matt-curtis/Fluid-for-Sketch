//
//  MochaRuntime.h
//  MCSketchPluginFramework
//
//  Created by Matt Curtis on 10/2/15.
//  Copyright © 2015 Matt. All rights reserved.
//

#import <AppKit/AppKit.h>

#import <JavaScriptCore/JavaScriptCore.h>


#define MOJavaScriptObject_Class GetClass(@"MOJavaScriptObject")

@interface MOJavaScriptObject : NSObject

	@property (readonly) JSObjectRef JSObject;
	
	@property (readonly) JSContextRef JSContext;

@end