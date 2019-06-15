
# MarsTech Headers
 - [Installation](#installation)
	 - [Configuration](#configuration)
 - [MarsTech Compiler Header](#marstech-compiler-header)
 - [MarsTech Objects Headers](#marstech-objects-headers)
	 - [MarsTech Loggable Object](#marstech-loggable-object)
	 - [MarsTech Lockable Object](#marstech-lockable-object)
	 - [MarsTech Initialiable Object](#marstech-initialiable-object)
	 - [MarsTech Runnable Object](#marstech-runnable-object)
	 - [MarsTech Object](#marstech-object)
 - [Usage Example](#usage-example)
 - [Source code documentation](#source-code-documentation)
 - [License](#license)

MarsTech Headers is C++ project which contains headers usefull in MarsTech projects. There will usually be macros definitions used in MarsTech projects.

## Installation
MHEADERS is header only project/library - there is no static or dynamic library. You can download repository and include header files to your project.

### Configuration
No configuration is needed - just include MHEADERS header files to your project.

## MarsTech Compiler Header
Contains implementations and all definitions for compiler settings (e.g. macros to disable or enable warnings). Please see [source code documentation](https://www.marstech.cz/projects/mheaders/1.0.1/doc) for more information.
**Example:**
~~~cpp
#include "mheaders/MsvCompiler.h"
MSV_DISABLE_ALL_WARNINGS

//include 3rdParty library which generates or can generate warnings
#include "spdlog/spdlog.h"

MSV_ENABLE_WARNINGS
~~~

## MarsTech Objects Headers
Contains MarsTech objects implementations. They are base classes which implements basic methods. Please see [source code documentation](https://www.marstech.cz/projects/mheaders/1.0.1/doc) for more information.

### MarsTech Loggable Object
Loggable object implements logger member and its initialization in constructors. Just inherit from this class and your class is ready for logging.

**Example:**
~~~cpp
#include "MsvLoggable.h"

class LoggingClass:
	public MsvLoggable
{
public:
	LoggingClass(std::shared_ptr<MsvLogger> spLogger):
		MsvLoggable(spLogger)
	{
		//logger is already initialized -> just set it and use it
	}

	LoggingClass(std::shared_ptr<IMsvLoggerProvider> spLoggerProvider:
		MsvLoggable(spLoggerProvider, "MyLoggerName")
	{
		//logger is not initialized -> get logger from logger provider
	}

	void SomeMethodWhichLogs()
	{
		//m_spLogger is inherited from MsvLoggable
		MSV_LOG_INFO(m_spLogger, "Some log message.");
	}
};
~~~

### MarsTech Lockable Object
Lockable object implements lock member and its initialization in constructors. Just inherit from this class and your class is ready for locking (thread synchronization).

**Example:**
~~~cpp
#include "MsvLockable.h"

class LockingClass:
	public MsvLockable
{
public:
	LockingClass():
		MsvLockable()
	{
		//m_lock is created
	}
	
	void SomeMethodWhichLocks()
	{
		//m_lock is inherited from MsvLockable
		std::lock_guard<std::recursive_mutex> lock(m_lock);
	}
};
~~~

### MarsTech Initialiable Object
Initiable object inherits from [lockable object](#marstech-lockable-object) and implements initialized flag, which is set to false in its constructor and initialize flag check method.
Just inherit from this class and your class is ready for locking and initializing (Initialize and Unitialize methods should be implemented by a child).

**Example:**
~~~cpp
#include "MsvInitiliable.h"

class InitiliableClass:
	public MsvInitiliable<InitiliableClassInterface>
{
public:
	InitiliableClass():
		MsvInitiliable<InitiliableClassInterface>()
	{
		//m_lock is created
		//m_initialized is set to false
	}
	
	void SomeMethodWhichLocksAndChecksIntializeFlag()
	{
		//m_lock is inherited from MsvLockable (through MsvInitiliable)
		std::lock_guard<std::recursive_mutex> lock(m_lock);

		//Initialized (and m_initialized) are inherited from MsvInitiliable
		if (Initialized())
		{
			return;
		}
	}
};
~~~

### MarsTech Runnable Object
Runnable object inherits from [initialiable object](#marstech-initialiable-object) and implements running flag, which is set to false in its constructor and running flag check method.
Just inherit from this class and your class is ready for locking, initializing and starting/stopping (Start and Stop methods should be implemented by a child).

**Example:**
~~~cpp
#include "MsvRunnable.h"

class RunnableClass:
	public MsvRunnable<RunnableClassInterface>
{
public:
	RunnableClass():
		MsvRunnable<RunnableClassInterface>()
	{
		//m_lock is created
		//m_initialized is set to false
		//m_running is set to false
	}
	
	void SomeMethodWhichLocksChecksIntializeAndRunningFlag()
	{
		//m_lock is inherited from MsvLockable (through MsvInitiliable)
		std::lock_guard<std::recursive_mutex> lock(m_lock);

		//Initialized (and m_initialized) are inherited from MsvInitiliable (through MsvRunnable)
		if (Initialized())
		{
			return;
		}
		
		//Running (and m_running) are inherited from MsvRunnable
		if (Running())
		{
			return;
		}
	}
};
~~~

### MarsTech Object
MarsTech object inherits from [runnable object](#marstech-runnable-object) and [loggable object](#marstech-loggable-object).
Just inherit from this class and your class is ready for logging, locking, initializing and starting/stopping (Initialize, Unitialize, Start and Stop methods should be implemented by a child).

**Example:**
~~~cpp
#include "MsvObject.h"

class ObjectClass:
	public MsvObject<ObjectClassInterface>
{
public:
	ObjectClass(std::shared_ptr<MsvLogger> spLogger):
		MsvObject<ObjectClassInterface>(spLogger)
	{
		//logger is already initialized -> just set it and use it
		//m_lock is created
		//m_initialized is set to false
		//m_running is set to false
	}

	ObjectClass(std::shared_ptr<IMsvLoggerProvider> spLoggerProvider:
		MsvObject<ObjectClassInterface>(spLoggerProvider, "MyLoggerName")
	{
		//logger is not initialized -> get logger from logger provider
		//m_lock is created
		//m_initialized is set to false
		//m_running is set to false
	}
	void SomeMethodWhichLocksChecksIntializeAndRunningFlagAndLogs()
	{
		//m_lock is inherited from MsvLockable (through MsvObject)
		std::lock_guard<std::recursive_mutex> lock(m_lock);

		//Initialized (and m_initialized) are inherited from MsvInitiliable (through MsvObject)
		if (Initialized())
		{
			return;
		}
		
		//Running (and m_running) are inherited from MsvRunnable (through MsvObject)
		if (Running())
		{
			return;
		}

		//m_spLogger is inherited from MsvLoggable (through MsvObject)
		MSV_LOG_INFO(m_spLogger, "Some log message.");
	}
};
~~~

## Usage Example
There is also an [usage example](https://github.com/Mars2004/msys/tree/master/Example) which uses the most of [MarsTech](https://github.com/Mars2004) projects and libraries.
Its source codes and readme can be found at:
 - [https://github.com/Mars2004/msys/tree/master/Example](https://github.com/Mars2004/msys/tree/master/Example)

## Source code documentation
You can find generated source code documentation at [https://www.marstech.cz/projects/mheaders/1.0.1/doc](https://www.marstech.cz/projects/mheaders/1.0.1/doc).

## License
This project is released under GNU General Public License version 3. If you can not or do not want to accept GNU GPLv3 license and you would like to use this project under another license, please contact me on [info@marstech.cz](mailto:info@marstech.cz) or visit [www.marstech.cz](https://www.marstech.cz/en).
