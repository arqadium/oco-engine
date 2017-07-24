/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_UNTAR_UNTAR_H )
#define INC__OCO_UNTAR_UNTAR_H ( 1 )

#if !defined( __cplusplus )

///
/// C INTERFACE
///

#if __STDC_VERSION__ >= 201112L

#define OCO_UNTAR_MAGICBYTES u8"ustar"
#define OCO_UNTAR_MAGICBYTES_LEN 6
#define OCO_UNTAR_VERSION u8"00"
#define OCO_UNTAR_VERSION_LEN 2

#else // __STDC_VERSION__ < 201112L

#define OCO_UNTAR_MAGICBYTES "ustar"
#define OCO_UNTAR_MAGICBYTES_LEN 6
#define OCO_UNTAR_VERSION "00"
#define OCO_UNTAR_VERSION_LEN 2

#endif // __STDC_VERSION__ >= 201112L

/** ============================= S T R U C T ============================= **
 *
 * TITLE:       Tarball Header Block
 * DESCRIPTION: Specifies the header structure for POSIX 1003.1-1990
 *              compliant tar archives (a.k.a. tarballs).
 */
typedef struct
{
    uint8_t name[100]; // 0
    uint8_t mode[8]; // 100
    uint8_t uid[8]; // 108
    uint8_t gid[8]; // 116
    uint8_t size[12]; // 124
    uint8_t mtime[12]; // 136
    uint8_t checksum[8]; // 148
    uint8_t typeflag; // 156
    uint8_t linkname[100]; // 157
    uint8_t magic[OCO_UNTAR_MAGICBYTES_LEN]; // 257
    uint8_t version[OCO_UNTAR_VERSION_LEN]; // 263
    uint8_t uname[32]; // 265
    uint8_t gname[32]; // 297
    uint8_t devMajor[8]; // 329
    uint8_t devMinor[8]; // 337
    uint8_t prefix[155]; // 345
    uint8_t _padding[12]; // 500
} OCoTarHeader;

#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

namespace OCo
{
namespace Untar
{

constexpr auto kMagicBytes{"ustar"};
constexpr std::uint_least8_t kMagicBytesLen{6};
constexpr auto kVersion{"00"};
constexpr std::uint_least8_t kVersionLen{2};

struct Header
{
    std::uint8_t name[100]; // 0
    std::uint8_t mode[8]; // 100
    std::uint8_t uid[8]; // 108
    std::uint8_t gid[8]; // 116
    std::uint8_t size[12]; // 124
    std::uint8_t mtime[12]; // 136
    std::uint8_t checksum[8]; // 148
    std::uint8_t typeflag; // 156
    std::uint8_t linkname[100]; // 157
    std::uint8_t magic[kMagicBytesLen]; // 257
    std::uint8_t version[kVersionLen]; // 263
    std::uint8_t uname[32]; // 265
    std::uint8_t gname[32]; // 297
    std::uint8_t devMajor[8]; // 329
    std::uint8_t devMinor[8]; // 337
    std::uint8_t prefix[155]; // 345
    std::uint8_t _padding[12]; // 500
};

std::uint_least32_t Placeholder( );
} // namespace Untar
} // namespace OCo

#endif // !defined( __cplusplus )
#endif // !defined( INC__OCO_UNTAR_UNTAR_H )
