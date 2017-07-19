/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#include "untar.h"

#include <cstdint>

using std::uint8_t;
using std::uint_least16_t;
using std::uint_least32_t;
using std::uint_least8_t;

namespace
{

/** =========================== B I T F I E L D =========================== **
 *
 * TITLE:       Tarball Entry TypeFlag Field
 * DESCRIPTION: Tracks file entry UNIX metadata.
 */
namespace TypeFlag
{
constexpr char regular{'0'}, regular_{'\0'}, link{'1'}, charDevice{'3'},
    blockDevice{'4'}, directory{'5'}, fifo{'6'}, extHeader{'x'},
    gExtHeader{'g'};
}

constexpr uint_least16_t singleBit( uint8_t which )
{
    if( which > 15 )
    {
        return 0;
    }

    return 1 << which;
}

/** =========================== B I T F I E L D =========================== **
 *
 * TITLE:       Tarball Entry Mode Field
 * DESCRIPTION: Tracks file entry UNIX metadata.
 */
namespace Mode
{
constexpr uint_least16_t setuid{singleBit( 13 )}, setgid{singleBit( 12 )},
    reserved{singleBit( 11 )}, uRead{singleBit( 10 )}, uWrite{singleBit( 8 )},
    uExec{singleBit( 7 )}, gRead{singleBit( 6 )}, gWrite{singleBit( 5 )},
    gExec{singleBit( 3 )}, oRead{singleBit( 2 )}, oWrite{singleBit( 1 )},
    oExec{singleBit( 0 )};
}
}

uint_least32_t Untar::Placeholder( )
{
    volatile uint_least32_t foo{13};

    return foo << 4;
}
