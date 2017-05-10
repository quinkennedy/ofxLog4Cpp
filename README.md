ofxLog4Cpp
=====================================

Currently libraries are only compiled for Visual Studio 2012, Linux64, and OSX

Introduction
------------
Enable production-ready logging in oF apps, notably including configuration via file and rolling logs.

Usage
-----
The logger needs to be initialized by calling `logger.init()` before use. If you have a file _log4cpp.properties_ in your _data/_ directory, then this will be used to configure Log4Cpp. There is an example properties file in _exampleConfigFile_. Keep in mind that the log levels specified in that file are Log4Cpp log levels, not oF log levels.

In order to use the Log4Cpp functionality while still calling `ofLog____` methods, you need to set Log4Cpp as a channel: 
```
shared_ptr<ofxLog4CppChannel> log(new ofxLog4CppChannel());
ofSetLoggerChannel(log);
```
If you intend to use ofxLog4Cpp this way, then you don't need to call `init()` explicitly, since `new ofxLog4CppChannel()` initializes the logger for you.

This is the mapping from oF log levels to Log4Cpp log levels:
```
 ofLogLevel::OF_LOG_FATAL_ERROR  <->  log4cpp::Priority::FATAL
 ofLogLevel::OF_LOG_ERROR        <->  log4cpp::Priority::ERROR
 ofLogLevel::OF_LOG_WARNING      <->  log4cpp::Priority::WARN
 ofLogLevel::OF_LOG_NOTICE       <->  log4cpp::Priority::INFO
 ofLogLevel::OF_LOG_VERBOSE      <->  log4cpp::Priority::DEBUG
 ofLogLevel::OF_LOG_SILENT       <->  log4cpp::Priority::EMERG
```

License
-------
[MIT License](https://en.wikipedia.org/wiki/MIT_License). The underlying library (Lib4Cpp) is LGPL.

Installation
------------
Drop or clone the folder into the `openFrameworks/addons/` folder: `cd /path/to/oF/addons; git clone https://github.com/quinkennedy/ofxLog4Cpp.git;`

Dependencies
------------
No dependency on other addons.

Compatibility
------------

* openFrameworks 0.8.4 for Visual Studio 2012
* openFrameworks 0.9.4 on Ubuntu 14.04
* openFrameworks 0.9.4 on OS X

Known issues
------------

Version history
------------
### Version 0.1 (Date):
first!

Building Log4Cpp lib
------------
This is built on top of Log4Cpp 1.1.1. This section roughly outlines what to do if you want to add static libraries for other platforms. Currently there are static libraries for Linux64 and Visual Studio 2012.

The source for Log4Cpp is hosted on [sourceforge](https://sourceforge.net/projects/log4cpp/files/)

Once downloaded and unzipped:
* Ubuntu

	```
	$cd /PATH/TO/UNZIPPED/LIB4CPP/
	$./configure --prefix=/PATH/TO/UNZIPPED/LIB4CPP/install_prefix
	$./make
	$./make install
	```
* OS X
	```
	$cd /PATH/TO/UNZIPPED/LIB4CPP/
	$./configure CFLAGS="-arch i386 -arch x86_64" CXXFLAGS="-arch i386 -arch x86_64" LDFLAGS="-arch i386 -arch x86_64" --prefix=/Users/brettrenfer/Dropbox/Code/Native/log4cpp/install_prefix
	$./make
	$./make install
	````

* That conveniently places the libs in a directory called install_prefix. You can grab the static lib from install_prefix/lib and drop it in the appropriate lib directory for this addon.
