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

module oco.untar.untar;

import std.algorithm.mutation : remove;

static ulong asciiToNumber( ubyte ch )
{
    return ch - 48;
}

ulong decodeOctal( ubyte[] data )
{
    ulong ret;
    ulong curMul = 1;
    
    // Remove all trailing whitespace and NUL chars
    for(ulong i = data.length - 1; i >= 0; i--)
    {
        // Make sure it is not a NUL or space
        if(data[i] == 0x00 || data[i] == 0x20)
        {
            remove( data, i );
        }
        else
        {
            break;
        }
    }
    
    foreach_reverse(b; data)
    {
        ret    += asciiToNumber( b ) * curMul;
        curMul *= 8;
    }
    
    return ret;
}

class Tarball
{
    protected ubyte[100] m_fileName; // NUL-terminated
    protected ubyte[8]   m_mode;
    protected ubyte[8]   m_uid;
    protected ubyte[8]   m_gid;
    protected ubyte[12]  m_fileSize;
    protected ubyte[12]  m_lastModification;
    protected ubyte[8]   m_checksum;
    protected ubyte      m_typeFlag;
    
    // USTAR-specific fields; NUL-filled in non-USTAR versions
    protected ubyte[100] m_linkedFileName;
    // "ustar" - 6th char may be NUL (not required)
    protected ubyte[6]   m_ustarIndicator;
    protected ubyte[2]   m_ustarVersion; // "00"
    protected ubyte[32]  m_ownerUserName;
    protected ubyte[32]  m_ownerGroupName;
    protected ubyte[8]   m_devMajorNum;
    protected ubyte[8]   m_devMinorNum;
    protected ubyte[155] m_fileNamePrefix;
    protected ubyte[12]  m_padding; // Unused, but relevant for checksum
    
    /** ========================= F U N C T I O N ========================= **
     *
     * TITLE:       Check Tarball Version
     * DESCRIPTION: Reads the magic bytes for USTAR compatibility.
     *
     * RETURNS: true if and only if
     */
    
    public bool isUstar( )
    {
        return this.m_ustarIndicator == "ustar";
    }
    
    public @property ulong fileSize( )
    {
        return decodeOctal( this.m_fileSize );
    }
    
    public bool checksum( )
    {
        // TODO: Implement later...
    }
}
