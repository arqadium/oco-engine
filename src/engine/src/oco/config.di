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

module oco.config;

immutable ubyte[16] kPkgMagicBytes = [
    0x89,                               // high bit set
    0x4F, 0x41, 0x4D, 0x50, 0x4B, 0x47, // "OAMPKG"
    0x0D, 0x0A,                         // "\r\n"
    0x1A,                               // DOS EOF character
    0x0A,                               // "\n"
    0x00,                               // NULL terminator
    0, 0, 0, 0                          // padding to make header length 16
];

immutable string kPkgFileExt = ".oampkg.tar.lz4";

immutable string kBadFileHeader = "File header bytes are invalid";
immutable string kBadFileExt = "File extension is invalid";
immutable string kBadFileStreamRead = "Failed to open file (read)";
immutable string kBadChecksum = "Checksumming failed";
immutable string kCannotCloseStream = "Cannot close file stream";
