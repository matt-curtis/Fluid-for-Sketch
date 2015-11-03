# :triangular_ruler: Sketch Constraints 1.0

Sketch Constraints is a plugin for Sketch that provides a means to create more constraint-based, responsive designs. It is based on Auto Layout constraints.

:package: [Download Plugin (Zipped)](https://github.com/matt-curtis/Sketch-Constraints/releases/download/v1.0/Sketch-Constraints.sketchplugin.zip) | :arrow_down: [Download the Example Sketch Document](https://github.com/matt-curtis/Sketch-Constraints/raw/master/Constraint%20Demos.sketch)
--- | ---

--

![](README/screenshot.png)

# Installation

1. Download the `.zip` above and extract it.
2. Double-click `Sketch-Constraints.sketchplugin`.
3. ??? Profit.

# Features

- Pin, Offset, Center, and Size relative to Parent Group, Parent Artboard, or Previous Sibling Layer.
- Utilize simple mathematic expressions as values, such as `50% - 10`
- View your artboards at different sizes using Preview Mode [**](#preview-mode)
- Constraints are stored directly on a layer, so no worries with layer names.

# Usage

First and foremost, I recommend downloading the example Sketch document included in this repo and linked to above. I've included several examples there, and examining the constraints used and playing around (ie. changing constraints, resizing Artboards and pressing `Update Layout`) makes things clearer.

There are 3 primary actions: Show/Hide Toolbar, Update Layout, Edit Constraints and Preview. All of the features that the plugin provides are available via `Plugins > Sketch Constraints`.

### Show/Hide Toolbar (⌃ + ⇧ + T)

For convenience, the plugin also provides a toolbar that floats above the current document, giving you quick access to all actions.

![Toolbar](README/toolbar.png)

### Edit Constraints (⌃ + ⇧ + C)

![Constraint Inspector](README/constraint-inspector.png)

This option shows the Constraint Inspector popup. Here you can edit all of the constraints for the currently selected layer.

Next to each section (Align, Fixed Size and Pinning) is a dropdown button. Pressing it opens a menu where you can set relativity:

![Constraint Inspector Relativity](README/constraint-inspector-relativity.png)

### Update Layout (⌃ + ⇧ + L)

Adjusts the layers in the current artboard to reflect your constraints.

### Preview (⌃ + ⇧ + P)

![Preview Mode](README/preview-mode.png)

Opens a window that allows you to preview the currently selected artboard at different sizes. See [notes for more info](#preview-mode).

# Additional Notes

### Preview Mode

Preview Mode is rather limited at this time - it only allows you to preview artboards at a preset number of sizes: Mobile, Tablet and Desktop. Expanding it to include more presets, custom sizes, as well as zooming are WIP.

### Width & Height

If you have Fixed Width or Fixed Height checked and leave the value blank, the plugin will lock the width or height to whatever the current height or width is in Sketch. This is useful in some cases where you want to ensure that the height and width don't change. Less useful for groups, where the height and width are equal to the content (see 'Groups' below)

### Symbols

It's worth noting that while constraints you set on a Symbol *itself* will not propagate to other instances of that Symbol, any constraints you set on its *sub-layers* will.

### Groups

Since the width and height of Groups in Sketch are dependent on their sub-layers, this plugin does not actually resize the height or width of a group, as that would distort the layers in it. Rather, it simulates that sizing when calculating the geometry of sub-layers.

### Text

If you set the width of a text layer but not its height, the plugin will set the height of the text layer to the height of the text after reflow.


# Contact

Questions? Comments? Probably unreciprocated declarations of love? Message & follow me Twitter: [@matt_sven](http://twitter.com/matt_sven)
