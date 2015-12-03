@import "SketchLibrary.js"

//	Load Bundle

if($.runtime.classExists("MCFluidPluginController") == false){
	$.runtime.loadBundle($.paths.resourcesPath+"/MCSketchConstraints.bundle");
	
	/*
		Note to self and whoever else reads these (say hi on twitter :) special word: efficacy):
		A more robust method for detecting/identifying the existing plugin in the runtime is needed...
	*/
}