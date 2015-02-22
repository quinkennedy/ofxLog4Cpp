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
private:
	vector<string> appenderNames;
	log4cpp::Category* root;
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

	ofxLog4Cpp(){
		root = &log4cpp::Category::getRoot();

		//setup logger
		string propFileName = "log4cpp.properties";
		if (ofFile::doesFileExist(propFileName)){
			log4cpp::PropertyConfigurator::configure(ofFile(propFileName).getAbsolutePath());
		} else {
			setLogPriority(log4cpp::Priority::INFO);
			enableConsoleLog();
		}
	};

	void useLayout(string appenderName, log4cpp::Layout* layout){
		log4cpp::Appender* appender = log4cpp::Appender::getAppender(appenderName);
		if (appender != NULL){
			appender->setLayout(layout);
		}
	}

	void useLayout(log4cpp::Layout* layout){
		for(auto appenderName : appenderNames){
			useLayout(appenderName, layout);
		}
	}

	void useBasicLayout(){
		useLayout(new log4cpp::BasicLayout());
	}

	void useDefaultLayout(){
		useLayout(getDefaultLayout());
	}

	void useRawLayout(){
		useLayout(getRawLayout());
	}

	void useJsonLayout(){
		useLayout(getJsonLayout());
	}

	void enableAppender(log4cpp::Appender* appender){
		for(int i = 0; i < appenderNames.size(); i++){
			if (appenderNames[i] == appender->getName()){
				//appender already in use
				return;
			}
		}
		root->addAppender(appender);
		appenderNames.push_back(appender->getName());
	}

	void enableFileLog(){
		enableAppender(getFileAppender());
	}

	void enableConsoleLog(){
		enableAppender(getConsoleAppender());
	}

	void disableAppender(string name){
		for(int i = 0; i < appenderNames.size(); i++){
			if (appenderNames[i] == name){
				root->removeAppender(log4cpp::Appender::getAppender(name));
				appenderNames.erase(appenderNames.begin() + i);
				return;
			}
		}
	}

	void disableConsoleLog(){
		disableAppender("console");
	}

	void disableFileLog(){
		disableAppender("file");
	}

	void setLogPriority(log4cpp::Priority::Value priority){
		root->setPriority(priority);
	}

	log4cpp::Category& operator[](string path){
		return log4cpp::Category::getInstance(path);
	}

	void log(log4cpp::Priority::Value priority, string message){
		root->log(priority, message);
	}

	void debug(string message){
		root->debug(message);
	}

	void info(string message){
		root->info(message);
	}

	void warn(string message){
		root->warn(message);
	}

	void error(string message){
		root->error(message);
	}

	log4cpp::CategoryStream debug(){
		return root->getStream(log4cpp::Priority::DEBUG);
	}

	log4cpp::CategoryStream info(){
		return root->getStream(log4cpp::Priority::INFO);
	}

	log4cpp::CategoryStream warn(){
		return root->getStream(log4cpp::Priority::WARN);
	}

	log4cpp::CategoryStream error(){
		return root->getStream(log4cpp::Priority::ERROR);
	}
};