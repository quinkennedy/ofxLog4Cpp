ofxLog4Cpp
=====================================

Currently libraries are only compiled for Visual Studio 2012 and Linux64

Introduction
------------
Enable production-ready logging in oF apps, notably including configuration via file and rolling logs.

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
* openFrameworks 0.9.3 on Ubuntu 14.04

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

Once downloaded and unzipped, on Ubuntu I did the following:

```
./configure --prefix=/PATH/TO/UNZIPPED/LIB4CPP/install_prefix
./make
./make install
```

That conveniently places the libs in a directory called install_prefix. You can grab the static lib from install_prefix/lib and drop it in the appropriate lib directory for this addon.
