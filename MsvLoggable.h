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
* @brief			MarsTech Loggable
* @details		Contains definition and implementation of @ref MsvLoggable class.
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


#ifndef MARSTECH_LOGGABLE_H
#define MARSTECH_LOGGABLE_H


#include "mlogging/mlogging.h"


/**************************************************************************************************//**
* @brief		MarsTech Loggable Object.
* @details	Loggable object. It has @ref m_spLogger member which is logger for logging.
******************************************************************************************************/
class MsvLoggable
{
public:
	/**************************************************************************************************//**
	* @brief			Constructor.
	* @param[in]	spLogger				Shared pointer to logger for logging.
	******************************************************************************************************/
	MsvLoggable(std::shared_ptr<MsvLogger> spLogger):
		m_spLogger(spLogger)
	{

	}

	/**************************************************************************************************//**
	* @brief			Constructor.
	* @param[in]	spLoggerProvider	Shared pointer to logger provider for getting logger.
	* @param[in]	loggerName			Logger name used for getting logger.
	******************************************************************************************************/
	MsvLoggable(std::shared_ptr<IMsvLoggerProvider> spLoggerProvider, const char* loggerName):
		m_spLogger(nullptr)
	{
		if (spLoggerProvider)
		{
			m_spLogger = spLoggerProvider->GetLogger(loggerName);
		}
	}

	/**************************************************************************************************//**
	* @brief		Virtual destructor.
	******************************************************************************************************/
	virtual ~MsvLoggable() = default;

	/**************************************************************************************************//**
	* @brief			Deleted copy constructor.
	* @details		Copy constructor deleted -> copying is not allowed.
	* @param[in]	origin			Reference to copyied object.
	* @warning		Do not copy this object.
	******************************************************************************************************/
	MsvLoggable(const MsvLoggable& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Deleted assign operator.
	* @details		Assign operator deleted -> assign is not allowed.
	* @param[in]	origin			Reference to assigned object.
	* @warning		Do not assign this object.
	******************************************************************************************************/
	MsvLoggable& operator= (const MsvLoggable& origin) = delete;

protected:
	/**************************************************************************************************//**
	* @brief			Smart pointer to logger.
	* @details		It is used for logging in childs objects.
	* @see			MsvLogger
	******************************************************************************************************/
	std::shared_ptr<MsvLogger> m_spLogger;
};


#endif // !MARSTECH_LOGGABLE_H

/** @} */	//End of group MOBJECTS.

/** @} */	//End of group MHEADERS
