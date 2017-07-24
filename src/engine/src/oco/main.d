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

module oco.main;

/++ ============================= M O D U L E ============================= ++
 +
 + TITLE:       Application Entry Point
 + DESCRIPTION: This is the main entry point for the OCo Engine. Currently all
 +              it does is safely duplicate the passed command-line arguments
 +              and pass them to the original C++ main() function, now called
 +              ocoMain(), manually cleaning up afterward. This is necessary
 +              as without D's dominance over startup, a lot of things would
 +              quickly break due to the absence of D-specific
 +              initialisations.
 +/

import core.stdc.stdlib : malloc, free;
import std.conv : to;

// This is implemented in main.cpp
extern (C) int ocoMain( int ac, char** av );

int main( string[] args )
{
    // Allocate new space for args
    char** argv = cast(char**)malloc( args.length );
    int argc = to!(int)(args.length);
    
    // Copy over every string, making allocations for it along the way
    for(ulong i; i < argc; i++)
    {
        // + 1 for the \0, just in case
        argv[i] = cast(char*)malloc( to!(int)(args[i].length) + 1 );
        
        for(ulong j; j < args[i].length; j++)
        {
            argv[i][j] = args[i][j];
        }
        
        argv[i][args[i].length] = '\0';
    }
    
    // Save return value
    int ret = ocoMain( argc, argv );
    
    version(Windows)
    {
        // Windows freaks when we free(), so let's not (we're exiting anyway)
        return ret;
    }
    else
    {
        // Clean up our holy memory
        for(ulong i; i < argc; i++)
        {
            free( argv[i] );
        }
        
        free( argv );
        
        // Return whatever ocoMain() gave us
        return ret;
    }
}
