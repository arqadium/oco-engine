/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "mainloop.hh"

#include <string>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>



using sf::RenderWindow;
using sf::VideoMode;
using std::string;
using std::vector;

namespace
{
	constexpr auto kSampleImagePath{ "SampleImage.png" };
}

void Engine::MainLoop( vector<string> args )
{
	RenderWindow window{ VideoMode{ 640, 360 }, "Project Mochi!" };
	sf::Texture img;

	img.loadFromFile( kSampleImagePath );

	sf::Sprite spr{ img };

	while(window.isOpen( ))
	{
		sf::Event event;

		while(window.pollEvent( event ))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close( );
			}
		}

		window.clear( );
		window.draw( spr );
		window.display( );
	}
}
