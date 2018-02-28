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

#include "helpers.h"
#include "ipsum.h"
#include "win32.h"
/*
using sf::RenderWindow;
using sf::VideoMode; */
using std::array;
using std::endl;
using std::exception;
using std::intmax_t;
using std::size_t;
using std::string;
using std::uintmax_t;
using std::vector;

namespace
{

void MainLoop( int ac, char* av[] )
{ /*
    RenderWindow window{VideoMode{640, 360}, u8"Project Mochi!"};
    sf::Texture img;

    img.loadFromFile( u8"sample.png" );

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
    } */
#if !defined( NDEBUG )
    ocoIpsum( );
#endif // !defined( NDEBUG )
}
}

extern "C" int ocoMain( int ac, char* av[] )
{
    try
    {
        // Only functional under Windows NT
        ocoEnableUnicodeConsole( );
        ocoEnableANSIConsole( );

        // Print boot text
        ocoLog( u8"" );
        ocoLog( u8"Project Mochi \u2013 \u00D4\u00C7\u00F4 Game Engine" );
        ocoLog( u8"Copyright \u00A9 2017 Arqadium. All rights reserved" );
        ocoLog( u8"" );

        MainLoop( ac, av );
    }
    catch( ... )
    {
        ocoError( u8"Rogue Exception thrown! Exiting..." );

        return 1;
    }

    return 0;
}
