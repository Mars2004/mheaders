/**************************************************************************************************//**
* @addtogroup	MHEADERS
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @defgroup		MOBJECTS MarsTech Objects
* @brief			MarsTech Objects
* @details		Contains implementation and all definitions of MarsTech Objects. They are objects which
*					implements basic functionallity and can be inherited.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file
* @brief			MarsTech Lockable
* @details		Contains definition and implementation of @ref MsvLockable class.
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


#ifndef MARSTECH_LOCKABLE_H
#define MARSTECH_LOCKABLE_H


#include "MsvCompiler.h"

MSV_DISABLE_ALL_WARNINGS

#include <mutex>

MSV_ENABLE_WARNINGS


/**************************************************************************************************//**
* @brief		MarsTech Lockable Object.
* @details	Lockable object. It has @ref m_lock member which locks this object for thread safety access.
******************************************************************************************************/
class MsvLockable
{
public:
	/**************************************************************************************************//**
	* @brief		Constructor.
	******************************************************************************************************/
	MsvLockable()
	{

	}

	/**************************************************************************************************//**
	* @brief		Virtual destructor.
	******************************************************************************************************/
	virtual ~MsvLockable() = default;

	/**************************************************************************************************//**
	* @brief			Deleted copy constructor.
	* @details		Copy constructor deleted -> copying is not allowed.
	* @param[in]	origin			Reference to copyied object.
	* @warning		Do not copy this object.
	******************************************************************************************************/
	MsvLockable(const MsvLockable& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Deleted assign operator.
	* @details		Assign operator deleted -> assign is not allowed.
	* @param[in]	origin			Reference to assigned object.
	* @warning		Do not assign this object.
	******************************************************************************************************/
	MsvLockable& operator= (const MsvLockable& origin) = delete;

protected:
	/**************************************************************************************************//**
	* @brief		Thread pool mutex.
	* @details	Locks this object for thread safety access.
	* @note		Mutable to be possible to lock even in const methods.
	******************************************************************************************************/
	mutable std::recursive_mutex m_lock;
};


#endif // !MARSTECH_LOCKABLE_H

/** @} */	//End of group MOBJECTS.

/** @} */	//End of group MHEADERS
