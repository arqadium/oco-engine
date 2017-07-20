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
#include <sstream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <boost/locale.hpp>

#include "helpers.h"
#include "win32.h"

using OCo::EnableANSIConsole;
using OCo::Helpers::Error;
using OCo::Helpers::Log;
using sf::RenderWindow;
using sf::VideoMode;
using std::array;
using std::endl;
using std::exception;
using std::intmax_t;
using std::size_t;
#if !defined( _WIN32 )
using std::string;
#else // defined( _WIN32 )
using std::wstring;
#endif // !defined( _WIN32 )
using std::uintmax_t;
using std::vector;

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

constexpr auto kSampleImagePath{u8"sample.png"};

vector<string> parseArgs( int ac, char* av[] )
{
    vector<string> ret( ac );

    for( intmax_t i = 0; i < ac; ++i )
    {
        ret.at( i ) = av[i];
    }
    return ret;
}

void MainLoop( vector<string> args )
{
    RenderWindow window{VideoMode{640, 360}, u8"Project Mochi!"};
    sf::Texture img;

    img.loadFromFile( kSampleImagePath );

    sf::Sprite spr{img};

    while( window.isOpen( ) )
    {
        sf::Event event;

        while( window.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
            {
                window.close( );
            }
        }

        window.clear( );
        window.draw( spr );
        window.display( );
    }
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
        EnableANSIConsole( );
#endif

        for( auto& line : kStartupText )
        {
            Log( line );
        }

        MainLoop( parseArgs( ac, av ) );
    }
    catch( ... )
    {
        Error( u8"Exception thrown! Exiting..." );

        return 1;
    }

    return 0;
}
