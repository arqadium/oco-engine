/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
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
