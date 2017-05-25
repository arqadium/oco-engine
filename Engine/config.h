/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_CONFIG_HH
#define INC__MOCHI_ENGINE_CONFIG_HH (1)

#ifndef __cplusplus

#if __STDC_VERSION__ >= 201112L

#define CFG__MAGIC_BYTES u8"\x89MOCHIPKG\r\n\x1A\n" // See notes below
#define CFG__PKG_FILE_EXT u8".mochipkg"
#define CFG__PKG_FILE_EXT_L u".mochipkg"
#define CFG__ERR_BAD_FILE_HEADER u8"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_HEADER_L u"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_EXT u8"File extension is invalid"
#define CFG__ERR_BAD_FILE_EXT_L u"File extension is invalid"
#define CFG__ERR_BAD_FILE_STREAM u8"Failed to open file (read)"
#define CFG__ERR_BAD_FILE_STREAM_L u"Failed to open file (read)"
#define CFG__ERR_BAD_CHECKSUM u8"Checksumming failed"
#define CFG__ERR_BAD_CHECKSUM_L u"Checksumming failed"
#define CFG__ERR_CANNOT_CLOSE_STREAM u8"Cannot close file stream"
#define CFG__ERR_CANNOT_CLOSE_STREAM_L u"Cannot close file stream"

#else

#define CFG__MAGIC_BYTES "\x89MOCHIPKG\r\n\x1A\n" // See notes below
#define CFG__PKG_FILE_EXT ".mochipkg"
#define CFG__PKG_FILE_EXT_L L".mochipkg"
#define CFG__ERR_BAD_FILE_HEADER "File header bytes are invalid"
#define CFG__ERR_BAD_FILE_HEADER_L L"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_EXT "File extension is invalid"
#define CFG__ERR_BAD_FILE_EXT_L L"File extension is invalid"
#define CFG__ERR_BAD_FILE_STREAM "Failed to open file (read)"
#define CFG__ERR_BAD_FILE_STREAM_L L"Failed to open file (read)"
#define CFG__ERR_BAD_CHECKSUM "Checksumming failed"
#define CFG__ERR_BAD_CHECKSUM_L L"Checksumming failed"
#define CFG__ERR_CANNOT_CLOSE_STREAM "Cannot close file stream"
#define CFG__ERR_CANNOT_CLOSE_STREAM_L L"Cannot close file stream"

#endif

#else

#include <cstddef>



namespace Config
{

constexpr auto magicBytes{
	"\x89" // High bit set to avoid 7-bit transmissions [1 byte]
	"MOCHIPKG" // File type identifier [8 bytes]
	"\r\n" // DOS-style line ending [2 bytes]
	"\x1A" // DOS End-of-file character [1 byte]
	"\n" // UNIX-style line ending [1 byte]
	// NOTE: there is a null terminator ('\0') character at the end here!
	// Total size: 14 (0xE) bytes
};
constexpr std::size_t magicBytesSz{ 0xE };
constexpr auto pkgFileExt{ ".mochipkg" };
constexpr auto pkgFileExt_L{ L".mochipkg" };

namespace Err
{

constexpr auto badFileHeader{ "File header bytes are invalid" };
constexpr auto badFileHeader_L{ L"File header bytes are invalid" };
constexpr auto badFileExt{ "File extension is invalid" };
constexpr auto badFileExt_L{ L"File extension is invalid" };
constexpr auto badFileStreamRead{ "Failed to open file (read)" };
constexpr auto badFileStreamRead_L{ L"Failed to open file (read)" };
constexpr auto badChecksum{ "Checksumming failed" };
constexpr auto badChecksum_L{ L"Checksumming failed" };
constexpr auto cannotCloseStream{ "Cannot close file stream" };
constexpr auto cannotCloseStream_L{ L"Cannot close file stream" };

}

}



#endif // __cplusplus

#endif // INC__MOCHI_ENGINE_CONFIG_HH
