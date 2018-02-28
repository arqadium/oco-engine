/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                                OCO  ENGINE                                *
 *           Copyright (C) 2017-2018 Arqadium. All rights reserved           *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_CORE_WIN32_H )
#define INC__OCO_CORE_WIN32_H ( 1 )

#if !defined( __cplusplus )

///
/// C INTERFACE
///

#include <stdbool.h>

void ocoEnableUnicodeConsole( void );
void ocoEnableANSIConsole( void );
bool ocoSupportsANSI( void );

#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

extern "C" void ocoEnableUnicodeConsole( );
extern "C" void ocoEnableANSIConsole( );
extern "C" bool ocoSupportsANSI( );

#endif // !defined( __cplusplus )
#endif // !defined( INC__OCO_CORE_WIN32_H )
