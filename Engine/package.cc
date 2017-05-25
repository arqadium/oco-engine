/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "package.hh"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>



using boost::filesystem::ifstream;
using boost::filesystem::path;
using std::array;
using std::runtime_error;
using std::ios_base;
using std::uint8_t;
using std::uintmax_t;
using std::vector;
using std::wstring;

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
const wstring pkgExt{ reinterpret_cast<wchar_t*>(u".oampkg.tar.lz4") };
constexpr uintmax_t headerRawSize = 0x1C;
constexpr uint8_t curVersion = 0;

bool hasEnding( wstring const& fullString, wstring const& ending )
{
	if(fullString.length( ) >= ending.length( ))
	{
		return (0 == fullString.compare( fullString.length( ) -
			ending.length( ), ending.length( ), ending ));
	}
	
	return false;
}

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

Engine::Package::Package( path filePath, bool check )
{
	// Check our checksum table's checksum
	if(check) { this->ChecksumsInvalid( ); }
	
	this->checked = check;

	// Ensure path name ends in our format's file extension
	if(!hasEnding( filePath.wstring( ), pkgExt ))
	{
		throw runtime_error{ "File extension is invalid" };
	}

	// Open our stream as binary input at the beginning
	this->stream.open( filePath, ifstream::in | ifstream::binary );
	this->stream.seekg( ios_base::beg );

	// Read the file header into a byte vector
	vector<uint8_t> headerRaw;

	headerRaw.resize( headerRawSize );
	this->stream.read( reinterpret_cast<char*>(headerRaw.data( )),
		headerRawSize );

	// Abort if the header doesn't match
	if(!headerMatch( headerRaw ))
	{
		throw runtime_error{ "File header bytes are invalid" };
	}

	this->IndexFiles( );
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
