/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include "win32.hh"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN ( 1 )
#include <Windows.h>
#endif

namespace
{

#ifdef _WIN32
bool ansiConsoleEnabled{false};
#else
bool ansiConsoleEnabled{true};
#endif
}

void Engine::EnableANSIConsole( )
{
#ifdef _WIN32
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
#endif
}

bool Engine::SupportsANSI( ) { return ansiConsoleEnabled; }
