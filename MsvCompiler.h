/**************************************************************************************************//**
* @defgroup		MHEADERS MarsTech Headers
* @brief			MarsTech Headers
* @details		Contains implementation and all definitions of MarsTech Headers usefull in projects.
*					There will usually be macros definitions used in MarsTech projects.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @defgroup		MCOMPILER MarsTech Compiler
* @brief			MarsTech Compiler
* @details		Contains implementation and all definitions of MarsTech Compiler. Macros to disable
*					or enable warnings etc.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file
* @brief			MarsTech Compiler
* @details		Contains compile time macros.
* @author		Martin Svoboda
* @date			26.11.2018
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


#ifndef MARSTECH_COMPILER_H
#define MARSTECH_COMPILER_H


/**************************************************************************************************//**
* @def			MSV_DISABLE_WARNINGS
* @brief			Disable warnings entry.
* @details		This macro must be used before any usage of @ref MSV_DISABLE_WARNING macro. When disabled
*					warnings is no more needed, @ref MSV_ENABLE_WARNINGS macro should be used.
* @see			MSV_DISABLE_WARNING
* @see			MSV_ENABLE_WARNINGS
******************************************************************************************************/

/**************************************************************************************************//**
* @def			MSV_DISABLE_WARNING
* @brief			Disable one warning.
* @details		This macro disables one warning. It must be enclosed by @ref MSV_DISABLE_WARNINGS macro
*					@ref MSV_ENABLE_WARNINGS macro.
* @param[in]	disabledWarning		Warning to disable.
* @see			MSV_DISABLE_WARNINGS
* @see			MSV_ENABLE_WARNINGS
******************************************************************************************************/

/**************************************************************************************************//**
* @def			MSV_DISABLE_ALL_WARNINGS
* @brief			Disables all warnings.
* @details		This macro disables all warnings. It is independent and @ref MSV_DISABLE_WARNING macro
*					usage is not required.
*					When disabled warning is no more needed, @ref MSV_ENABLE_WARNINGS macro	should be used.
* @see			MSV_ENABLE_WARNINGS
******************************************************************************************************/

/**************************************************************************************************//**
* @def			MSV_ENABLE_WARNINGS
* @brief			Enables all warnings.
* @details		This macro enables all previously disabled warnings.
* @see			MSV_DISABLE_WARNINGS
* @see			MSV_DISABLE_WARNING
* @see			MSV_DISABLE_ALL_WARNINGS
******************************************************************************************************/


#ifndef MSV_3RDPARTY_WARNINGS_ON


#ifdef _MSC_VER //VISUAL STUDIO


#define MSV_DISABLE_WARNINGS __pragma(warning(push))

#define MSV_DISABLE_WARNING(disabledWarning) __pragma(warning(disable:disabledWarning))

#define MSV_DISABLE_ALL_WARNINGS __pragma(warning(push, 0))

#define MSV_ENABLE_WARNINGS __pragma(warning(pop))


#elif defined(__GNUC__) || defined(__MINGW32__) //GCC or MINGW


#define MSV_DISABLE_WARNINGS _Pragma("GCC diagnostic push")

#define MSV_DISABLE_WARNING(disabledWarning) _Pragma("GCC diagnostic ignored \""#disabledWarning#"\"")

#define MSV_DISABLE_ALL_WARNINGS MSV_DISABLE_WARNINGS \
_Pragma("GCC diagnostic ignored \"-Wall\"") \
_Pragma("GCC diagnostic ignored \"-Wextra\"")

#define MSV_ENABLE_WARNINGS _Pragma("GCC diagnostic pop")


#else //OTHER COMPILERS (TODO: ADD SUPPORT for more compilers)


#define MSV_DISABLE_WARNINGS

#define MSV_DISABLE_WARNING(disabledWarning)

#define MSV_DISABLE_ALL_WARNINGS

#define MSV_ENABLE_WARNINGS


#endif // _MSC_VER


#else // MSV_3RDPARTY_WARNINGS_ON


#define MSV_DISABLE_WARNINGS

#define MSV_DISABLE_WARNING(warning)

#define MSV_DISABLE_ALL_WARNINGS

#define MSV_ENABLE_WARNINGS


#endif // MSV_3RDPARTY_WARNINGS_ON


#endif // !MARSTECH_COMPILER_H

/** @} */	//End of group MCOMPILER.

/** @} */	//End of group MHEADERS
