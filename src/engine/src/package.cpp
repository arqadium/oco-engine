/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include "package.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/crc.hpp>
#include <boost/filesystem.hpp>

#include "config.h"

#include "except.hpp"
#include "helpers.h"

using boost::crc_32_type;
using boost::filesystem::ifstream;
using boost::filesystem::path;
using Engine::Exception;
using Engine::Helpers::charArrToU16;
using Engine::Helpers::charArrToU32;
using std::array;
using std::runtime_error;
using std::ios;
#ifndef _WIN32
using std::string;
#endif
using std::size_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::uint8_t;
using std::uintmax_t;
using std::vector;
#ifdef _WIN32
using std::wstring;
#endif

namespace
{

// Imported from config.h
constexpr size_t magicBytesSz{0x1C};
constexpr uint8_t curVersion{0};
constexpr size_t headerSize{0x30};
constexpr size_t fileCountOffset{0x10};
constexpr size_t crcTableCrcOffset{0x14};

#ifdef _WIN32
bool endsWith( wstring const& fullString, wstring const& ending )
#else // _WIN32
bool endsWith( string const& fullString, string const& ending )
#endif
{
    if( fullString.length( ) >= ending.length( ) )
    {
        return ( 0 ==
            fullString.compare( fullString.length( ) - ending.length( ),
                ending.length( ),
                ending ) );
    }

    return false;
}

bool headerMismatch( vector<uint8_t> data )
{
    for( uintmax_t i = 0; i < Config::kPkgMagicBytesSz; ++i )
    {
        if( data.at( i ) != Config::kPkgMagicBytes[i] )
        {
            return true;
        }
    }
    return false;
}

} // namespace

Engine::Package::Package( path filePath, bool check )
{
    // Ensure path name ends in our format's file extension
    if( !endsWith( filePath.string( ), Config::kPkgFileExt ) )
    {
        throw Exception{Config::Err::kBadFileExt};
    }

    // Ensure stream is open and seek to beginning
    this->EnsureOpenStream( );
    this->stream.seekg( ios::beg );

    // Read the file header into a byte vector
    vector<uint8_t> headerRaw;

    headerRaw.resize( Config::kPkgMagicBytesSz );
    this->stream.read( reinterpret_cast<char*>( headerRaw.data( ) ),
        Config::kPkgMagicBytesSz );

    // Abort if the header doesn't match
    if( headerMismatch( headerRaw ) )
    {
        throw Exception{Config::Err::kBadFileHeader};
    }

    // Check our checksum table's checksum
    if( check && this->ChecksumsInvalid( ) )
    {
        throw Exception{Config::Err::kBadChecksum};
    }

    this->checked = check;
    // Index the FAT
    this->IndexFiles( );
}

Engine::Package::~Package( )
{
    if( this->stream.is_open( ) )
    {
        this->stream.close( );
    }
}

void Engine::Package::IndexFiles( ) {}

bool Engine::Package::ChecksumsInvalid( )
{
    // Read in and format the file count, to size up the checksum table
    array<char, sizeof( uint16_t )> fileCountBytes;
    uint16_t fileCount;

    this->stream.seekg( fileCountOffset );
    this->stream.read( fileCountBytes.data( ), sizeof( uint16_t ) );

    fileCount = charArrToU16( fileCountBytes );

    // Read in the checksum table
    const size_t crcTableSz{
        static_cast<size_t>( fileCount * sizeof( uint32_t ) )};
    vector<uint8_t> crcTable{};

    crcTable.resize( crcTableSz );
    this->stream.seekg( headerSize );
    this->stream.read(
        reinterpret_cast<char*>( crcTable.data( ) ), crcTableSz );

    // Retrieve our expected checksum
    array<char, sizeof( uint32_t )> expectedBytes;
    this->stream.seekg( crcTableCrcOffset );
    this->stream.read( expectedBytes.data( ), sizeof( uint32_t ) );

    // We're done with the stream, so close it
    this->EnsureClosedStream( );

    uint32_t expected{charArrToU32( expectedBytes )};
    crc_32_type tableChecksum;

    // Retrieve our actual checksum
    tableChecksum.process_bytes(
        reinterpret_cast<void*>( crcTable.data( ) ), crcTableSz );

    uint32_t actual{tableChecksum.checksum( )};

    return expected != actual;
}

void Engine::Package::EnsureOpenStream( )
{
    if( !this->stream.is_open( ) )
    {
        // Open our stream as binary input at the beginning
        this->stream.open( this->filePath, ifstream::in | ifstream::binary );

        // Ensure it opened
        if( !this->stream.is_open( ) )
        {
            throw Exception{Config::Err::kBadFileStreamRead};
        }
    }
}

void Engine::Package::EnsureClosedStream( )
{
    if( this->stream.is_open( ) )
    {
        this->stream.close( );

        if( this->stream.is_open( ) )
        {
            throw Exception{Config::Err::kCannotCloseStream};
        }
    }
}
