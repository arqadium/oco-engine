/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "package.hh"

#include <array>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>



using std::array;
using std::ifstream;
using std::ios_base;
using std::string;
using std::uint8_t;
using std::uintmax_t;
using std::vector;

namespace
{
	const array<uint8_t, 0xE> magicBytes{
		0x89,
		static_cast<uint8_t>('M'),
		static_cast<uint8_t>('O'),
		static_cast<uint8_t>('C'),
		static_cast<uint8_t>('H'),
		static_cast<uint8_t>('I'),
		static_cast<uint8_t>('P'),
		static_cast<uint8_t>('K'),
		static_cast<uint8_t>('G'),
		static_cast<uint8_t>('\r'),
		static_cast<uint8_t>('\n'),
		0x1A,
		static_cast<uint8_t>('\n'),
		static_cast<uint8_t>('\0')
	};
	constexpr uintmax_t headerRawSize = 0x1C;
	constexpr uint8_t curVersion = 0;

	bool headerMatch( vector<uint8_t> data )
	{
		for(uintmax_t i = 0; i < 0xE; ++i)
		{
			if(data.at( i ) != magicBytes.at( i ))
			{
				return false;
			}
		}

		return true;
	}
}

Engine::Package::Package( string filePath, bool check )
{
	if(check) { this->ChecksumsInvalid( ); }
	
	this->checked = check;
	this->stream.open( filePath, ifstream::in | ifstream::binary );
	this->stream.seekg( ios_base::beg );

	vector<uint8_t> headerRaw;

	headerRaw.resize( headerRawSize );
	this->stream.read( reinterpret_cast<char*>(headerRaw.data( )),
		headerRawSize );

	if(headerMatch( headerRaw ))
	{
		this->IndexFiles( );
	}
}

Engine::Package::~Package( )
{
	if(this->stream.is_open( ))
	{
		this->stream.close( );
	}
}

void Engine::Package::IndexFiles( )
{

}

bool Engine::Package::ChecksumsInvalid( )
{
	return false;
}
