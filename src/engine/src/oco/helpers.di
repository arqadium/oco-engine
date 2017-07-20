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
 +              error-level diagnostic messages. Under the hood it interfaces
 +              with C++ code that formats the message to be identifiable as
 +              coming from OCo, and includes colouring for the different
 +              diagnostic levels if supported.
 +/

uint singleBit( ubyte which )
{
    if( which > 31 )
    {
        return 0;
    }

    return 1 << which;
}

bool Log( string str );
bool Info( string str );
bool Warn( string str );
bool Error( string str );
