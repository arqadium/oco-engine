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

module oco.engine.ipsum;

/++ ============================= M O D U L E ============================= ++
 +
 + TITLE:       Lorem Ipsum Logging Test
 + DESCRIPTION: This exposes a C-linkable function that tests the D-exposed
 +              C++ logging functions by sending the de facto Lorem Ipsum
 +              text to it, stored in a D string array.
 +
 + FOOTNOTE: For some reason statically declaring + assigning kLoremIpsum
 +           causes segmentation faults; we work around this by actually
 +           assigning to it at program startup using D's "static this" code.
 +/

debug
{
static import oco.engine.helpers;
import std.conv : to;

string[] kLoremIpsum;

static this( )
{
    string[] tmp = [
        "Lorem ipsum dolor sit amet,",
        "consectetur adipiscing elit,",
        "sed do eiusmod tempor incididunt ut labore",
        "et dolore magna aliqua. Ut enim ad minim veniam,",
        "quis nostrud exercitation ullamco laboris",
        "nisi ut aliquip ex ea commodo consequat.",
        "Duis aute irure dolor in reprehenderit in",
        "voluptate velit esse cillum dolore",
        "eu fugiat nulla pariatur.",
        "Excepteur sint occaecat cupidatat non proident,",
        "sunt in culpa qui officia deserunt",
        "mollit anim id est laborum."
    ];
    
    kLoremIpsum.length = tmp.length;
    kLoremIpsum[] = tmp; // Copy by value, not reference
}

extern (C) void ocoIpsum( )
{
    foreach(line; kLoremIpsum)
    {
        oco.engine.helpers.Log( line );
    }
    
    foreach(line; kLoremIpsum)
    {
        oco.engine.helpers.Info( line );
    }
    
    foreach(line; kLoremIpsum)
    {
        oco.engine.helpers.Warn( line );
    }
    
    foreach(line; kLoremIpsum)
    {
        oco.engine.helpers.Error( line );
    }
}
}
