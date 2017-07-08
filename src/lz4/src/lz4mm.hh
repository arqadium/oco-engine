/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_LZ4_LZ4_HH
#define INC__MOCHI_LZ4_LZ4_HH ( 1 )

#include <cstdint>
#include <vector>

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
}

#endif // INC__MOCHI_LZ4_LZ4_HH
