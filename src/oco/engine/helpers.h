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

void ocoLog( const char* str );
void ocoInfo( const char* str );
void ocoWarn( const char* str );
void ocoError( const char* str );

#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

#include <array>
#include <cstdint>

extern "C" void ocoLog( const char* str );
extern "C" void ocoInfo( const char* str );
extern "C" void ocoWarn( const char* str );
extern "C" void ocoError( const char* str );

namespace OCo
{
namespace Helpers
{

namespace ANSI
{

constexpr auto kANSIReset{u8"\033[0m"};
constexpr auto kANSIStart{u8"\033["};
constexpr auto kANSISep{u8";"};
constexpr auto kANSIEnd{u8"m"};
constexpr auto kANSICodeBold{u8"1"};
constexpr auto kANSICodeUnderline{u8"4"};
constexpr auto kANSICodeBlink{u8"5"};
constexpr auto kANSICodeReverse{u8"7"};
constexpr auto kANSICodeBlackF{u8"30"};
constexpr auto kANSICodeWhiteF{u8"37"};
constexpr auto kANSICodeRedF{u8"31"};
constexpr auto kANSICodeGreenF{u8"32"};
constexpr auto kANSICodeBlueF{u8"34"};
constexpr auto kANSICodeCyanF{u8"36"};
constexpr auto kANSICodeYellowF{u8"33"};
constexpr auto kANSICodeMagentaF{u8"35"};
constexpr auto kANSICodeBlackB{u8"40"};
constexpr auto kANSICodeWhiteB{u8"47"};
constexpr auto kANSICodeRedB{u8"41"};
constexpr auto kANSICodeGreenB{u8"42"};
constexpr auto kANSICodeBlueB{u8"44"};
constexpr auto kANSICodeCyanB{u8"46"};
constexpr auto kANSICodeYellowB{u8"43"};
constexpr auto kANSICodeMagentaB{u8"45"};
} // namespace ANSI

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
