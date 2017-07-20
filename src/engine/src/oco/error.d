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

static import oco.helpers;

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

extern (C) void ocoDebugPrint( Error what, Level level )
{
    debug
    {
        if(what > Error.max)
        {
            return;
        }
        
        string msg = kOCoErrorTexts[what] ~ ".";
        
        switch(level)
        {
        default:
            oco.helpers.Log( msg );
            
            break;
        case Level.Info:
            oco.helpers.Info( msg );
            
            break;
        case Level.Warn:
            oco.helpers.Warn( msg );
            
            break;
        case Level.Error:
            oco.helpers.Error( msg );
        }
    }
}

void DebugPrint( Error what, Level level )
{
    ocoDebugPrint( what, level );
}
