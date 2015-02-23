#pragma once

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/PassThroughLayout.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include "log4cpp/CategoryStream.hh"
#include "ofMain.h"

class ofxLog4Cpp {
public:
	static log4cpp::Layout* getDefaultLayout(){
		log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
		layout->setConversionPattern("%d{%y/%m/%d,%H:%M:%S,%l} %c-%p: %m%n");
		return layout;
	}

	static log4cpp::Layout* getJsonLayout(){
		log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
		layout->setConversionPattern("{\"category\":\"%c\",\"priority\":\"%p\",\"message\":\"%m\",\"epoch\":\"%R\",\"millis\":%d{%l}}%n");
		return layout;
	}

	static log4cpp::Layout* getRawLayout(){
		log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
		return layout;
	}

	static log4cpp::Appender* getFileAppender(){
		log4cpp::Appender* appender = log4cpp::Appender::getAppender("file");
		if (appender == NULL){
			ofFile file("output.log");
			appender = new log4cpp::FileAppender("file", file.getAbsolutePath());
			appender->setLayout(getDefaultLayout());
		}
		return appender;
	}

	static log4cpp::Appender* getConsoleAppender(){
		log4cpp::Appender* appender = log4cpp::Appender::getAppender("console");
		if (appender == NULL){
			appender = new log4cpp::OstreamAppender("console", &std::cout);
			appender->setLayout(getDefaultLayout());
		}
		return appender;
	}

	static log4cpp::Category& getPath(string path = ""){
		return log4cpp::Category::getInstance(path);
	}

	static void useLayout(string appenderName, log4cpp::Layout* layout){
		log4cpp::Appender* appender = log4cpp::Appender::getAppender(appenderName);
		if (appender != NULL){
			appender->setLayout(layout);
		}
	}

	static void useLayout(log4cpp::Layout* layout){
		useLayout("console", layout);
		useLayout("file", layout);
	}

	static void useBasicLayout(){
		useLayout(new log4cpp::BasicLayout());
	}

	static void useDefaultLayout(){
		useLayout(getDefaultLayout());
	}

	static void useRawLayout(){
		useLayout(getRawLayout());
	}

	static void useJsonLayout(){
		useLayout(getJsonLayout());
	}

	static void enableAppender(log4cpp::Appender* appender){
		getPath().addAppender(appender);
	}

	static void enableFileLog(){
		enableAppender(getFileAppender());
	}

	static void enableConsoleLog(){
		enableAppender(getConsoleAppender());
	}

	static void disableAppender(string name){
		log4cpp::Appender* appender = log4cpp::Appender::getAppender(name);
		if (appender != NULL){
			getPath().removeAppender(appender);
		}
	}

	static void disableConsoleLog(){
		disableAppender("console");
	}

	static void disableFileLog(){
		disableAppender("file");
	}

	static void setLogPriority(log4cpp::Priority::Value priority){
		getPath().setPriority(priority);
	}

	static void init(){
		//setup logger
		string propFileName = "log4cpp.properties";
		if (ofFile::doesFileExist(propFileName)){
			log4cpp::PropertyConfigurator::configure(ofFile(propFileName).getAbsolutePath());
		} else {
			ofxLog4Cpp::setLogPriority(log4cpp::Priority::INFO);
			ofxLog4Cpp::enableConsoleLog();
		}
	}

	static void log(string path, log4cpp::Priority::Value priority, string message){
		getPath(path).log(priority, message);
	}

	static void log(log4cpp::Priority::Value priority, string message){
		log("", priority, message);
	}

	static log4cpp::CategoryStream log(string path, log4cpp::Priority::Value priority){
		return getPath(path).getStream(priority);
	}

	static log4cpp::CategoryStream log(log4cpp::Priority::Value priority){
		return log("", priority);
	}

	static void debug(string path, string message){
		log(path, log4cpp::Priority::DEBUG, message);
	}
	
	static log4cpp::CategoryStream debug(string path = ""){
		return getPath(path).getStream(log4cpp::Priority::DEBUG);
	}

	static void info(string path, string message){
		log(path, log4cpp::Priority::INFO, message);
	}
	
	static log4cpp::CategoryStream info(string path = ""){
		return getPath(path).getStream(log4cpp::Priority::INFO);
	}

	static void warn(string path, string message){
		log(path, log4cpp::Priority::WARN, message);
	}
	
	static log4cpp::CategoryStream warn(string path = ""){
		return getPath(path).getStream(log4cpp::Priority::WARN);
	}

	static void error(string path, string message){
		log(path, log4cpp::Priority::ERROR, message);
	}
	
	static log4cpp::CategoryStream error(string path = ""){
		return getPath(path).getStream(log4cpp::Priority::ERROR);
	}
};