//
//  MCSPluginController.h
//  MCSketchPluginFramework
//
//  Created by Matt Curtis on 10/11/15.
//  Copyright © 2015 Matt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SketchRuntime.h"

#import "MochaRuntime.h"

#import "MCSPluginUserDefaults.h"

#import "MCSPluginUpdater.h"


//	Notifications

extern NSString *const MCSPluginSelectionDidChangeNotification;

extern NSString *const MCSPluginCurrentArtboardDidChangeNotification;

extern NSString *const MCSPluginCurrentDocumentDidChangeNotification;

extern NSString *const MCSPluginAllDocumentsClosedNotification;

//	Notification Keys

extern NSString *const MCSPluginNotificationDocumentKey;

extern NSString *const MCSPluginNotificationDocumentWindowKey;


@interface MCSPluginController : NSObject

	@property (nonatomic, readonly) NSString *loadedVersion;


	@property (nonatomic) MSPluginCommand *pluginCommand;

	@property (nonatomic) MSPluginBundle *plugin;

	@property (nonatomic, readonly) MCSPluginUserDefaults *userDefaults;

	@property (nonatomic, readonly) MCSPluginUpdater *updater;


	+ (instancetype) pluginController:(MSPluginBundle*)plugin pluginCommand:(MSPluginCommand*)pluginCommand;

	+ (instancetype) pluginController;


	+ (NSAlert*) alertWithTitle:(NSString*)title information:(NSString*)information run:(BOOL)run;

	+ (NSAlert*) alertWithTitle:(NSString*)title information:(NSString*)information;


	- (void) applicationDidBecomeActive;


	- (void) allDocumentsDidClose;

	- (void) currentDocumentDidChange:(NSNotification*)notification;

	- (void) currentSelectionDidChange:(NSNotification*)notification;

	- (void) currentArtboardDidChange:(NSNotification*)notification;

@end
