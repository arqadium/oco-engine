/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_CONFIG_HH
#define INC__MOCHI_ENGINE_CONFIG_HH (1)

#ifndef __cplusplus

#define CFG__MAGIC_BYTES u8"\x89MOCHIPKG\r\n\x1A\n" // See notes below
#define CFG__PKG_FILE_EXT u8".mochipkg"
#define CFG__PKG_FILE_EXT_L u".mochipkg"
#define CFG__ERR_BAD_FILE_HEADER u8"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_HEADER_L u"File header bytes are invalid"
#define CFG__ERR_BAD_FILE_EXT u8"File extension is invalid"
#define CFG__ERR_BAD_FILE_EXT_L u"File extension is invalid"

#else

#include <cstddef>



namespace Config
{

constexpr auto magicBytes{
	u8"\x89" // High bit set to avoid 7-bit transmissions [1 byte]
	u8"MOCHIPKG" // File type identifier [8 bytes]
	u8"\r\n" // DOS-style line ending [2 bytes]
	u8"\x1A" // DOS End-of-file character [1 byte]
	u8"\n" // UNIX-style line ending [1 byte]
	// NOTE: there is a null terminator ('\0') character at the end here!
	// Total size: 14 (0xE) bytes
};
constexpr std::size_t magicBytesSz{ 0xE };
constexpr auto pkgFileExt{ u8".mochipkg" };
constexpr auto pkgFileExt_L{ reinterpret_cast<wchar_t*>(u".mochipkg") };

namespace Err
{

constexpr auto badFileHeader{ u8"File header bytes are invalid" };
constexpr auto badFileHeader_L{
	reinterpret_cast<wchar_t*>(u"File header bytes are invalid")
};
constexpr auto badFileExt{ u8"File extension is invalid" };
constexpr auto badFileExt_L{
	reinterpret_cast<wchar_t*>(u8"File extension is invalid")
};

}

}



#endif // __cplusplus

#endif // INC__MOCHI_ENGINE_CONFIG_HH
