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

#include <stdbool.h>

#if defined( _WIN32 )

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

static bool ansiConsoleEnabled = false;

bool ocoSupportsANSI( ) { return ansiConsoleEnabled; }

void ocoEnableUnicodeConsole( )
{
    SetConsoleCP( 65001 );
    SetConsoleOutputCP( 65001 );
}

void ocoEnableANSIConsole( )
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut  = GetStdHandle( STD_OUTPUT_HANDLE );
    DWORD dwMode = 0;

    if( hOut == INVALID_HANDLE_VALUE )
    {
        return;
    }
    if( !GetConsoleMode( hOut, &dwMode ) )
    {
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if( !SetConsoleMode( hOut, dwMode ) )
    {
        return;
    }

    ansiConsoleEnabled = true;
}

#else // !defined( _WIN32 )

void ocoEnableUnicodeConsole( ) { }
void ocoEnableANSIConsole( ) { }
bool ocoSupportsANSI( ) { return true; }

#endif // defined( _WIN32 )
