//
//  SketchLibrary.js
//
//  Created by Matt Curtis
//  Copyright (c) 2015. All rights reserved.
//

(function(){
	var global = this;

	//
	//	EXTEND DEFAULT OBJECTS
	//	----------------------
	//

	String.prototype.toNSString = function(){
		return NSString.alloc().initWithString(this+"");
	};

	//
	//	INTERNAL UTILITIES
	//	------------------
	//

	var createProp = function(object, propertyName, config){
		if(typeof config.enumerable == "undefined"){
			config.enumerable = true;
		}

		Object.defineProperty(object, propertyName, config);
	};

	//
	//	DEFINE CORE
	//	-----------
	//

	var core = function(layer){
		return new LayerWrapper(layer);
	};

	global.$ = core;

	//
	//	CONTEXT
	//	-------
	//

	var ctx;

	createProp(core, "context", {
		get: function(){
			return ctx;
		},

		set: function(value){
			ctx = value;
		}
	});

	createProp(core, "ctx", {
		get: function(){
			return ctx;
		},

		set: function(value){
			ctx = value;
		}
	});

	//
	//	LAYER WRAPPER
	//	-------------
	//

	var LayerWrapper = function(layer){
		//
		//	STATIC VARIABLES
		//	----------------
		//

		this.layer = layer;

		this.className = layer.class()+"";

		this.canHaveLayers = (layer.layers != null);

		this.isGroup = (this.className == "MSLayerGroup");
		this.isArtboard = (this.className == "MSArtboardGroup");
		this.isText = (this.className == "MSTextLayer");

		//
		//	PROPERTIES
		//	----------
		//

		//	Frame

		createProp(this, "frame", {
			get: function(){
				return layer.frame();
			},
			set: function(frame){
				this.setFrame(frame);
			}
		});

		//
		//	FUNCTIONS
		//	---------
		//

		//	Data Storage & Retrieval

		this.data = function(key, value){
			return this.dataFromPlugin(null, key, value);
		};

		this.dataFromPlugin = function(pluginId, key, value){
			var command = ctx.command;

			//	Read

			if(typeof value != "undefined"){
				if(pluginId){
					return [command valueForKey:key onLayer:layer forPluginIdentifier:pluginId];
				} else {
					return [command valueForKey:key onLayer:layer];
				}
			}

			//	Write

			if(pluginId){
				[command setValue:value forKey:key onLayer:layer forPluginIdentifier:pluginId];
			} else {
				[command setValue:value forKey:key onLayer:layer];
			}
		};

		//	Frame

		this.setFrame = function(){
			var args = arguments;
			var layerFrame = layer.frame();

			if(args.length == 1 && typeof args[0] == "object"){
				var frame = args[0];

				for(var prop in frame){
					layerFrame[prop] = frame[prop];
				}
			} else if(args.length > 0){
				var order = ["x", "y", "width", "height"];

				for(var i in args){
					var prop = order[i];
					layerFrame[prop] = Number(args[i]);
				}
			}
		};
	};

	//
	//	UTILITIES
	//	---------
	//

	//	JS

	var js = core.js = {};

	js.execute = function(js, basePath){
		var baseURL;

		if(!basePath){
			baseURL = coscript.env().scriptURL;
		} else {
			baseURL = [NSURL fileURLWithPath:basePath];
		}

		[coscript executeString:js baseURL:baseURL];
	};

	js.executeFile = function(filePath){
		var scriptURL = coscript.env().scriptURL, scriptPath = scriptURL.path();

		var jsPath = scriptPath.stringByDeletingLastPathComponent()+"/commands.js";
		var script = [NSString stringWithContentsOfFile:jsPath encoding:NSUTF8StringEncoding error:nil];

		js.execute(script, jsPath);
	};

	//	Paths

	var paths = core.paths = {};

	createProp(paths, "scriptPath", {
		get: function(){
			return coscript.env().scriptURL.path()+"";
		}
	});

	createProp(paths, "scriptFolderPath", {
		get: function(){
			return paths.scriptPath.toNSString().stringByDeletingLastPathComponent()+"";
		}
	});

	paths.pluginPath = (function(){
		var NSScriptPath = paths.scriptPath.toNSString();

		while(NSScriptPath.lastPathComponent().pathExtension() != "sketchplugin"){
			NSScriptPath = NSScriptPath.stringByDeletingLastPathComponent();
		}

		return NSScriptPath+"";
	})();

	paths.resourcesPath = paths.pluginPath+"/Contents/Resources";

	paths.joinPathComponents = function(){
		var args = arguments;

		if(args.length == 0) return;

		var path = NSString.new();

		for(var i = 0, len = args.length; i<len; i++){
			path = [path stringByAppendingPathComponent:args[i]];
		}

		return path+"";
	};

	//	Web

	var web = core.web = {};

	web.joinURLComponents = function(){
		var args = arguments;

		if(args.length == 0) return;

		var URL = [NSURL URLWithString:args[0]];

		if(!URL) return;

		for(var i = 1, len = args.length; i<len; i++){
			URL = [URL URLByAppendingPathComponent:args[i]];
		}

		return URL;
	};

	//	Utility Properties

	createProp(core, "doc", {
		get: function(){
			return ctx.document;
		}
	});

	createProp(core, "page", {
		get: function(){
			return ctx.document.currentPage();
		}
	});

	createProp(core, "artboards", {
		get: function(){
			return core.page.artboards();
		}
	});

	createProp(core, "artboard", {
		get: function(){
			var artboards = core.artboards, numberOfBoards = artboards.count();

			if(numberOfBoards == 0) return;
			if(numberOfBoards == 1) return artboards.firstObject();

			var selection = $.selection, firstLayer = selection.firstObject();

			if(!firstLayer) return;
			if(firstLayer.class()+"" == "MSArtboardGroup") return firstLayer;

			var artboard, layer = firstLayer;

			while(layer){
				if(layer.class()+"" == "MSArtboardGroup"){
					return layer;
				}

				layer = layer.parentGroup();
			}
		}
	});

	createProp(core, "selection", {
		get: function(){
			return ctx.selection;
		}
	});

	createProp(core, "command", {
		get: function(){
			return ctx.command;
		}
	});

	//	Files

	var files = core.files = {};

	files.getFileContents = function(filePathOrURL){
		var url = [NSURL URLWithString:filePathOrURL];
		if(url && url.isFileURL) filePathOrURL = url.path;
		
		var fileData = [NSString stringWithContentsOfFile:filePathOrURL encoding:NSUTF8StringEncoding error:nil];
		
		return fileData;
	};

	//	Utility Functions

	core.refresh = function(){
		core.doc.currentView().refresh();
	};

	core.alert = function(message, title){
		if(!message) message = "";

		var alert = NSAlert.new();
		
		alert.messageText = title || "Alert";
		alert.informativeText = message;
		
		alert.runModal();
	};

	core.prompt = function(promptTitle, defaultValue){
		if(!defaultValue) defaultValue = "";

		var alert = [NSAlert
			alertWithMessageText:promptTitle
			defaultButton:"OK"
			alternateButton:"Cancel"
			otherButton:nil
			informativeTextWithFormat:""];

		var input = [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 200, 24)];

		[input setStringValue:defaultValue];
		[alert setAccessoryView:input];
		[input selectText:nil];

		var pressedButtonIndex = [alert runModal];

		if(pressedButtonIndex == NSAlertDefaultReturn){
			[input validateEditing];

			return [input stringValue]+"";
		} else {
			return null;
		}
	};

	//	Runtime

	var runtime = core.runtime = {};

	runtime.loadFramework = function(frameworkName, directory){
		var mocha = Mocha.sharedRuntime();

		return [mocha loadFrameworkWithName:frameworkName inDirectory:directory];
	};

	runtime.loadBundle = function(bundlePath){
		var bundle = NSBundle.bundleWithPath(bundlePath);
		
		if(bundle.isLoaded) bundle.unload();
		
		bundle.load();
		
		return bundle;
	};

	runtime.classExists = function(className){
		return NSClassFromString(className) != null;
	};

	//	Commands

	var commands = core.commands = {};

	commands.createCommand = function(commandName, functionToCall){
		var dynFunc = function(ctx){
			core.context = ctx;

			functionToCall(ctx);
		};

		global["command_"+commandName] = dynFunc;

		return dynFunc;
	};

})();