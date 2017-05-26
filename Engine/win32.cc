/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "win32.hh"

#define WIN32_LEAN_AND_MEAN (1)
#include <Windows.h>



namespace
{

bool ansiConsoleEnabled{ false };

}

void Engine::EnableANSIConsole( )
{
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	DWORD dwMode = 0;

	if(hOut == INVALID_HANDLE_VALUE) { return; }
	if(!GetConsoleMode( hOut, &dwMode )) { return; }

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if(!SetConsoleMode( hOut, dwMode )) { return; }

	ansiConsoleEnabled = true;
}
