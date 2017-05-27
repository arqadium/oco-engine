/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "win32.hh"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN (1)
#include <Windows.h>
#endif



namespace
{

#ifdef _WIN32
bool ansiConsoleEnabled{ false };
#else
bool ansiConsoleEnabled{ true };
#endif

}

void Engine::EnableANSIConsole( )
{
#ifdef _WIN32
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	DWORD dwMode = 0;

	if(hOut == INVALID_HANDLE_VALUE) { return; }
	if(!GetConsoleMode( hOut, &dwMode )) { return; }

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if(!SetConsoleMode( hOut, dwMode )) { return; }

	ansiConsoleEnabled = true;
#endif
}



bool Engine::SupportsANSI( )
{
	return ansiConsoleEnabled;
}
