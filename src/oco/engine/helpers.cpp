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

using OCo::Helpers::singleBit;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::uint32_t;
using std::uint8_t;
using std::vector;

constexpr auto logPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};

constexpr auto logDPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixNoANSI{u8"[\u00D4\u00C7\u00F4] "};

static void ocoPrint( const char* str, const char* prefix )
{
    cout << prefix << str << endl;
}

void ocoLog( const char* str )
{
    ocoPrint( str, logPrefix );
}

void ocoInfo( const char* str )
{
    ocoPrint( str, logPrefixGood );
}

void ocoWarn( const char* str )
{
    ocoPrint( str, logPrefixNeutral );
}

void ocoError( const char* str )
{
    ocoPrint( str, logPrefixBad );
}

static bool ocoPrint_D( const char* str, const char* prefix )
{
    ocoPrint( str, prefix );

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

void OCo::Helpers::Log( string str )
{
    ocoLog( str.c_str( ) );
}

void OCo::Helpers::Log( const char* str )
{
    ocoLog( str );
}

void OCo::Helpers::Log( vector<string> lines )
{
    for( auto& line : lines )
    {
        ocoLog( line.c_str( ) );
    }
}

void OCo::Helpers::Info( string str )
{
    ocoInfo( str.c_str( ) );
}

void OCo::Helpers::Info( const char* str )
{
    ocoInfo( str );
}

void OCo::Helpers::Info( vector<string> lines )
{
    for( auto& line : lines )
    {
        ocoInfo( line.c_str( ) );
    }
}

void OCo::Helpers::Warn( string str )
{
    ocoWarn( str.c_str( ) );
}

void OCo::Helpers::Warn( const char* str )
{
    ocoWarn( str );
}

void OCo::Helpers::Warn( vector<string> lines )
{
    for( auto& line : lines )
    {
        ocoWarn( line.c_str( ) );
    }
}

void OCo::Helpers::Error( string str )
{
    ocoError( str.c_str( ) );
}

void OCo::Helpers::Error( const char* str )
{
    ocoError( str );
}

void OCo::Helpers::Error( vector<string> lines )
{
    for( auto& line : lines )
    {
        ocoError( line.c_str( ) );
    }
}

namespace
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
}

string OCo::Helpers::ANSIFormat( string str, uint32_t opts )
{
    stringstream ret;

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
            return string{""};
        }
    }

    ret << kANSIEnd << str;

    return ret.str( );
}

string OCo::Helpers::ANSIFormat( const char* str, uint32_t opts )
{
    string tmp{str};

    return ANSIFormat( tmp, opts );
}
