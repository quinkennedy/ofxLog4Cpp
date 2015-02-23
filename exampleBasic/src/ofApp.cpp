#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxLog4Cpp::init();
	ofxLog4Cpp::debug() << "this message won't show up";
	ofxLog4Cpp::setLogPriority(log4cpp::Priority::DEBUG);
	ofxLog4Cpp::debug() << "this will show up";
	ofxLog4Cpp::setLogPriority(log4cpp::Priority::INFO);
	ofxLog4Cpp::info() << "now you should know how to change log levels";
	ofxLog4Cpp::info() << "you can also change the format";
	ofxLog4Cpp::useBasicLayout();
	ofxLog4Cpp::info() << "to use the basic layout";
	ofxLog4Cpp::useJsonLayout();
	ofxLog4Cpp::info() << "or the json layout for automated processing";
	ofxLog4Cpp::useRawLayout();
	ofxLog4Cpp::info() << "... the raw layout for just messages";
	ofxLog4Cpp::useDefaultLayout();
	ofxLog4Cpp::info() << "or just be content with the default";
	ofxLog4Cpp::info("setup") << "and here is scoped logging";
	ofxLog4Cpp::enableFileLog();
	ofxLog4Cpp::info() << "now lets try logging to a file";
	ofxLog4Cpp::disableConsoleLog();
	ofxLog4Cpp::info() << "and stop logging to the console";
	ofxLog4Cpp::enableConsoleLog();
	ofxLog4Cpp::info() << "ok, we can log to both";
	ofxLog4Cpp::info("setup") << "and continue to use scoped logs";
	ofxLog4Cpp::useLayout("file", ofxLog4Cpp::getJsonLayout());
	ofxLog4Cpp::info() << "this starts to get advanced";
	ofxLog4Cpp::info() << "different log formats for different places";
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
