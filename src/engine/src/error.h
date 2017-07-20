/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_ENGINE_ERROR_H )
#define INC__OCO_ENGINE_ERROR_H ( 1 )

#if !defined( __cplusplus )

///
/// C INTERFACE
///

#include <stdint.h>

enum : uint32_t
{
    OCoError_Success = 0,
    OCoError_BadFileHeader,
    OCoError_BadFileExt,
    OCoError_BadFileStreamRead,
    OCoError_BadChecksum,
    OCoError_CannotCloseStream
};

enum : uint32_t
{
    OCoDiagMsgLevel_Info = 0,
    OCoDiagMsgLevel_Warn,
    OCoDiagMsgLevel_Error
};

void ocoDebugPrint( uint32_t what, uint32_t level );

#elif __cplusplus <= 199711L
#error "The OCo Engine needs at least a C++11 compliant compiler"
#else // defined( __cplusplus ) && __cplusplus > 199711L

///
/// C++11 INTERFACE
///

#include <cstdint>

extern "C" void ocoDebugPrint( std::uint32_t what, std::uint32_t level );

namespace OCo
{
namespace Error
{

enum : std::uint32_t
{
    Success = 0,
    BadFileHeader,
    BadFileExt,
    BadFileStreamRead,
    BadChecksum,
    CannotCloseStream
};
} // namespace Error

namespace DiagMsgLevel
{

enum : std::uint32_t
{
    Info = 0,
    Warn,
    Error
};
} // namespace DiagMsgLevel
} // namespace OCo

#endif // !defined( __cplusplus )
#endif // defined( INC__OCO_ENGINE_ERROR_H )
