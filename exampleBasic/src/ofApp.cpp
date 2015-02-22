#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	logger.debug() << "this message won't show up";
	logger.setLogPriority(log4cpp::Priority::DEBUG);
	logger.debug() << "this will show up";
	logger.setLogPriority(log4cpp::Priority::INFO);
	logger.info() << "now you should know how to change log levels";
	logger.info() << "you can also change the format";
	logger.useBasicLayout();
	logger.info() << "to use the basic layout";
	logger.useJsonLayout();
	logger.info() << "or the json layout for automated processing";
	logger.useRawLayout();
	logger.info() << "... the raw layout for just messages";
	logger.useDefaultLayout();
	logger.info() << "or just be content with the default";
	logger["setup"].infoStream() << "and here is scoped logging";
	logger.enableFileLog();
	logger.info() << "now lets try logging to a file";
	logger.disableConsoleLog();
	logger.info() << "and stop logging to the console";
	logger.enableConsoleLog();
	logger.info() << "ok, we can log to both";
	logger["setup"].infoStream() << "and continue to use scoped logs";
	logger.useLayout("file", logger.getJsonLayout());
	logger.info() << "this starts to get advanced";
	logger.info() << "different log formats for different places";
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
