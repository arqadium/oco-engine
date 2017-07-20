/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#ifndef INC__OCO_ENGINE_WIN32_H
#define INC__OCO_ENGINE_WIN32_H ( 1 )

#if defined( __cplusplus )

namespace OCo
{

void EnableANSIConsole( );
bool SupportsANSI( );
}

extern "C" void ocoEnableANSIConsole( );
extern "C" bool ocoSupportsANSI( );

#else // !defined( __cplusplus )

#include <stdbool.h>

void ocoEnableANSIConsole( void );
bool ocoSupportsANSI( void );

#endif // defined( __cplusplus )

#endif // INC__OCO_ENGINE_WIN32_H
