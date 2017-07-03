//
//  Sketch.h
//
//  Created by Matt Curtis on 9/9/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AppKit/AppKit.h>


#pragma mark -
#pragma mark Foward Classes

@class MSPage, MSLayer, MSArtboardGroup, MSContentDrawView, MSArray, MSLayerGroup, MSDocumentWindow;


#pragma mark -
#pragma mark Protocols

@protocol MSPageDelegate <NSObject>

	- (void) layerSelectionDidChange;

	- (void) currentArtboardDidChange;

@end


#pragma mark -
#pragma mark Data Structures

#define MSArray_Class GetClass(@"MSArray")

@interface MSArray : NSObject <NSFastEnumeration>

	@property (readonly, copy, nonatomic) NSArray *array;

@end

#define MSLayerArray_Class GetClass(@"MSLayerArray")

@interface MSLayerArray : NSObject <NSFastEnumeration>

	@property (copy, nonatomic) NSArray *layers;

	+ (instancetype) arrayWithLayers:(NSArray*)layers;

@end


#pragma mark -
#pragma mark Event Handler

#define MSEventHandler_Class GetClass(@"MSEventHandler")

@interface MSEventHandler : NSObject

	- (void) writeLayers:(MSLayerArray*)layers toPasteboard:(NSPasteboard*)pasteboard;

@end

#define MSEventHandlerManager_Class GetClass(@"MSEventHandlerManager")

@interface MSEventHandlerManager : NSObject

	//@property (nonatomic) MSNormalEventHandler *normalHandler;
	@property (nonatomic) MSEventHandler *normalHandler;

@end



#pragma mark -
#pragma mark Document Classes

#define MSDocument_Class GetClass(@"MSDocument")

@interface MSDocument : NSDocument <MSPageDelegate>

	- (void) saveArtboardOrSlice:(id)artboardOrSlice toFile:(NSString*)filePath;

	- (MSPage*) currentPage;

	- (void) setCurrentPage:(MSPage*)page;

	- (NSArray*) pages;


	- (MSEventHandler*) currentHandler;


	@property (retain, nonatomic) MSEventHandlerManager *eventHandlerManager;


	- (MSDocumentWindow*) window;

	+ (MSDocument*) currentDocument;

	- (NSArray*) selectedLayers;


	- (MSContentDrawView*) currentView;


	- (NSUndoManager*) undoManager;

@end

#define MSRect_Class GetClass(@"MSRect")

@interface MSRect : NSObject

	@property (nonatomic) double y;
	@property (nonatomic) double x;
	@property (nonatomic) double width;
	@property (nonatomic) double height;

	@property (nonatomic) CGPoint origin;
	@property (nonatomic) CGSize size;
	@property (nonatomic) CGRect rect;

	@property (nonatomic) BOOL constrainProportions;

	- (instancetype) scaleBy:(double)scaleBy;

	- (void) makeRectIntegral;

	- (void) makeOriginIntegral;

@end

#define MSAbsoluteRect_Class GetClass(@"MSAbsoluteRect")

@interface MSAbsoluteRect : NSObject

	- (CGRect) rect;

@end

#define MSLayer_Class GetClass(@"MSLayer")

@interface MSLayer : NSObject

	@property (nonatomic) NSString *name;

	@property (readonly, nonatomic) BOOL nameIsFixed;


	@property (nonatomic) id sharedObjectID;

	@property (readonly, copy, nonatomic) NSObject<NSCopying, NSCoding> *objectID;

	@property (readonly, nonatomic) NSObject<NSCopying, NSCoding> *originalObjectID;


	@property (nonatomic) CGPoint origin;

	@property (nonatomic) CGRect rect;

	@property (retain, nonatomic) MSRect *frame;

	@property (nonatomic) MSAbsoluteRect *absoluteRect;


	@property (nonatomic) BOOL isSelected;

	@property (nonatomic) BOOL isHovering;


	- (void) select:(BOOL)select byExpandingSelection:(BOOL)expandSelection showSelection:(BOOL)showSelection;

	- (void) select:(BOOL)select byExpandingSelection:(BOOL)expandSelection;


	- (MSLayerGroup*) parentGroup;

	- (MSPage*) parentPage;

	- (MSArtboardGroup*) parentArtboard;


	- (instancetype) duplicate;


	- (void) removeFromParent;


	- (BOOL) isSharedObject;

	- (BOOL) isSymbol;

	- (BOOL) containsSymbols;

	- (BOOL) parentOrSelfIsSymbol;

@end

#define MSLayerGroup_Class GetClass(@"MSLayerGroup")

@interface MSLayerGroup : MSLayer

	@property (nonatomic) MSArray *layers;

	- (void) removeAllLayers;
	- (void) removeLayerAtIndex:(NSInteger)index;
	- (void) removeLayer:(MSLayer*)layer;

	- (void) insertLayers:(NSArray*)layers atIndex:(NSInteger)index;
	- (void) insertLayers:(NSArray*)layers afterLayer:(MSLayer*)afterLayer;
	- (void) insertLayers:(NSArray*)arg1 beforeLayer:(MSLayer*)beforeLayer;

	- (void) replaceLayersWithLayers:(NSArray*)layers;
	- (void) addLayers:(NSArray*)layers;

	- (MSLayer*) addLayerOfType:(NSString*)type;

	- (BOOL) resizeToFitChildrenWithOption:(long long)arg1;

@end

#define MSPage_Class GetClass(@"MSPage")

@interface MSPage : MSLayerGroup <MSPageDelegate>

	@property (nonatomic) double zoomValue;

	@property(nonatomic) CGPoint scrollOrigin;

	- (NSArray*) artboards;

	- (MSArtboardGroup*) currentArtboard;

@end

#define MSExportFormat_Class GetClass(@"MSExportFormat")

@interface MSExportFormat : NSObject

	+ (instancetype) formatWithScale:(double)scale name:(NSString*)name fileFormat:(NSString*)fileFormat;

@end

#define MSExportRequest_Class GetClass(@"MSExportRequest")

@interface MSExportRequest : NSObject

	+ (NSArray*) exportRequestsFromExportableLayer:(MSLayer*)layer exportFormats:(NSArray*)formats useIDForName:(BOOL)useIDForName;

	@property (nonatomic) BOOL includeArtboardBackground;

@end

#define MSExporter_Class GetClass(@"MSExporter")

@interface MSExporter : NSObject

	+ (instancetype) exporterForRequest:(MSExportRequest*)exportRequest colorSpace:(NSColorSpace*)colorSpace;

	- (NSData*) PNGData;

@end

#define MSArtboardGroup_Class GetClass(@"MSArtboardGroup")

@interface MSArtboardGroup : MSLayerGroup

	@property (nonatomic) BOOL includeBackgroundColorInExport;
	@property (nonatomic) BOOL hasBackgroundColor;

@end

#define MSTextLayer_Class GetClass(@"MSTextLayer")

@interface MSTextLayer : MSLayer

	@property (nonatomic) double fontSize;

	@property (nonatomic, copy) NSAttributedString *attributedStringValue;

@end

#define MSShapeGroup_Class GetClass(@"MSShapeGroup")

@interface MSShapeGroup : MSLayerGroup

	- (void) prepareAsMask;

@end


#pragma mark -
#pragma mark Plugins

#define MSPluginCommand_Class GetClass(@"MSPluginCommand")

@interface MSPluginCommand : NSObject

	//	Supports arrays, dictionaries, numbers and strings

	- (void) setValue:(id)value forKey:(NSString*)key onLayer:(MSLayer*)layer;
	- (id) valueForKey:(NSString*)key onLayer:(MSLayer*)layer;

	- (void) setValue:(id)value forKey:(NSString*)key onLayer:(MSLayer*)layer forPluginIdentifier:(NSString*)pluginIdentifier;
	- (id) valueForKey:(NSString*)key onLayer:(MSLayer*)layer forPluginIdentifier:(NSString*)pluginIdentifier;

@end

#define MSPluginBundle_Class GetClass(@"MSPluginBundle")

@interface MSPluginBundle : NSObject

	@property (readonly, nonatomic) NSURL *manifestURL;
	@property (readonly, nonatomic) NSString *authorEmail;
	@property (readonly, nonatomic) NSString *author;
	@property (readonly, nonatomic) NSURL *homepageURL;
	@property (readonly, nonatomic) NSString *pluginDescription;
	@property (readonly, nonatomic) NSString *identifier;
	@property (readonly, nonatomic) NSString *name;
	@property (readonly, nonatomic) NSString *version;
	@property (readonly, nonatomic) NSDictionary *commands;
	@property (readonly, nonatomic) NSURL *url;
	
	- (id) urlForResourceNamed:(NSString*)resourceName;

@end

#define MSPluginManager_Class GetClass(@"MSPluginManager")

@interface MSPluginManager : NSObject

	+ (id) pluginsURL;

	@property (readonly, copy, nonatomic) NSURL *pluginsFolderURL; // @synthesize pluginsFolderURL=_pluginsFolderURL;
	@property (copy, nonatomic) NSDictionary *plugins;

	- (void) reloadPlugins;
	- (NSDictionary*) pluginsFromFolderAtURL:(NSURL*)url visitedURLs:(NSArray*)visitedURLs relativeFolderPath:(NSString*)relativeFolderPath;

@end


#pragma mark -
#pragma mark Interface Classes

#define MSDocumentWindow_Class GetClass(@"MSDocumentWindow")

@interface MSDocumentWindow : NSWindow

@end

#define MSContentDrawView_Class GetClass(@"MSContentDrawView")

@interface MSContentDrawView : NSView

@end


#pragma mark -
#pragma mark Application

@interface AppController : NSObject <NSApplicationDelegate>

	@property (retain, nonatomic) MSPluginManager *pluginManager;

	//@property (retain, nonatomic) MSPasteboardManager *pasteboardManager;

@end

#define MSArtboardPresetStore_Class GetClass(@"MSArtboardPresetStore")

@interface MSArtboardPresetStore : NSObject

	+ (NSURL*) systemPresetsURL;
	- (NSURL*) userPresetsURL;

@end
