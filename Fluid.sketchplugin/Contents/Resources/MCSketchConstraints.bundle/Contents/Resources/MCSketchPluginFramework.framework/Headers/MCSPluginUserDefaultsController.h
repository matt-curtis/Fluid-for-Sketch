//
//  MCSPluginUserDefaultsController.h
//  MCSketchPluginFramework
//
//  Created by Matt Curtis on 11/23/15.
//  Copyright © 2015 Matt. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "MCSPluginUserDefaults.h"


@interface MCSPluginUserDefaultsController : NSUserDefaultsController

	- (MCSPluginUserDefaults*) userDefaultsProxy;

@end