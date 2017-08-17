#!/usr/bin/dmd
/++ -*- coding: utf-8; mode: D; indent-tabs-mode: nil; indent-width: 4; -*- ++/
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

module oco.ocopkg.unpack;

import std.stdio : File;

struct Header
{
    ushort ver;
    ushort fileCount;
    uint   crcTableCrc;
    uint   sectCount;
    uint[] crcTable;
}

struct EntryUnc
{
    uint   size;
    ulong  startSect;
    ushort type;
    string name;
}

enum LZ4BlockSize
{
    _16KiB = 0,
    _64KiB,
    _256KiB,
    _1MiB,
    _4MiB
}

struct EntryLZ4
{
    uint   size;
    ulong  startSect;
    ushort type;
    string name;
}

Header getHeader( File ocoPkg )
{
    
}
