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

module oco.helpers;

/++ ============================= M O D U L E ============================= ++
 +
 + TITLE:       Helper Functions
 + DESCRIPTION: This provides functions for printing messages to standard
 +              output, including specific functions for info-, warning-, and
 +              error-level diagnostic messages.
 +/

// For making C-compatible strings
import std.string : toStringz;

// These are implemented in helpers.cpp
extern (C) bool ocoLog_D( const char* str );
extern (C) bool ocoInfo_D( const char* str );
extern (C) bool ocoWarn_D( const char* str );
extern (C) bool ocoError_D( const char* str );

bool Log( string str )
{
    return ocoLog_D( toStringz( str ) );
}

bool Info( string str )
{
    return ocoInfo_D( toStringz( str ) );
}

bool Warn( string str )
{
    return ocoWarn_D( toStringz( str ) );
}

bool Error( string str )
{
    return ocoError_D( toStringz( str ) );
}
