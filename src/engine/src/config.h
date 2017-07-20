/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_ENGINE_CONFIG_H )
#define INC__OCO_ENGINE_CONFIG_H ( 1 )

///
/// C INTERFACE
///

#if !defined( __cplusplus )
#if !defined( _WIN32 )

#if __STDC_VERSION__ >= 201112L

#define CFG__PKG_FILE_EXT u8".oampkg.tar.lz4"
#define CFG__ERR_BAD_FILE_HEADER u8"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_EXT u8"File extension is invalid"
#define CFG__ERR_BAD_FILE_STREAM u8"Failed to open file (read)"
#define CFG__ERR_BAD_CHECKSUM u8"Checksumming failed"
#define CFG__ERR_CANNOT_CLOSE_STREAM u8"Cannot close file stream"

#else // __STDC_VERSION__ >= 201112L

#define CFG__PKG_FILE_EXT ".oampkg.tar.lz4"
#define CFG__ERR_BAD_FILE_HEADER "File header bytes are invalid"
#define CFG__ERR_BAD_FILE_EXT "File extension is invalid"
#define CFG__ERR_BAD_FILE_STREAM "Failed to open file (read)"
#define CFG__ERR_BAD_CHECKSUM "Checksumming failed"
#define CFG__ERR_CANNOT_CLOSE_STREAM "Cannot close file stream"

#endif // __STDC_VERSION__ >= 201112L

#else // defined( _WIN32 )

#define CFG__PKG_FILE_EXT_L L".oampkg.tar.lz4"
#define CFG__ERR_BAD_FILE_HEADER_L L"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_EXT_L L"File extension is invalid"
#define CFG__ERR_BAD_FILE_STREAM_L L"Failed to open file (read)"
#define CFG__ERR_BAD_CHECKSUM_L L"Checksumming failed"
#define CFG__ERR_CANNOT_CLOSE_STREAM_L L"Cannot close file stream"

#endif // !defined( _WIN32 )

#elif __cplusplus <= 199711L
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

#include <cstddef>

namespace Config
{

#if !defined( _WIN32 )

constexpr auto kPkgFileExt{u8".oampkg.tar.lz4"};

#else // defined( _WIN32 )

constexpr auto kPkgFileExt{L".oampkg.tar.lz4"};

#endif // !defined( _WIN32 )

namespace Err
{

#if !defined( _WIN32 )

constexpr auto kBadFileHeader{u8"File header bytes are invalid"};
constexpr auto kBadFileExt{u8"File extension is invalid"};
constexpr auto kBadFileStreamRead{u8"Failed to open file (read)"};
constexpr auto kBadChecksum{u8"Checksumming failed"};
constexpr auto kCannotCloseStream{u8"Cannot close file stream"};

#else // defined( _WIN32 )

constexpr auto kBadFileHeader{L"File header bytes are invalid"};
constexpr auto kBadFileExt{L"File extension is invalid"};
constexpr auto kBadFileStreamRead{L"Failed to open file (read)"};
constexpr auto kBadChecksum{L"Checksumming failed"};
constexpr auto kCannotCloseStream{L"Cannot close file stream"};

#endif // !defined( _WIN32 )
}
}

#endif // __cplusplus

#endif // !defined( INC__OCO_ENGINE_CONFIG_H )
