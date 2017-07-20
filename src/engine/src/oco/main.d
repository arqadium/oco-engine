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

import core.stdc.stdlib : malloc, free;
import std.conv : to;

extern (C) int ocoMain( int ac, char** av );

int main( string[] args )
{
    char** argv = cast(char**)malloc( args.length );
    int argc = to!(int)(args.length);
    
    for(ulong i; i < argc; i++)
    {
        argv[i] = cast(char*)malloc( to!(int)(args[i].length) + 1 );
        
        for(ulong j; j < args[i].length; j++)
        {
            argv[i][j] = args[i][j];
        }
        
        argv[i][args[i].length] = '\0';
    }
    
    int ret = ocoMain( argc, argv );
    
    for(ulong i; i < argc; i++)
    {
        free( argv[i] );
    }
    
    free( argv );
    
    return ret;
}
