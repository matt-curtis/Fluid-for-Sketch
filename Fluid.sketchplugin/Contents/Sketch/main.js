@import "SketchLibrary.js"

//	Load Bundle

if($.runtime.classExists("MCFluidPluginController") == false){
	$.runtime.loadBundle($.paths.resourcesPath+"/Fluid.bundle");
	
	/*
		Note to self and whoever else reads these (say hi on twitter :) special word: loneliness):
		A more robust method for detecting/identifying the existing plugin in the runtime is needed...
	*/
}

//	Controller

var getPluginController = function(ctx){
	return [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];
};