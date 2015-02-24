#include "ofxLog4CppChannel.h"

namespace ofxLog4CppChannelNS{
	bool isShutdown;
	void shutdown(){
		isShutdown = true;
	}
}

ofxLog4CppChannel::ofxLog4CppChannel():
	root(log4cpp::Category::getRoot())
{
	ofxLog4Cpp::init();
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);//let's let log4cpp handle the filtering, not oF
	ofxLog4CppChannelNS::isShutdown = false;
	log4cpp::HierarchyMaintainer::getDefaultMaintainer().register_shutdown_handler(&ofxLog4CppChannelNS::shutdown);
}

ofxLog4CppChannel::~ofxLog4CppChannel(){
}

void ofxLog4CppChannel::close(){
}

void ofxLog4CppChannel::log(ofLogLevel level, const string & module, const string & message){
	if (!ofxLog4CppChannelNS::isShutdown){
		root.log(of2l4c(level), message);
	}
	//ofxLog4Cpp::log(module, of2l4c(level), message);
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
