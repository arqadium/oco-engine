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

module oco.ocopkg.main;

version(Windows)
{

import core.sys.windows.windows;
import core.sys.windows.dll;

__gshared HINSTANCE g_hInst;

extern (Windows)
BOOL DllMain(HINSTANCE hInstance, ULONG ulReason, LPVOID pvReserved)
{
    switch (ulReason)
    {
    case DLL_PROCESS_ATTACH:
        g_hInst = hInstance;
        dll_process_attach( hInstance, true );
        break;

    case DLL_PROCESS_DETACH:
        dll_process_detach( hInstance, true );
        break;

    case DLL_THREAD_ATTACH:
        dll_thread_attach( true, true );
        break;

    case DLL_THREAD_DETACH:
        dll_thread_detach( true, true );
        break;

    default:
    }
    return true;
}
}
