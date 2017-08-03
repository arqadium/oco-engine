/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#if !defined( INC__OCO_JSON_JSONLIB_H )
#define INC__OCO_JSON_JSONLIB_H ( 1 )

#if !defined( __cplusplus )
#error "libJSON does not yet have a C interface."
#elif __cplusplus <= 199711L && !defined( _MSC_VER )
#error "The OCo Engine needs at least a C++11 compliant compiler"
#endif // !defined( __cplusplus )

///
/// C++11 INTERFACE
///

#include <cstdint>

namespace OCo
{
namespace JSON
{

namespace _internal
{

// Minimise namespace pollution
#include "json.h"
}

namespace Version
{

constexpr auto kString   = JSONCPP_VERSION_STRING;
constexpr uint8_t kMajor = JSONCPP_VERSION_MAJOR;
constexpr uint8_t kMinor = JSONCPP_VERSION_MINOR;
constexpr uint8_t kPatch = JSONCPP_VERSION_PATCH;
constexpr uint32_t kHexa =
    ( kMajor << 24 ) | ( kMinor << 16 ) | ( kPatch << 8 );
}

constexpr bool kExceptions = JSON_USE_EXCEPTION;

// writer.h
using _internal::Json::FastWriter;
using _internal::Json::StyledWriter;

// reader.h
using _internal::Json::Reader;

// features.h
using _internal::Json::Features;

// value.h
typedef unsigned int ArrayIndex;
using _internal::Json::Path;
using _internal::Json::PathArgument;
using _internal::Json::StaticString;
using _internal::Json::Value;
using _internal::Json::ValueConstIterator;
using _internal::Json::ValueIterator;
using _internal::Json::ValueIteratorBase;
} // namespace JSON
} // namespace OCo

#endif // !defined( INC__OCO_JSON_JSONLIB_H )
