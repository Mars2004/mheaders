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
* @brief			MarsTech Runnable
* @details		Contains definition and implementation of @ref MsvRunnable class.
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


#ifndef MARSTECH_RUNNABLE_H
#define MARSTECH_RUNNABLE_H


#include "MsvInitiliable.h"


/**************************************************************************************************//**
* @brief		MarsTech Runnable Object.
* @details	Runnable object. It has @ref m_running member which is flag if object is running
*				(true) or not (false). It is set to false in constructor.
* @see		MsvInitiliable
******************************************************************************************************/
template<class InterfaceClass> class MsvRunnable:
	public MsvInitiliable<InterfaceClass>
{
public:
	/**************************************************************************************************//**
	* @brief		Constructor.
	* @details	Constructs MarsTEch runnable object and set @ref m_running to false (not running).
	******************************************************************************************************/
	MsvRunnable():
		MsvInitiliable<InterfaceClass>(),
		m_running(false)
	{

	}

	/**************************************************************************************************//**
	* @brief		Virtual destructor.
	******************************************************************************************************/
	virtual ~MsvRunnable() = default;

	/**************************************************************************************************//**
	* @brief			Deleted copy constructor.
	* @details		Copy constructor deleted -> copying is not allowed.
	* @param[in]	origin			Reference to copyied object.
	* @warning		Do not copy this object.
	******************************************************************************************************/
	MsvRunnable(const MsvRunnable& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Deleted assign operator.
	* @details		Assign operator deleted -> assign is not allowed.
	* @param[in]	origin			Reference to assigned object.
	* @warning		Do not assign this object.
	******************************************************************************************************/
	MsvRunnable& operator= (const MsvRunnable& origin) = delete;

	/**************************************************************************************************//**
	* @brief			Running check.
	* @details		Returns flag if object is running (true) or not (false).
	* @retval		true		When running.
	* @retval		false		When not running.
	******************************************************************************************************/
	virtual bool Running() const
	{
		std::lock_guard<std::recursive_mutex> lock(MsvInitiliable<InterfaceClass>::m_lock);

		return m_running;
	}

protected:
	/**************************************************************************************************//**
	* @brief		Running flag.
	* @details	Flag if object is running (true) or not (false).
	* @see		Running
	******************************************************************************************************/
	bool m_running;
};


#endif // !MARSTECH_RUNNABLE_H

/** @} */	//End of group MOBJECTS.

/** @} */	//End of group MHEADERS
