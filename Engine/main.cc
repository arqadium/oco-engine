/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

extern "C"
{
#include <io.h>
#include <fcntl.h>
}

#include "mainloop.hh"



using std::array;
using std::endl;
using std::exception;
using std::intmax_t;
using std::runtime_error;
using std::size_t;
using std::string;
using std::uintmax_t;
using std::vector;
using std::wcerr;
using std::wcin;
using std::wclog;
using std::wcout;
using std::wstring;

namespace
{
	const vector<wstring> kStartupText{
		reinterpret_cast<wchar_t*>(u""),
		reinterpret_cast<wchar_t*>(u"Project Mochi – ÔÇô Game Engine"),
		reinterpret_cast<wchar_t*>(
			u"Copyright © 2017 Trinity Software. All rights reserved"),
		reinterpret_cast<wchar_t*>(u"")
	};
	
	vector<string> parseArgs( int ac, char* av[] )
	{
		vector<string> ret( ac );

		for(intmax_t i = 0; i < ac; ++i)
		{
			ret.at( i ) = av[i];
		}

		return ret;
	}
}

int main(int ac, char* av[])
{
	try
	{
		const size_t kStartupTextSz = kStartupText.size( );

		_setmode( _fileno( stderr ), _O_U16TEXT );
		_setmode( _fileno( stdin ), _O_U16TEXT );
		_setmode( _fileno( stdout ), _O_U16TEXT );

		for(auto& line : kStartupText)
		{
			wcout << line << endl;
		}

		Engine::MainLoop( parseArgs( ac, av ) );
	}
	catch(exception& ex)
	{
		wcerr << "!!! Exception thrown: " << ex.what( ) << endl;

		return 2;
	}
	catch(...)
	{
		wcerr << "!!! ROGUE EXCEPTION THROWN! EXITING..." << endl;

		return 1;
	}

	return 0;
}
