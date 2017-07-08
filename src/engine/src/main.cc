/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#ifdef _WIN32
extern "C" {
#include <fcntl.h>
#include <io.h>
}
#endif

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/locale.hpp>

#include "except.hh"
#include "helpers.hh"
#include "mainloop.hh"
#include "win32.hh"

using boost::locale::conv::utf_to_utf;
using Engine::Exception;
using Engine::Helpers::ANSIFormat;
using Engine::Helpers::Error;
using Engine::Helpers::Log;
using std::array;
using std::endl;
using std::exception;
using std::intmax_t;
using std::size_t;
using std::string;
using std::uintmax_t;
using std::vector;
using std::wstring;

namespace
{

#ifdef _WIN32
const vector<wstring> kStartupText{L"",
    L"Project Mochi \u2013 \u00D4\u00C7\u00F4 Game Engine",
    L"Copyright \u00A9 2017 Trinity Software. All rights reserved",
    L""};
#else
const vector<string> kStartupText{u8"",
    u8"Project Mochi \u2013 \u00D4\u00C7\u00F4 Game Engine",
    u8"Copyright \u00A9 2017 Trinity Software. All rights reserved",
    u8""};
#endif

vector<string> parseArgs( int ac, char* av[] )
{
    vector<string> ret( ac );

    for( intmax_t i = 0; i < ac; ++i )
    {
        ret.at( i ) = av[i];
    }
    return ret;
}
}

int main( int ac, char* av[] )
{
    try
    {
#ifdef _WIN32
        _setmode( _fileno( stderr ), _O_U16TEXT );
        _setmode( _fileno( stdin ), _O_U16TEXT );
        _setmode( _fileno( stdout ), _O_U16TEXT );
        Engine::EnableANSIConsole( );
#endif

        for( auto& line : kStartupText )
        {
            Log( line );
        }

        Engine::MainLoop( parseArgs( ac, av ) );
    }
    catch( Exception& ex ) // Enhanced exception object
    {
        Error( u8"Engine exception thrown, code ", false );
        Error( ANSIFormat(
                   std::to_string( ex.code ), Engine::Helpers::ANSI::Bold ),
            false );
        Error( u8": ", false );
        Error( ex.msg );

        return ex.code < 4 ? 3 : ex.code;
    }
    catch( exception& ex ) // STL exception object
    {
        Error( u8"Standard exception thrown: ", false );
        Error( ex.what( ) );

        return 2;
    }
    catch( ... )
    {
        Error( u8"ROGUE EXCEPTION THROWN! EXITING..." );

        return 1;
    }

    return 0;
}
