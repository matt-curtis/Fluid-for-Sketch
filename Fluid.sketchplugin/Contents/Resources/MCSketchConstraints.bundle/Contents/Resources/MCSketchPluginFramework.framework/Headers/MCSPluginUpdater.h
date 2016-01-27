//
//  MCSPluginUpdater.h
//  MCSketchPluginFramework
//
//  Created by Matt Curtis on 11/23/15.
//  Copyright © 2015 Matt. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MCSPluginUpdater : NSObject

	@property (nonatomic) NSString *pluginIdentifier;

	- (BOOL) isNewerPluginBundleAvailableLocally:(NSString*)loadedVersion;

	- (void) showUpdateRestartPrompt;

	- (void) relaunchSketch;

@end