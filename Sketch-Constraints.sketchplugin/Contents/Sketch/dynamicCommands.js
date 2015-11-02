//	Import commands.js. Gets around the caching Sketch does.

var scriptURL = coscript.env().scriptURL, scriptPath = scriptURL.path();

var jsPath = scriptPath.stringByDeletingLastPathComponent()+"/commands.js";
var js = [NSString stringWithContentsOfFile:jsPath encoding:NSUTF8StringEncoding error:nil];

var mainScriptURL = [NSURL fileURLWithPath:jsPath];

[coscript executeString:js baseURL:mainScriptURL];