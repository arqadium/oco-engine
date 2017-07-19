/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#ifndef INC__MOCHI_UNTAR_UNTAR_HH
#define INC__MOCHI_UNTAR_UNTAR_HH ( 1 )

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>

namespace Untar
{

constexpr auto kMagicBytes{"ustar"};
constexpr uint_least8_t kMagicBytesLen{6};
constexpr auto kVersion = {'0', '0'};
constexpr uint_least8_t kVersionLen{2};

/** ============================== C L A S S ============================== **
 *
 * TITLE:       Tarball Object
 * DESCRIPTION: Represents a read-only tarball object.
 */
class Tarball
{
    /** =========================== S T R U C T =========================== **
     *
     * TITLE:       Tarball Header Block
     * DESCRIPTION: Specifies the header structure for POSIX 1003.1-1990
     *              compliant tar archives (a.k.a. tarballs).
     */
    struct Header
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
        uint8_t magic[kMagicBytesLen]; // 257
        uint8_t version[kVersionLen]; // 263
        uint8_t uname[32]; // 265
        uint8_t gname[32]; // 297
        uint8_t devMajor[8]; // 329
        uint8_t devMinor[8]; // 337
        uint8_t prefix[155]; // 345
        uint8_t _padding[12]; // 500
    };

    /** =========================== S T R U C T =========================== **
     *
     * TITLE:       Tarball Entry Object
     * DESCRIPTION: Represents a single entry in a Tarball object.
     */
    struct TarEntry
    {
        TarEntry( Header& _header, std::uint_least64_t _offset )
            : header( dupHeader( _header ) ), offset( _offset )
        {
        }
        ~TarEntry( ) { delete header; }

        const Header* header;
        const std::uint_least64_t offset;

      private:
        Header* dupHeader( Header& _header )
        {
            auto head = reinterpret_cast<std::uint64_t*>( &_header );
            auto ret  = new std::uint64_t[64];

            for( uint_least8_t i = 0; i < 64; ++i )
            {
                ret[i] = head[i];
            }

            return reinterpret_cast<Header*>( ret );
        }
    };

    std::vector<TarEntry> entries;

  public:
    Tarball( boost::filesystem::path filePath );
    ~Tarball( );

    std::vector<std::uint8_t> ReadFile( std::string entryPath );
    std::vector<TarEntry> ListFiles( ) { return this->entries; }

  private:
    std::ifstream file;
};

std::uint_least32_t Placeholder( );
}

#endif // INC__MOCHI_UNTAR_UNTAR_HH
