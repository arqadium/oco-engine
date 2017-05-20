/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include <array>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "mainloop.hh"



using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::intmax_t;
using std::runtime_error;
using std::string;
using std::vector;

namespace
{
	const array<string, 4> kStartupText{
		u8"",
		u8"Project Mochi ÔÇô Game Engine",
		u8"Copyright (C) 2017 Trinity Software. All rights reserved",
		u8""
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
		for(auto& line : kStartupText)
		{
			cout << line << endl;
		}

		Engine::MainLoop( parseArgs( ac, av ) );
	}
	catch(exception& ex)
	{
		cerr << "!!! Exception thrown: " << ex.what( ) << endl;
	}
	catch(...)
	{
		cerr << "!!! ROGUE EXCEPTION THROWN! EXITING..." << endl;
	}

	return 0;
}
