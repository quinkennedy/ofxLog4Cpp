#include "ofxLog4CppChannel.h"

ofxLog4CppChannel::ofxLog4CppChannel(){
	ofxLog4Cpp::init();
}

ofxLog4CppChannel::~ofxLog4CppChannel(){
}

void ofxLog4CppChannel::close(){
	file.close();
}

void ofxLog4CppChannel::log(ofLogLevel level, const string & module, const string & message){
	ofxLog4Cpp::log(module, of2l4c(level), message);
}

void ofxLog4CppChannel::log(ofLogLevel level, const string & module, const char* format, ...){
	va_list args;
	va_start(args, format);
	log(level, module, format, args);
	va_end(args);
}

void ofxLog4CppChannel::log(ofLogLevel level, const string & module, const char* format, va_list args){
	log(level, module, ofVAArgsToString(format, args));
}
