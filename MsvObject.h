/**************************************************************************************************//**
* @addtogroup	MHEADERS
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @addtogroup	MOBJECTS
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file
* @brief			MarsTech Object
* @details		Contains definition and implementation of @ref MsvObject class.
* @author		Martin Svoboda
* @date			19.05.2019
* @copyright	GNU General Public License (GPLv3).
******************************************************************************************************/


/*
This file is part of MarsTech Headers.

MarsTech Dependency Injection is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MarsTech Promise Like Syntax is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar. If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef MARSTECH_OBJECT_H
#define MARSTECH_OBJECT_H


#include "MsvRunnable.h"
#include "MsvLoggable.h"


/**************************************************************************************************//**
* @brief		MarsTech Object.
* @details	It is base MarsTech object. This object is lockable, initialiable, runnable and loggable.
* @see		MsvRunnable
* @see		MsvLoggable
******************************************************************************************************/
template<class InterfaceClass> class MsvObject:
	public MsvRunnable<InterfaceClass>,
	public MsvLoggable
{
public:
	/**************************************************************************************************//**
	* @brief			Constructor.
	* @details		Constructs MarsTech object and set it to default state (uninitialized, not running).
	* @param[in]	spLogger				Shared pointer to logger for logging.
	******************************************************************************************************/
	MsvObject(std::shared_ptr<MsvLogger> spLogger):
		MsvRunnable<InterfaceClass>(),
		MsvLoggable(spLogger)
	{

	}

	/**************************************************************************************************//**
	* @brief			Constructor.
	* @details		Constructs MarsTech object and set it to default state (uninitialized, not running).
	* @param[in]	spLoggerProvider	Shared pointer to logger provider for getting logger.
	* @param[in]	loggerName			Logger name used for getting logger.
	******************************************************************************************************/
	MsvObject(std::shared_ptr<IMsvLoggerProvider> spLoggerProvider, const char* loggerName):
		MsvRunnable<InterfaceClass>(),
		MsvLoggable(spLoggerProvider, loggerName)
	{

	}

	/**************************************************************************************************//**
	* @brief		Virtual destructor.
	******************************************************************************************************/
	virtual ~MsvObject() = default;

	/**************************************************************************************************//**
	* @brief			Deleted copy constructor.
	* @details		Copy constructor deleted -> copying is not allowed.
	* @param[in]	origin			Reference to copyied object.
	* @warning		Do not copy this object.
	******************************************************************************************************/
	MsvObject(const MsvObject& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Deleted assign operator.
	* @details		Assign operator deleted -> assign is not allowed.
	* @param[in]	origin			Reference to assigned object.
	* @warning		Do not assign this object.
	******************************************************************************************************/
	MsvObject& operator= (const MsvObject& origin) = delete;
};


#endif // !MARSTECH_OBJECT_H

/** @} */	//End of group MOBJECTS.

/** @} */	//End of group MHEADERS
