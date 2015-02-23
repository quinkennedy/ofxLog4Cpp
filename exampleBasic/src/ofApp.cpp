#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxLog4Cpp logger;
	logger.init();
	logger.warn() << "HELLO WORLD";
	logger.info() << "This example shows how to use a bunch of the standard stuff in ofxLog4Cpp";
	logger.info() << "Using an instance of the class is probably the most straight forward";
	logger.info() << "You need to 'init' the logger exactly once, before you start logging anywhere";

	logger.warn() << "SCOPING";
	logger.info("", "You can also log without using the stream functionality if you would rather");
	logger.info("", "Be careful when you are not using a stream though");
	logger.info("") << "Because you need to use two arguments, if you use one, you still get a stream";
	logger.info() << "So what is that first argument?";
	logger.info("ofApp.setup") << "It is a way to scope your logs";
	logger.info("interesting") << "Using the more advanced functionality, you can have different logging levels for different scopes";
	logger.info("ofApp.setup", "And here is the scoped version without a stream");
	logger.info("", "When we don't want to use the stream, the empty string represents the 'root' scope.");
	logger.info() << "Just put that in your back pocket for later";

	logger.warn() << "STATIC FUNCTIONS";
	ofxLog4Cpp::info() << "Since all the functions are static, you could just call them directly";
	ofxLog4Cpp::info() << "No need to create an instance of the class.";
	ofxLog4Cpp::info() << "You can throw in logs anywhere in your app, different classes, and they will all log the same";
	ofxLog4Cpp::info() << "No need to pass references around";

	logger.warn() << "PRIORITIES";
	logger.info() << "I have been logging using the INFO priority";
	logger.debug() << "But it is just as easy to log debug statements";
	logger.debug() << "These won't show up in any log output until you change the logger priority";
	logger.setLogPriority(log4cpp::Priority::DEBUG);
	logger.debug() << "Now you can see the DEBUG logs";
	logger.setLogPriority(log4cpp::Priority::WARN);
	logger.info() << "And now you won't even be able to see INFO logs";
	logger.setLogPriority(log4cpp::Priority::INFO);
	logger.log(log4cpp::Priority::CRIT) << "It is also possible to use priorities that don't have an alias";
	logger.log("ofApp.setup", log4cpp::Priority::ALERT) << "And there are a couple of formats for the 'log' method";
	logger.log("ofApp.setup", log4cpp::Priority::FATAL, "As you can see here");

	logger.warn() << "FORMATS";
	logger.info() << "One of the important features of this logger";
	logger.info() << "Is the ability to customize the output format";
	logger.info() << "We have been using the Default layout thus far";
	logger.info() << "Which includes in the log: human-readable timestamp, log level, scope";
	logger.useBasicLayout();
	logger.info() << "There is also a Basic layout";
	logger.info() << "Which is basically the same, using epoch-time and a slightly different format";
	logger.useRawLayout();
	logger.info() << "There is a Raw layout";
	logger.info() << "Which just logs the message and nothing else";
	logger.useJsonLayout();
	logger.info() << "And finally a JSON layout";
	logger.info() << "Which is designed to make it easy to parse the logs programmatically";
	logger.useDefaultLayout();

	logger.warn() << "DESTINATIONS";
	logger.info() << "It is also easy to log to a file vs. the console";
	logger.enableFileLog();
	logger.info() << "Now we are logging to both the console and a file called 'output.log'";
	logger.info() << "We can also selectively disable different log destinations";
	logger.disableConsoleLog();
	logger.info() << "Now logs are only being written to the file, and not the console";
	logger.disableFileLog();
	logger.info() << "It is possible to not have logs go anywhere!";
	logger.info() << "This can easily happen if you don't 'init' the logger like we did above";
	logger.enableConsoleLog();

	logger.warn() << "MIXING FORMATS";
	logger.info() << "We can also use a different format for different log destinations";
	logger.enableFileLog();
	logger.useLayout("file", logger.getJsonLayout());
	logger.info() << "This way you could still have a human-readable layout in the console";
	logger.info() << "And a machine-readable layout in your file";

	logger.warn() << "USING ofLog";
	logger.info() << "We can also use this logger as a channel in the regular oF Log universe";
	shared_ptr<ofxLog4CppChannel> log(new ofxLog4CppChannel());
	ofSetLoggerChannel(log);
	ofLogNotice() << "Now we can use the regular oF logging framework";
	ofLogNotice() << "But still have the power of log4cpp";
	ofLogNotice() << "We are still logging to the console and file";
	ofLogNotice() << "And still using the two different formats";
	ofxLog4Cpp::disableFileLog();
	ofLogNotice() << "And it is just as easy to disable file logging as well";
	ofLogNotice() << "'init' is actually called by the ofxLog4CppChannel constructor";
	ofLogNotice() << "So if you want to use the addon this way, no need to call 'init' yourself";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
