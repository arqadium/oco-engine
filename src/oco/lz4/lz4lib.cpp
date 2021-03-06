/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include "lz4lib.h"

#include <cstddef>
#include <cstdint>
#include <vector>

#include "lz4.h"

using std::size_t;
using std::uint8_t;
using std::uintmax_t;
using std::vector;

bool ocoLZ4Compress(
    const uint8_t* src, size_t srcSz, uint8_t* dst, size_t dstSz )
{
    return !LZ4_compress_default( reinterpret_cast<const char*>( src ),
        reinterpret_cast<char*>( dst ),
        static_cast<int>( srcSz ),
        static_cast<int>( dstSz ) );
}

bool ocoLZ4DecompressSafe(
    const uint8_t* src, size_t srcSz, uint8_t* dst, size_t dstSz )
{
    return LZ4_decompress_safe( reinterpret_cast<const char*>( src ),
               reinterpret_cast<char*>( dst ),
               static_cast<int>( srcSz ),
               static_cast<int>( dstSz ) ) < 0;
}

bool ocoLZ4DecompressFast( const uint8_t* src, uint8_t* dst, size_t origSz )
{
    return LZ4_decompress_fast( reinterpret_cast<const char*>( src ),
               reinterpret_cast<char*>( dst ),
               static_cast<int>( origSz ) ) < 0;
}

bool OCo::LZ4::Compress( vector<uint8_t> source, vector<uint8_t> dest )
{
    const uintmax_t sourceSize = source.size( );
    const uintmax_t destSize =
        LZ4_compressBound( static_cast<int>( sourceSize ) );

    if( dest.size( ) < destSize )
    {
        dest.resize( destSize );
    }

    return !LZ4_compress_default(
        reinterpret_cast<const char*>( source.data( ) ),
        reinterpret_cast<char*>( dest.data( ) ),
        static_cast<int>( source.size( ) ),
        static_cast<int>( destSize ) );
}

bool OCo::LZ4::Decompress( vector<uint8_t> source, vector<uint8_t> dest )
{
    return LZ4_decompress_safe( reinterpret_cast<char*>( source.data( ) ),
               reinterpret_cast<char*>( dest.data( ) ),
               static_cast<int>( source.size( ) ),
               static_cast<int>( dest.size( ) ) ) < 0;
}

bool OCo::LZ4::Decompress(
    vector<uint8_t> source, vector<uint8_t> dest, uintmax_t originalSize )
{
    if( dest.size( ) < originalSize )
    {
        return true;
    }

    return LZ4_decompress_fast( reinterpret_cast<const char*>( source.data( ) ),
               reinterpret_cast<char*>( dest.data( ) ),
               static_cast<int>( originalSize ) ) < 0;
}
