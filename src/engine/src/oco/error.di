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

module oco.error;

/++ ============================= M O D U L E ============================= ++
 +
 + TITLE:       Error Functions
 + DESCRIPTION: This provides functions for handling errors in D, the old-
 +              fashioned way. We cannot use exceptions as they don't exist in
 +              C, our common denominator for interlingual compatibility.
 +/

enum Error : uint
{
    Success,
    BadFileHeader,
    BadFileExt,
    BadFileStreamRead,
    BadChecksum,
    CannotCloseStream
}

enum Level
{
    Info,
    Warn,
    Error
}

void DebugPrint( Error what, Level level );
