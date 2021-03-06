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

module oco.engine.error;

/++ ============================= M O D U L E ============================= ++
 +
 + TITLE:       Error Functions
 + DESCRIPTION: This provides functions for handling errors in D, the old-
 +              fashioned way. We cannot use exceptions as they don't exist in
 +              C, our common denominator for interlingual compatibility.
 +/

static import oco.engine.helpers;

enum Error : uint
{
    Success,
    BadFileHeader,
    BadFileExt,
    BadFileStreamRead,
    BadChecksum,
    CannotCloseStream
}

enum Level : uint
{
    Info,
    Warn,
    Error
}

// NOTE: DMD doesn't think this is a constant expression, so we hack it using
// static this( )
immutable string[Error] kOCoErrorTexts;

static this( )
{
    import std.exception : assumeUnique;
    
    string[Error] tmp = [
        Error.Success:
            "(unused)",
        Error.BadFileHeader:
            "The header data of a file is invalid",
        Error.BadFileExt:
            "The file extension of a file is invalid",
        Error.BadFileStreamRead:
            "The reading of a file via stream failed",
        Error.BadChecksum:
            "A checksum is invalid",
        Error.CannotCloseStream:
            "The closing of a file stream failed"
    ];
    
    tmp.rehash; // For faster lookups
    
    kOCoErrorTexts = assumeUnique( tmp );
}

extern (C) void ocoDebugPrint( uint what, uint level )
{
    DebugPrint( cast(Error)what, cast(Level)level );
}

// This function is exposed in our D interface
void DebugPrint( Error what, Level level )
{
    debug
    {
        // NOTE: This is necessary to guard against bad values from C(++) code
        if(what > Error.max)
        {
            return;
        }
        
        string msg = kOCoErrorTexts[what] ~ ".";
        
        switch(level)
        {
        default:
            oco.engine.helpers.Log( msg );
            
            break;
        case Level.Info:
            oco.engine.helpers.Info( msg );
            
            break;
        case Level.Warn:
            oco.engine.helpers.Warn( msg );
            
            break;
        case Level.Error:
            oco.engine.helpers.Error( msg );
        }
    }
}
