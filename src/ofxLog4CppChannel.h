#pragma once

#include "ofLog.h"
#include "ofxLog4Cpp.h"
#include "log4cpp/HierarchyMaintainer.hh"

class ofxLog4CppChannel: public ofBaseLoggerChannel{
public:
	enum LogFormat{
		DEFAULT,
		JSON,
		NONE,
		RAW,
		BASIC
	};
	ofxLog4CppChannel(/*LogFormat forConsole = LogFormat::DEFAULT, LogFormat forFile = LogFormat::NONE*/);
	virtual ~ofxLog4CppChannel();

	void log(ofLogLevel level, const string & module, const string & message);
	void log(ofLogLevel level, const string & module, const char* format, ...);
	void log(ofLogLevel level, const string & module, const char* format, va_list args);

	void close();

private:
	log4cpp::Category& root;
	log4cpp::Priority::Value of2l4c(ofLogLevel level){
		switch (level){
		case ofLogLevel::OF_LOG_ERROR:
			return log4cpp::Priority::ERROR;
		case ofLogLevel::OF_LOG_FATAL_ERROR:
			return log4cpp::Priority::FATAL;
		case ofLogLevel::OF_LOG_SILENT:
			return log4cpp::Priority::EMERG;
		case ofLogLevel::OF_LOG_VERBOSE:
			return log4cpp::Priority::DEBUG;
		case ofLogLevel::OF_LOG_WARNING:
			return log4cpp::Priority::WARN;
		case ofLogLevel::OF_LOG_NOTICE:
		default:
			return log4cpp::Priority::INFO;
		}
	}
};
