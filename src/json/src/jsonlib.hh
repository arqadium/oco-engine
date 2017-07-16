/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#ifndef INC__MOCHI_JSON_JSONLIB_HH
#define INC__MOCHI_JSON_JSONLIB_HH ( 1 )

#include <cstdint>

namespace JSON
{

namespace _internal
{

#include "json.hh"
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
using _internal::Json::StaticString;
using _internal::Json::Path;
using _internal::Json::PathArgument;
using _internal::Json::Value;
using _internal::Json::ValueIteratorBase;
using _internal::Json::ValueIterator;
using _internal::Json::ValueConstIterator;
}

#endif // INC__MOCHI_JSON_JSONLIB_HH
