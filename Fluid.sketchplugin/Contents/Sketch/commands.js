@import "main.js"

//	-------
//	ACTIONS
//	-------

function selectionDidChange(ctx){
	getPluginController(ctx).currentSelectionDidChange();
};

function artboardDidChange(ctx){
	getPluginController(ctx).currentDocumentDidChange();
};

//	--------
//	COMMANDS
//	--------

$.commands.createCommand("toggleToolbarVisiblity", function(ctx){
	var pluginController = getPluginController(ctx);

	pluginController.toggleToolbarVisiblity();
});

$.commands.createCommand("editConstraints", function(ctx){
	var pluginController = getPluginController(ctx);

	pluginController.showConstraintInspector();
});

$.commands.createCommand("updateLayout", function(ctx){
	var pluginController = getPluginController(ctx);

	pluginController.updateLayout();
});

$.commands.createCommand("preview", function(ctx){
	var pluginController = getPluginController(ctx);

	pluginController.preview();
});

$.commands.createCommand("toggleArtboardSize", function(ctx){
	var pluginController = getPluginController(ctx);

	pluginController.showArtboardSizePresetsPopover();
});

$.commands.createCommand("showSettingsWindow", function(ctx){
	var pluginController = getPluginController(ctx);

	pluginController.showSettingsWindow();
});