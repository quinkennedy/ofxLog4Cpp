#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	logger.init();
	logger.debug() << "debug log";
	logger.info() << "info log";
	logger.warn() << "warn log";
	logger.error() << "error log";
	logger.info() << "I'm logging!";
}

//--------------------------------------------------------------
void ofApp::update(){
	logger.debug("ofApp.update") << "lets see how much data we can create: " << ofGetElapsedTimeMillis();
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
