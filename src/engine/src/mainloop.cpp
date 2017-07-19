/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include "mainloop.hpp"

#include <sstream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::VideoMode;
using std::string;
using std::vector;

namespace
{

constexpr auto kSampleImagePath{u8"SampleImage.png"};
}

void Engine::MainLoop( vector<string> args )
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
