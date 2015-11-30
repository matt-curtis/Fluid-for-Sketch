@import "main.js"

//	--------
//	COMMANDS
//	--------

$.commands.createCommand("toggleToolbarVisiblity", function(ctx){
	var pluginController = [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];

	pluginController.toggleToolbarVisiblity();
});

$.commands.createCommand("editConstraints", function(ctx){
	var pluginController = [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];

	pluginController.showConstraintInspector();
});

$.commands.createCommand("updateLayout", function(ctx){
	var pluginController = [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];

	pluginController.updateLayout();
});

$.commands.createCommand("preview", function(ctx){
	var pluginController = [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];

	pluginController.preview();
});

$.commands.createCommand("toggleArtboardSize", function(ctx){
	var pluginController = [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];

	pluginController.showArtboardSizePresetsPopover();
});

$.commands.createCommand("showSettingsWindow", function(ctx){
	var pluginController = [MCFluidPluginController pluginController:ctx.plugin pluginCommand:ctx.command];

	pluginController.showSettingsWindow();
});