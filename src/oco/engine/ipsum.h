/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_ENGINE_IPSUM_H )
#define INC__OCO_ENGINE_IPSUM_H ( 1 )

#if !defined( NDEBUG )
#if !defined( __cplusplus )

///
/// C INTERFACE
///

void ocoIpsum( void );

#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

extern "C" void ocoIpsum( );

#endif // !defined( __cplusplus )
#endif // !defined( NDEBUG )
#endif // !defined( INC__OCO_ENGINE_IPSUM_H )
