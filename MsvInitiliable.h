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
* @brief			MarsTech Initiliable
* @details		Contains definition and implementation of @ref MsvInitiliable class.
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


#ifndef MARSTECH_INITILIABLE_H
#define MARSTECH_INITILIABLE_H


#include "MsvLockable.h"


/**************************************************************************************************//**
* @brief		MarsTech Initialiable Object.
* @details	Initialiable object. It has @ref m_initialized member which is flag if object is initialized
*				(true) or not (false). It is set to false in constructor.
* @see		MsvLockable
******************************************************************************************************/
template<class InterfaceClass> class MsvInitiliable:
	public InterfaceClass,
	public MsvLockable
{
public:
	/**************************************************************************************************//**
	* @brief		Constructor.
	* @details	Constructs initialiable object and set @ref m_initialized to false (not initialize).
	******************************************************************************************************/
	MsvInitiliable():
		MsvLockable(),
		m_initialized(false)
	{

	}

	/**************************************************************************************************//**
	* @brief		Virtual destructor.
	******************************************************************************************************/
	virtual ~MsvInitiliable() = default;

	/**************************************************************************************************//**
	* @brief			Deleted copy constructor.
	* @details		Copy constructor deleted -> copying is not allowed.
	* @param[in]	origin			Reference to copyied object.
	* @warning		Do not copy this object.
	******************************************************************************************************/
	MsvInitiliable(const MsvInitiliable& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Deleted assign operator.
	* @details		Assign operator deleted -> assign is not allowed.
	* @param[in]	origin			Reference to assigned object.
	* @warning		Do not assign this object.
	******************************************************************************************************/
	MsvInitiliable& operator= (const MsvInitiliable& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Initialize check.
	* @details		Returns flag if object is initialized (true) or not (false).
	* @retval		true		When initialized.
	* @retval		false		When not initialized.
	******************************************************************************************************/
	virtual bool Initialized() const
	{
		std::lock_guard<std::recursive_mutex> lock(m_lock);

		return m_initialized;
	}

protected:
	/**************************************************************************************************//**
	* @brief		Initialize flag.
	* @details	Flag if object is initialized (true) or not (false).
	* @see		Initialized
	******************************************************************************************************/
	bool m_initialized;
};


#endif // !MARSTECH_INITILIABLE_H

/** @} */	//End of group MOBJECTS.

/** @} */	//End of group MHEADERS
