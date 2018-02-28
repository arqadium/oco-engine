/** -*- coding: utf-8; mode: C; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*****************************************************************************\
 *                                OCO  ENGINE                                *
 *           Copyright (C) 2017-2018 Arqadium. All rights reserved           *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include <oco/core/win32.h>

extern "C" int ocoMain( int ac, char* av[] )
{
    // Only functional under Windows NT
    ocoEnableUnicodeConsole( );
    ocoEnableANSIConsole( );

    // Print boot text
    // NOTE: This is hand-encoded to UTF-8, for C89 compat
    ocoLog( "" );
    ocoLog( "Project Mochi \342\200\223 \303\224\303\207\303\267 Game Engine" );
    ocoLog( "Copyright \302\251 2017 Arqadium. All rights reserved" );
    ocoLog( "" );

    return 0;
}
