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

//#include <boost/locale.hpp>

#include "win32.h"

using std::endl;
using std::string;
using std::uint32_t;
using std::uint8_t;
using std::vector;

using std::cerr;
using std::cout;
using std::stringstream;

constexpr auto logPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};

#if defined( _WIN32 )
constexpr auto logPrefixNoANSI{u8"[\u00D4\u00C7\u00F4] "};
#endif // defined( _WIN32 )

constexpr auto logDPrefix{u8"\033[1;37m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixGood{u8"\033[1;32m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixNeutral{u8"\033[1;33m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixBad{u8"\033[1;31m[\u00D4\u00C7\u00F4]\033[0m "};
constexpr auto logDPrefixNoANSI{u8"[\u00D4\u00C7\u00F4] "};

namespace
{
void ocoPrint( const char* str, const char* prefix )
{
#if defined( _WIN32 )
    if( ocoSupportsANSI( ) )
    {
#endif // defined( _WIN32 )
        cout << prefix;
#if defined( _WIN32 )
    }
    else
    {
        cout << logPrefixNoANSI;
    }
#endif // defined( _WIN32 )

    cout << str << endl;
}
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
