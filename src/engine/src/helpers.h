/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_ENGINE_HELPERS_H )
#define INC__OCO_ENGINE_HELPERS_H ( 1 )

#if !defined( __cplusplus )

///
/// C INTERFACE
///

#if !defined( _WIN32 )
void ocoLog( const char* str );
void ocoInfo( const char* str );
void ocoWarn( const char* str );
void ocoError( const char* str );
#else // defined( _WIN32 )
void ocoLog( const wchar_t* str );
void ocoInfo( const wchar_t* str );
void ocoWarn( const wchar_t* str );
void ocoError( const wchar_t* str );
#endif // !defined( _WIN32 )

#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

#include <array>
#include <cstdint>
#include <string>
#include <vector>

#if !defined( _WIN32 )
extern "C" void ocoLog( const char* str );
extern "C" void ocoInfo( const char* str );
extern "C" void ocoWarn( const char* str );
extern "C" void ocoError( const char* str );
#else // defined( _WIN32 )
extern "C" void ocoLog( const wchar_t* str );
extern "C" void ocoInfo( const wchar_t* str );
extern "C" void ocoWarn( const wchar_t* str );
extern "C" void ocoError( const wchar_t* str );
#endif // !defined( _WIN32 )

namespace OCo
{
namespace Helpers
{

namespace ANSI
{

enum Codes : std::uint32_t
{
    None      = 0x0,
    Bold      = 0x1,
    Underline = 0x2,
    Blink     = 0x4,
    Reverse   = 0x8,
    Invisible = 0x10,
    BlackFG   = 0x20,
    WhiteFG   = 0x40,
    RedFG     = 0x80,
    GreenFG   = 0x100,
    BlueFG    = 0x200,
    CyanFG    = 0x400,
    YellowFG  = 0x800,
    MagentaFG = 0x1000,
    BlackBG   = 0x2000,
    WhiteBG   = 0x4000,
    RedBG     = 0x8000,
    GreenBG   = 0x10000,
    BlueBG    = 0x20000,
    CyanBG    = 0x40000,
    YellowBG  = 0x80000,
    MagentaBG = 0x100000,
};
} // namespace ANSI

constexpr std::uint32_t singleBit( std::uint8_t which )
{
    if( which > 31 )
    {
        return 0;
    }

    return 1 << which;
}

#if !defined( _WIN32 )
void Log( std::string str );
void Log( const char* str );
void Log( std::vector<std::string> str );

void Info( std::string str );
void Info( const char* str );
void Info( std::vector<std::string> str );

void Warn( std::string str );
void Warn( const char* str );
void Warn( std::vector<std::string> str );

void Error( std::string str );
void Error( const char* str );
void Error( std::vector<std::string> str );

std::string ANSIFormat( std::string str, std::uint32_t opts );
std::string ANSIFormat( const char* str, std::uint32_t opts );
#else // defined( _WIN32 )
void Log( std::wstring str );
void Log( const wchar_t* str );
void Log( std::vector<std::wstring> str );

void Info( std::wstring str );
void Info( const wchar_t* str );
void Info( std::vector<std::wstring> str );

void Warn( std::wstring str );
void Warn( const wchar_t* str );
void Warn( std::vector<std::wstring> str );

void Error( std::wstring str );
void Error( const wchar_t* str );
void Error( std::vector<std::wstring> str );

std::wstring ANSIFormat( std::wstring str, std::uint32_t opts );
std::wstring ANSIFormat( const wchar_t* str, std::uint32_t opts );
#endif // !defined( _WIN32 )

inline std::uint16_t charArrToU16( std::array<char, 2> bytes )
{
    uint16_t ret{0};

    ret |= static_cast<uint16_t>( bytes[0] ) << 8;
    ret |= static_cast<uint16_t>( bytes[1] );

    return ret;
}

inline std::uint32_t charArrToU32( std::array<char, 4> bytes )
{
    std::uint32_t ret{0};

    ret |= static_cast<std::uint32_t>( bytes[0] ) << 24;
    ret |= static_cast<std::uint32_t>( bytes[1] ) << 16;
    ret |= static_cast<std::uint32_t>( bytes[2] ) << 8;
    ret |= static_cast<std::uint32_t>( bytes[3] );

    return ret;
}

inline std::uint64_t charArrToU64( std::array<char, 8> bytes )
{
    std::uint64_t ret{0};

    ret |= static_cast<std::uint64_t>( bytes[0] ) << 56;
    ret |= static_cast<std::uint64_t>( bytes[1] ) << 48;
    ret |= static_cast<std::uint64_t>( bytes[2] ) << 40;
    ret |= static_cast<std::uint64_t>( bytes[3] ) << 32;
    ret |= static_cast<std::uint64_t>( bytes[4] ) << 24;
    ret |= static_cast<std::uint64_t>( bytes[5] ) << 16;
    ret |= static_cast<std::uint64_t>( bytes[6] ) << 8;
    ret |= static_cast<std::uint64_t>( bytes[7] );

    return ret;
}
} // namespace Helpers
} // namespace OCo

#endif // !defined( __cplusplus )
#endif // !defined( INC__OCO_ENGINE_HELPERS_H )
