@import 'SketchLibrary.js'

//	Load Bundle

if($.runtime.classExists("MCSConstraintsPluginController") == false){
	$.runtime.loadBundle($.paths.resourcesPath+"/MCSketchConstraints.bundle");
}

//	Plugin Methods

//	...