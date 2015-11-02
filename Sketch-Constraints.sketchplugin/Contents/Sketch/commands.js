@import "main.js"

//	--------
//	COMMANDS
//	--------

$.commands.createCommand("toggleToolbarVisiblity", function(ctx){
	var pluginController = MCSConstraintsPluginController.pluginController_(ctx.command);

	pluginController.toggleToolbarVisiblity();
});

$.commands.createCommand("editConstraints", function(ctx){
	var pluginController = MCSConstraintsPluginController.pluginController_(ctx.command);

	pluginController.showConstriantInspectorUnderMouse();
});

$.commands.createCommand("updateLayout", function(ctx){
	var pluginController = MCSConstraintsPluginController.pluginController_(ctx.command);

	pluginController.updateLayout();
});

$.commands.createCommand("preview", function(ctx){
	var pluginController = MCSConstraintsPluginController.pluginController_(ctx.command);

	pluginController.preview();
});