//
//  Utilities.h
//  MCSketchPluginFramework
//
//  Created by Matt Curtis on 10/2/15.
//  Copyright © 2015 Matt. All rights reserved.
//

#import <MCSketchPluginFramework/SketchRuntime.h>

#import "MochaRuntime.h"


#ifndef Utilities_h
#define Utilities_h

#pragma mark -
#pragma mark General

Class GetClass(NSString *className);


#pragma mark -
#pragma mark Mocha

JSContext *JSContextOfMochaObject(MOJavaScriptObject *mochaObject);

JSValue *JSValueFromMochaObject(MOJavaScriptObject *mochaObject);


#pragma mark -
#pragma mark Text

CGFloat Sketch_GetTextHeight(CGFloat desiredTextWidth, MSTextLayer *textLayer);

CGSize Sketch_GetTextSize(MSTextLayer *textLayer);


#pragma mark -
#pragma mark Document

MSDocument *Sketch_GetCurrentDocument();


#pragma mark -
#pragma mark Page

MSPage *Sketch_GetCurrentPage();


#pragma mark -
#pragma mark Undo Registration

void Sketch_DisableUndoRegistration(MSDocument *document);

void Sketch_EnableUndoRegistration(MSDocument *document);

void Sketch_DisableUndoRegistrationInBlock(MSDocument *document, void(^block)());


#pragma mark -
#pragma mark Selection

NSArray *Sketch_GetSelectedLayers(MSDocument *document);

NSArray *Sketch_GetSelectedArtboards(MSDocument *document, BOOL linear, BOOL includeCurrentOrOnly);


#pragma mark -
#pragma mark Artboards

MSArtboardGroup *Sketch_GetCurrentArtboard(MSDocument *document);

MSArtboardGroup *Sketch_GetCurrentOrOnlyArtboard(MSDocument *document);


#pragma mark -
#pragma mark Geometry

CGRect Sketch_MSRectToCGRect(MSRect *rect);

NSRect Sketch_MSRectToNSRect(MSRect *rect);

void Sketch_SetMSRectWithCGRect(MSRect *msrect, CGRect cgrect);

void Sketch_SetMSRectWithNSRect(MSRect *msrect, NSRect nsrect);


CGRect Sketch_GetAbsoluteLayerFrame(MSLayer *layer);

CGRect Sketch_GetLayerFrameInContentDrawView(MSLayer *layer);

CGRect Sketch_GetLayerFrameInWindow(MSLayer *layer, MSDocument *document);

CGRect Sketch_GetLayerFrameInScreen(MSLayer *layer, MSDocument *document);


#pragma mark -
#pragma mark Layer to Images

NSData *Sketch_GetImageDataFromLayer(MSLayer *layer, double scale);

NSImage *Sketch_GetImageFromLayer(MSLayer *layer, double scale);

#endif /* Utilities_h */
