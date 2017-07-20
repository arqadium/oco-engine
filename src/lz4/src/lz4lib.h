/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_LZ4_LZ4_H )
#define INC__OCO_LZ4_LZ4_H ( 1 )

#if !defined( __cplusplus )

///
/// C INTERFACE
///

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

bool ocoLZ4Compress(
    const uint8_t* src, size_t srcSz, uint8_t* dst, size_t dstSz );
bool ocoLZ4DecompressSafe(
    const uint8_t* src, size_t srcSz, uint8_t* dst, size_t dstSz );
bool ocoLZ4DecompressFast( const uint8_t* src, uint8_t* dst, size_t origSz );

#elif __cplusplus <= 199711L
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

#include <cstddef>
#include <cstdint>
#include <vector>

extern "C" bool ocoLZ4Compress( const std::uint8_t* src,
    std::size_t srcSz,
    std::uint8_t* dst,
    std::size_t dstSz );
extern "C" bool ocoLZ4DecompressSafe( const std::uint8_t* src,
    std::size_t srcSz,
    std::uint8_t* dst,
    std::size_t dstSz );
extern "C" bool ocoLZ4DecompressFast(
    const std::uint8_t* src, std::uint8_t* dst, std::size_t origSz );

namespace OCo
{
namespace LZ4
{
constexpr std::uint32_t versionMajor{1};
constexpr std::uint32_t versionMinor{7};
constexpr std::uint32_t versionPatch{5};

bool Compress(
    std::vector<std::uint8_t> source, std::vector<std::uint8_t> dest );
bool Decompress(
    std::vector<std::uint8_t> source, std::vector<std::uint8_t> dest );
bool Decompress( std::vector<std::uint8_t> source,
    std::vector<std::uint8_t> dest,
    std::uintmax_t originalSize );
} // namespace LZ4
} // namespace OCo

#endif // !defined( __cplusplus )
#endif // !defined( INC__OCO_LZ4_LZ4_H )
