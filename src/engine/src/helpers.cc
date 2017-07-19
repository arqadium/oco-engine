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

#include "except.hh"
#include "win32.hh"

using boost::locale::conv::utf_to_utf;
using Engine::Exception;
using Engine::Helpers::singleBit;
using std::endl;
using std::string;
using std::uint32_t;
using std::uint8_t;
using std::vector;
using std::wstring;

#ifndef _WIN32
using std::cerr;
using std::cout;
using std::stringstream;
#else
using std::wcerr;
using std::wcout;
using std::wstringstream;
#endif

#ifdef _WIN32

constexpr auto logPrefix{L"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixGood{L"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNeutral{L"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixBad{L"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNoANSI{L"[\u00D4\u00C7\u00F4] "};

#else

constexpr auto logPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};

#endif

bool ocoLog( const char* str )
{
    try
    {
        Engine::Helpers::Log( str, true );
    }
    catch( ... )
    {
        return true;
    }

    return false;
}

bool ocoInfo( const char* str )
{
    try
    {
        Engine::Helpers::Info( str, true );
    }
    catch( ... )
    {
        return true;
    }

    return false;
}

bool ocoWarn( const char* str )
{
    try
    {
        Engine::Helpers::Warn( str, true );
    }
    catch( ... )
    {
        return true;
    }

    return false;
}

bool ocoError( const char* str )
{
    try
    {
        Engine::Helpers::Error( str, true );
    }
    catch( ... )
    {
        return true;
    }

    return false;
}

void Engine::Helpers::Log( string str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefix;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefix << str;

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Log( const char* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefix;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefix << str;

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Log( wstring str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefix;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str;

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefix << utf_to_utf<char>( str );

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Log( const wchar_t* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefix;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str;

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefix << utf_to_utf<char>( str );

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Log( vector<string> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcout << logPrefix;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << utf_to_utf<wchar_t>( line );

        if( newline )
        {
            wcout << endl;
        }
#else
        cout << logPrefix << line;

        if( newline )
        {
            cout << endl;
        }
#endif
    }
}

void Engine::Helpers::Log( vector<wstring> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcout << logPrefix;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << line;

        if( newline )
        {
            wcout << endl;
        }
#else
        cout << logPrefix << utf_to_utf<char>( line );

        if( newline )
        {
            cout << endl;
        }
#endif
    }
}

void Engine::Helpers::Info( string str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixGood;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixGood << str;

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Info( const char* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixGood;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixGood << str;

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Info( wstring str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixGood;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str;

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixGood << utf_to_utf<char>( str );

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Info( const wchar_t* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixGood;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str;

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixGood << utf_to_utf<char>( str );

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Info( vector<string> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcout << logPrefixGood;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << utf_to_utf<wchar_t>( line );

        if( newline )
        {
            wcout << endl;
        }
#else
        cout << logPrefixGood << line;

        if( newline )
        {
            cout << endl;
        }
#endif
    }
}

void Engine::Helpers::Info( vector<wstring> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcout << logPrefixGood;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << line;

        if( newline )
        {
            wcout << endl;
        }
#else
        cout << logPrefixGood << utf_to_utf<char>( line );

        if( newline )
        {
            cout << endl;
        }
#endif
    }
}

void Engine::Helpers::Warn( string str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixNeutral;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixNeutral << str;

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Warn( const char* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixNeutral;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixNeutral << str;

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Warn( wstring str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixNeutral;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str;

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixNeutral << utf_to_utf<char>( str );

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Warn( const wchar_t* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcout << logPrefixNeutral;
    }
    else
    {
        wcout << logPrefixNoANSI;
    }

    wcout << str;

    if( newline )
    {
        wcout << endl;
    }
#else
    cout << logPrefixNeutral << utf_to_utf<char>( str );

    if( newline )
    {
        cout << endl;
    }
#endif
}

void Engine::Helpers::Warn( vector<string> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcout << logPrefixNeutral;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << utf_to_utf<wchar_t>( line );

        if( newline )
        {
            wcout << endl;
        }
#else
        cout << logPrefixNeutral << line;

        if( newline )
        {
            cout << endl;
        }
#endif
    }
}

void Engine::Helpers::Warn( vector<wstring> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcout << logPrefixNeutral;
        }
        else
        {
            wcout << logPrefixNoANSI;
        }

        wcout << line;

        if( newline )
        {
            wcout << endl;
        }
#else
        cout << logPrefixNeutral << utf_to_utf<char>( line );

        if( newline )
        {
            cout << endl;
        }
#endif
    }
}

void Engine::Helpers::Error( string str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcerr << logPrefixBad;
    }
    else
    {
        wcerr << logPrefixNoANSI;
    }

    wcerr << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcerr << endl;
    }
#else
    cerr << logPrefixBad << str;

    if( newline )
    {
        cerr << endl;
    }
#endif
}

void Engine::Helpers::Error( const char* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcerr << logPrefixBad;
    }
    else
    {
        wcerr << logPrefixNoANSI;
    }

    wcerr << utf_to_utf<wchar_t>( str );

    if( newline )
    {
        wcerr << endl;
    }
#else
    cerr << logPrefixBad << str;

    if( newline )
    {
        cerr << endl;
    }
#endif
}

void Engine::Helpers::Error( wstring str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcerr << logPrefixBad;
    }
    else
    {
        wcerr << logPrefixNoANSI;
    }

    wcerr << str;

    if( newline )
    {
        wcerr << endl;
    }
#else
    cerr << logPrefixBad << utf_to_utf<char>( str );

    if( newline )
    {
        cerr << endl;
    }
#endif
}

void Engine::Helpers::Error( const wchar_t* str, bool newline )
{
#ifdef _WIN32
    if( Engine::SupportsANSI( ) )
    {
        wcerr << logPrefixBad;
    }
    else
    {
        wcerr << logPrefixNoANSI;
    }

    wcerr << str;

    if( newline )
    {
        wcerr << endl;
    }
#else
    cerr << logPrefixBad << utf_to_utf<char>( str );

    if( newline )
    {
        cerr << endl;
    }
#endif
}

void Engine::Helpers::Error( vector<string> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcerr << logPrefixBad;
        }
        else
        {
            wcerr << logPrefixNoANSI;
        }

        wcerr << utf_to_utf<wchar_t>( line );

        if( newline )
        {
            wcerr << endl;
        }
#else
        cerr << logPrefixBad << line;

        if( newline )
        {
            cerr << endl;
        }
#endif
    }
}

void Engine::Helpers::Error( vector<wstring> str, bool newline )
{
#ifdef _WIN32
    const bool ansiSupport = Engine::SupportsANSI( );
#endif

    for( auto& line : str )
    {
#ifdef _WIN32
        if( ansiSupport )
        {
            wcerr << logPrefixBad;
        }
        else
        {
            wcerr << logPrefixNoANSI;
        }

        wcerr << line;

        if( newline )
        {
            wcerr << endl;
        }
#else
        cerr << logPrefixBad << utf_to_utf<char>( line );

        if( newline )
        {
            cerr << endl;
        }
#endif
    }
}

string Engine::Helpers::ANSIFormat( string str, uint32_t opts )
{
#ifdef _WIN32
    return string{utf_to_utf<char>( Engine::Helpers::ANSIFormat(
        wstring{utf_to_utf<wchar_t>( str )}, opts ) )};
#else
    stringstream ret;

    if( opts == 0 )
    {
        ret << u8"\033[0m" << str;

        return ret.str( );
    }

    ret << u8"\033[";

    for( uint8_t i = 0; i < 32; ++i )
    {
        if( i > 0 )
        {
            ret << ';';
        }

        switch( opts & singleBit( i ) )
        {
        case Engine::Helpers::ANSI::None:
            break;
        case Engine::Helpers::ANSI::Bold:
            ret << '1';

            break;
        case Engine::Helpers::ANSI::Underline:
            ret << '4';

            break;
        case Engine::Helpers::ANSI::Blink:
            ret << '5';

            break;
        case Engine::Helpers::ANSI::Reverse:
            ret << '7';

            break;
        case Engine::Helpers::ANSI::BlackFG:
            ret << "30";

            break;
        case Engine::Helpers::ANSI::WhiteFG:
            ret << "37";

            break;
        case Engine::Helpers::ANSI::RedFG:
            ret << "31";

            break;
        case Engine::Helpers::ANSI::GreenFG:
            ret << "32";

            break;
        case Engine::Helpers::ANSI::BlueFG:
            ret << "34";

            break;
        case Engine::Helpers::ANSI::CyanFG:
            ret << "36";

            break;
        case Engine::Helpers::ANSI::YellowFG:
            ret << "33";

            break;
        case Engine::Helpers::ANSI::MagentaFG:
            ret << "35";

            break;
        case Engine::Helpers::ANSI::BlackBG:
            ret << "40";

            break;
        case Engine::Helpers::ANSI::WhiteBG:
            ret << "47";

            break;
        case Engine::Helpers::ANSI::RedBG:
            ret << "41";

            break;
        case Engine::Helpers::ANSI::GreenBG:
            ret << "42";

            break;
        case Engine::Helpers::ANSI::BlueBG:
            ret << "44";

            break;
        case Engine::Helpers::ANSI::CyanBG:
            ret << "46";

            break;
        case Engine::Helpers::ANSI::YellowBG:
            ret << "43";

            break;
        case Engine::Helpers::ANSI::MagentaBG:
            ret << "45";

            break;
        default:
            throw Exception{u8"Invalid ANSI escape code provided"};
        }
    }

    ret << 'm' << str;

    return ret.str( );
#endif
}

string Engine::Helpers::ANSIFormat( const char* str, uint32_t opts )
{
    string tmp{str};

    return ANSIFormat( tmp, opts );
}

wstring Engine::Helpers::ANSIFormat( wstring str, uint32_t opts )
{
#ifdef _WIN32
    wstringstream ret;

    if( opts == 0 )
    {
        ret << L"\033[0m" << str;

        return ret.str( );
    }

    ret << L"\033[";

    for( uint8_t i = 0; i < 32; ++i )
    {
        if( i == 0 )
        {
            continue;
        }

        ret << L';';

        switch( opts & singleBit( i ) )
        {
        case Engine::Helpers::ANSI::None:
            break;
        case Engine::Helpers::ANSI::Bold:
            ret << L'1';

            break;
        case Engine::Helpers::ANSI::Underline:
            ret << L'4';

            break;
        case Engine::Helpers::ANSI::Blink:
            ret << L'5';

            break;
        case Engine::Helpers::ANSI::Reverse:
            ret << L'7';

            break;
        case Engine::Helpers::ANSI::BlackFG:
            ret << L"30";

            break;
        case Engine::Helpers::ANSI::WhiteFG:
            ret << L"37";

            break;
        case Engine::Helpers::ANSI::RedFG:
            ret << L"31";

            break;
        case Engine::Helpers::ANSI::GreenFG:
            ret << L"32";

            break;
        case Engine::Helpers::ANSI::BlueFG:
            ret << L"34";

            break;
        case Engine::Helpers::ANSI::CyanFG:
            ret << L"36";

            break;
        case Engine::Helpers::ANSI::YellowFG:
            ret << L"33";

            break;
        case Engine::Helpers::ANSI::MagentaFG:
            ret << L"35";

            break;
        case Engine::Helpers::ANSI::BlackBG:
            ret << L"40";

            break;
        case Engine::Helpers::ANSI::WhiteBG:
            ret << L"47";

            break;
        case Engine::Helpers::ANSI::RedBG:
            ret << L"41";

            break;
        case Engine::Helpers::ANSI::GreenBG:
            ret << L"42";

            break;
        case Engine::Helpers::ANSI::BlueBG:
            ret << L"44";

            break;
        case Engine::Helpers::ANSI::CyanBG:
            ret << L"46";

            break;
        case Engine::Helpers::ANSI::YellowBG:
            ret << L"43";

            break;
        case Engine::Helpers::ANSI::MagentaBG:
            ret << L"45";

            break;
        default:
            throw Exception{u8"Invalid ANSI escape code provided"};
        }
    }

    ret << L'm' << str;

    return ret.str( );
#else
    return wstring{utf_to_utf<wchar_t>(
        Engine::Helpers::ANSIFormat( string{utf_to_utf<char>( str )}, opts ) )};
#endif
}

wstring Engine::Helpers::ANSIFormat( const wchar_t* str, uint32_t opts )
{
    wstring tmp{str};

    return ANSIFormat( tmp, opts );
}
