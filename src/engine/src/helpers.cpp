/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include "helpers.h"

#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/locale.hpp>

#include "win32.h"

#if defined( _WIN32 )
using boost::locale::conv::conversion_error;
using boost::locale::conv::utf_to_utf;
#endif // defined( _WIN32 )
using OCo::Helpers::singleBit;
using std::endl;
using std::string;
using std::uint32_t;
using std::uint8_t;
using std::vector;

#if !defined( _WIN32 )
using std::cerr;
using std::cout;
using std::stringstream;
#else // defined( _WIN32 )
using std::wcerr;
using std::wcout;
using std::wstring;
using std::wstringstream;
#endif // !defined( _WIN32 )

#if !defined( _WIN32 )
constexpr auto logPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};
#else
constexpr auto logPrefix{L"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixGood{L"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNeutral{L"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixBad{L"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNoANSI{L"[\u00D4\u00C7\u00F4] "};
#endif

constexpr auto logDPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixNoANSI{u8"[\u00D4\u00C7\u00F4] "};

#if !defined( _WIN32 )
static void ocoPrint( const char* str, const char* prefix )
#else // defined( _WIN32 )
static void ocoPrint( const wchar_t* str, const wchar_t* prefix )
#endif // !defined( _WIN32 )
{
#if defined( _WIN32 )
    if( OCo::SupportsANSI( ) )
    {
        wcout << prefix;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str << endl;
#else // !defined( _WIN32 )
    cout << prefix << str << endl;
#endif // defined( _WIN32 )
}

#if !defined( _WIN32 )
void ocoLog( const char* str )
#else // defined( _WIN32 )
void ocoLog( const wchar_t* str )
#endif // !defined( _WIN32 )
{
    ocoPrint( str, logPrefix );
}

#if !defined( _WIN32 )
void ocoInfo( const char* str )
#else // defined( _WIN32 )
void ocoInfo( const wchar_t* str )
#endif // !defined( _WIN32 )
{
    ocoPrint( str, logPrefixGood );
}

#if !defined( _WIN32 )
void ocoWarn( const char* str )
#else // defined( _WIN32 )
void ocoWarn( const wchar_t* str )
#endif // !defined( _WIN32 )
{
    ocoPrint( str, logPrefixNeutral );
}

#if !defined( _WIN32 )
void ocoError( const char* str )
#else // defined( _WIN32 )
void ocoError( const wchar_t* str )
#endif // !defined( _WIN32 )
{
    ocoPrint( str, logPrefixBad );
}

static bool ocoPrint_D( const char* str, const char* prefix )
{
#if defined( _WIN32 )
    wstring _str;

    try
    {
        _str = utf_to_utf<wchar_t, char>( str );
    }
    catch( conversion_error& )
    {
        if( OCo::SupportsANSI( ) )
        {
            wcout << logPrefixBad;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << L"Unicode conversion error in logging function!" << endl;

        return true;
    }

    ocoPrint(
        _str.c_str( ), utf_to_utf<wchar_t, char>( string( prefix ) ).c_str( ) );

#else // !defined( _WIN32 )
    ocoPrint( str, prefix );
#endif // defined( _WIN32 )

    return false;
}

extern "C" bool ocoLog_D( const char* str )
{
    return ocoPrint_D( str, logDPrefix );
}

extern "C" bool ocoInfo_D( const char* str )
{
    return ocoPrint_D( str, logDPrefixGood );
}

extern "C" bool ocoWarn_D( const char* str )
{
    return ocoPrint_D( str, logDPrefixNeutral );
}

extern "C" bool ocoError_D( const char* str )
{
    return ocoPrint_D( str, logDPrefixBad );
}

#if !defined( _WIN32 )
void OCo::Helpers::Log( string str )
#else // defined( _WIN32 )
void OCo::Helpers::Log( wstring str )
#endif // !defined( _WIN32 )
{
    ocoLog( str.c_str( ) );
}

#if !defined( _WIN32 )
void OCo::Helpers::Log( const char* str )
#else // defined( _WIN32 )
void OCo::Helpers::Log( const wchar_t* str )
#endif // defined( _WIN32 )
{
    ocoLog( str );
}

#if !defined( _WIN32 )
void OCo::Helpers::Log( vector<string> lines )
#else // defined( _WIN32 )
void OCo::Helpers::Log( vector<wstring> lines )
#endif // !defined( _WIN32 )
{
    for( auto& line : lines )
    {
        ocoLog( line.c_str( ) );
    }
}

#if !defined( _WIN32 )
void OCo::Helpers::Info( string str )
#else // defined( _WIN32 )
void OCo::Helpers::Info( wstring str )
#endif // !defined( _WIN32 )
{
    ocoInfo( str.c_str( ) );
}

#if !defined( _WIN32 )
void OCo::Helpers::Info( const char* str )
#else // defined( _WIN32 )
void OCo::Helpers::Info( const wchar_t* str )
#endif // defined( _WIN32 )
{
    ocoInfo( str );
}

#if !defined( _WIN32 )
void OCo::Helpers::Info( vector<string> lines )
#else // defined( _WIN32 )
void OCo::Helpers::Info( vector<wstring> lines )
#endif // !defined( _WIN32 )
{
    for( auto& line : lines )
    {
        ocoInfo( line.c_str( ) );
    }
}

#if !defined( _WIN32 )
void OCo::Helpers::Warn( string str )
#else // defined( _WIN32 )
void OCo::Helpers::Warn( wstring str )
#endif // !defined( _WIN32 )
{
    ocoWarn( str.c_str( ) );
}

#if !defined( _WIN32 )
void OCo::Helpers::Warn( const char* str )
#else // defined( _WIN32 )
void OCo::Helpers::Warn( const wchar_t* str )
#endif // defined( _WIN32 )
{
    ocoWarn( str );
}

#if !defined( _WIN32 )
void OCo::Helpers::Warn( vector<string> lines )
#else // defined( _WIN32 )
void OCo::Helpers::Warn( vector<wstring> lines )
#endif // !defined( _WIN32 )
{
    for( auto& line : lines )
    {
        ocoWarn( line.c_str( ) );
    }
}

#if !defined( _WIN32 )
void OCo::Helpers::Error( string str )
#else // defined( _WIN32 )
void OCo::Helpers::Error( wstring str )
#endif // !defined( _WIN32 )
{
    ocoError( str.c_str( ) );
}

#if !defined( _WIN32 )
void OCo::Helpers::Error( const char* str )
#else // defined( _WIN32 )
void OCo::Helpers::Error( const wchar_t* str )
#endif // defined( _WIN32 )
{
    ocoError( str );
}

#if !defined( _WIN32 )
void OCo::Helpers::Error( vector<string> lines )
#else // defined( _WIN32 )
void OCo::Helpers::Error( vector<wstring> lines )
#endif // !defined( _WIN32 )
{
    for( auto& line : lines )
    {
        ocoError( line.c_str( ) );
    }
}

namespace
{
#if !defined( _WIN32 )
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
#else // defined( _WIN32 )
constexpr auto kANSIReset{L"\033[0m"};
constexpr auto kANSIStart{L"\033["};
constexpr auto kANSISep{L";"};
constexpr auto kANSIEnd{L"m"};
constexpr auto kANSICodeBold{L"1"};
constexpr auto kANSICodeUnderline{L"4"};
constexpr auto kANSICodeBlink{L"5"};
constexpr auto kANSICodeReverse{L"7"};
constexpr auto kANSICodeBlackF{L"30"};
constexpr auto kANSICodeWhiteF{L"37"};
constexpr auto kANSICodeRedF{L"31"};
constexpr auto kANSICodeGreenF{L"32"};
constexpr auto kANSICodeBlueF{L"34"};
constexpr auto kANSICodeCyanF{L"36"};
constexpr auto kANSICodeYellowF{L"33"};
constexpr auto kANSICodeMagentaF{L"35"};
constexpr auto kANSICodeBlackB{L"40"};
constexpr auto kANSICodeWhiteB{L"47"};
constexpr auto kANSICodeRedB{L"41"};
constexpr auto kANSICodeGreenB{L"42"};
constexpr auto kANSICodeBlueB{L"44"};
constexpr auto kANSICodeCyanB{L"46"};
constexpr auto kANSICodeYellowB{L"43"};
constexpr auto kANSICodeMagentaB{L"45"};
#endif // !defined( _WIN32 )
}

#if !defined( _WIN32 )
string OCo::Helpers::ANSIFormat( string str, uint32_t opts )
#else // defined( _WIN32 )
wstring OCo::Helpers::ANSIFormat( wstring str, uint32_t opts )
#endif // !defined( _WIN32 )
{
#if !defined( _WIN32 )
    stringstream ret;
#else // defined( _WIN32 )
    wstringstream ret;
#endif // !defined( _WIN32 )

    if( opts == 0 )
    {
        ret << kANSIReset << str;

        return ret.str( );
    }

    ret << kANSIStart;

    for( uint_least8_t i = 0; i < sizeof( uint32_t ) * 8; ++i )
    {
        if( i > 0 )
        {
            ret << kANSISep;
        }

        switch( opts & singleBit( i ) )
        {
        case OCo::Helpers::ANSI::None:
            break;
        case OCo::Helpers::ANSI::Bold:
            ret << kANSICodeBold;

            break;
        case OCo::Helpers::ANSI::Underline:
            ret << kANSICodeUnderline;

            break;
        case OCo::Helpers::ANSI::Blink:
            ret << kANSICodeBlink;

            break;
        case OCo::Helpers::ANSI::Reverse:
            ret << kANSICodeReverse;

            break;
        case OCo::Helpers::ANSI::BlackFG:
            ret << kANSICodeBlackF;

            break;
        case OCo::Helpers::ANSI::WhiteFG:
            ret << kANSICodeWhiteF;

            break;
        case OCo::Helpers::ANSI::RedFG:
            ret << kANSICodeRedF;

            break;
        case OCo::Helpers::ANSI::GreenFG:
            ret << kANSICodeGreenF;

            break;
        case OCo::Helpers::ANSI::BlueFG:
            ret << kANSICodeBlueF;

            break;
        case OCo::Helpers::ANSI::CyanFG:
            ret << kANSICodeCyanF;

            break;
        case OCo::Helpers::ANSI::YellowFG:
            ret << kANSICodeYellowF;

            break;
        case OCo::Helpers::ANSI::MagentaFG:
            ret << kANSICodeMagentaF;

            break;
        case OCo::Helpers::ANSI::BlackBG:
            ret << kANSICodeBlackB;

            break;
        case OCo::Helpers::ANSI::WhiteBG:
            ret << kANSICodeWhiteB;

            break;
        case OCo::Helpers::ANSI::RedBG:
            ret << kANSICodeRedB;

            break;
        case OCo::Helpers::ANSI::GreenBG:
            ret << kANSICodeGreenB;

            break;
        case OCo::Helpers::ANSI::BlueBG:
            ret << kANSICodeBlueB;

            break;
        case OCo::Helpers::ANSI::CyanBG:
            ret << kANSICodeCyanB;

            break;
        case OCo::Helpers::ANSI::YellowBG:
            ret << kANSICodeYellowB;

            break;
        case OCo::Helpers::ANSI::MagentaBG:
            ret << kANSICodeMagentaB;

            break;
        default:
#if !defined( _WIN32 )
            return string{""};
#else // defined( _WIN32 )
            return wstring{L""};
#endif // !defined( _WIN32 )
        }
    }

    ret << kANSIEnd << str;

    return ret.str( );
}

#if !defined( _WIN32 )
string OCo::Helpers::ANSIFormat( const char* str, uint32_t opts )
#else // defined( _WIN32 )
wstring OCo::Helpers::ANSIFormat( const wchar_t* str, uint32_t opts )
#endif // !defined( _WIN32 )
{
#if !defined( _WIN32 )
    string tmp{str};
#else // defined( _WIN32 )
    wstring tmp{str};
#endif // !defined( _WIN32 )

    return ANSIFormat( tmp, opts );
}
