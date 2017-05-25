/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "package.hh"

#include <array>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/crc.hpp>
#include <boost/filesystem.hpp>

#include "config.h"



using boost::crc_32_type;
using boost::filesystem::ifstream;
using boost::filesystem::path;
using std::array;
using std::runtime_error;
using std::ios;
using std::size_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::uint8_t;
using std::uintmax_t;
using std::vector;
using std::wstring;

namespace
{

// Imported from config.h
const wstring pkgExt{ Config::pkgFileExt_L };
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

bool headerMismatch( vector<uint8_t> data )
{
	for(uintmax_t i = 0; i < Config::magicBytesSz; ++i)
	{
		if(data.at( i ) != Config::magicBytes[i])
		{
			return true;
		}
	}
	return false;
}

uint16_t charArrToU16( array<char, 2> bytes )
{
	uint16_t ret{ 0 };

	ret |= static_cast<uint16_t>(bytes[0]) << 8;
	ret |= static_cast<uint16_t>(bytes[1]);

	return ret;
}

uint32_t charArrToU32( array<char, 4> bytes )
{
	uint32_t ret{ 0 };

	ret |= static_cast<uint32_t>(bytes[0]) << 24;
	ret |= static_cast<uint32_t>(bytes[1]) << 16;
	ret |= static_cast<uint32_t>(bytes[2]) << 8;
	ret |= static_cast<uint32_t>(bytes[3]);

	return ret;
}

uint64_t charArrToU64( array<char, 8> bytes )
{
	uint64_t ret{ 0 };

	ret |= static_cast<uint64_t>(bytes[0]) << 56;
	ret |= static_cast<uint64_t>(bytes[1]) << 48;
	ret |= static_cast<uint64_t>(bytes[2]) << 40;
	ret |= static_cast<uint64_t>(bytes[3]) << 32;
	ret |= static_cast<uint64_t>(bytes[4]) << 24;
	ret |= static_cast<uint64_t>(bytes[5]) << 16;
	ret |= static_cast<uint64_t>(bytes[6]) << 8;
	ret |= static_cast<uint64_t>(bytes[7]);

	return ret;
}

} // namespace

Engine::Package::Package( path filePath, bool check )
{
	// Ensure path name ends in our format's file extension
	if(!hasEnding( filePath.wstring( ), pkgExt ))
	{
		throw runtime_error{ Config::Err::badFileExt };
	}

	// Ensure stream is open and seek to beginning
	this->EnsureOpenStream( );
	this->stream.seekg( ios::beg );

	// Read the file header into a byte vector
	vector<uint8_t> headerRaw;

	headerRaw.resize( headerRawSize );
	this->stream.read( reinterpret_cast<char*>(headerRaw.data( )),
		headerRawSize );

	// Abort if the header doesn't match
	if(headerMismatch( headerRaw ))
	{
		throw runtime_error{ Config::Err::badFileHeader };
	}

	// Check our checksum table's checksum
	if(check && this->ChecksumsInvalid( ))
	{
		throw runtime_error{ Config::Err::badChecksum };
	}

	this->checked = check;
	// Index the FAT
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
	// Read in and format the file count, to size up the checksum table
	array<char, 2> fileCountBytes;
	uint16_t fileCount;

	this->stream.seekg( 0x10 );
	this->stream.read( fileCountBytes.data( ), 2 );

	fileCount = charArrToU16( fileCountBytes );

	// Read in the checksum table
	const size_t crcTableSz{ static_cast<size_t>(fileCount * 4) };
	vector<uint8_t> crcTable{ };

	crcTable.resize( crcTableSz );
	this->stream.seekg( 0x30 );
	this->stream.read( reinterpret_cast<char*>(crcTable.data( )),
		crcTableSz );

	// Retrieve our expected checksum
	array<char, 4> expectedBytes;
	this->stream.seekg( 0x14 );
	this->stream.read( expectedBytes.data( ), 4 );

	// We're done with the stream, so close it
	this->EnsureClosedStream( );

	uint32_t expected{ charArrToU32( expectedBytes ) };
	crc_32_type tableChecksum;

	// Retrieve our actual checksum
	tableChecksum.process_bytes( reinterpret_cast<void*>(crcTable.data( )),
		crcTableSz );

	uint32_t actual{ tableChecksum.checksum( ) };

	return expected != actual;
}

void Engine::Package::EnsureOpenStream( )
{
	if(!this->stream.is_open( ))
	{
		// Open our stream as binary input at the beginning
		this->stream.open( this->filePath, ifstream::in | ifstream::binary );

		// Ensure it opened
		if(!this->stream.is_open( ))
		{
			throw runtime_error{ Config::Err::badFileStreamRead };
		}
	}
}

void Engine::Package::EnsureClosedStream( )
{
	if(this->stream.is_open( ))
	{
		this->stream.close( );

		if(this->stream.is_open( ))
		{
			throw runtime_error( Config::Err::cannotCloseStream );
		}
	}
}
