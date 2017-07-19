/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - OCO ENGINE                         *
 *             Copyright (C) 2017 Arqadium. All rights reserved.             *
 *                                                                           *
 *    This Source Code Form is subject to the terms of the Mozilla Public    *
 * License, version 2.0.  If a copy of the MPL was not distributed with this *
 *      file, then you can obtain one at <http://mozilla.org/MPL/2.0/>.      *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_PACKAGE_HH
#define INC__MOCHI_ENGINE_PACKAGE_HH ( 1 )

#ifdef __cplusplus

#include <cstdint>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>

namespace Engine
{

class Package
{
  public:
    Package( boost::filesystem::path filePath, bool check = false );
    ~Package( );
    std::vector<std::uint8_t> ReadFile( std::string name );
    std::uint8_t ReadPFlags( std::string name );

  private:
    boost::filesystem::path filePath;
    boost::filesystem::ifstream stream;
    bool checked;
    std::map<std::string, std::uint32_t> fileChecksums;

    bool ChecksumsInvalid( );
    void IndexFiles( );
    void EnsureOpenStream( );
    void EnsureClosedStream( );
};
}

#endif // __cplusplus

#endif // INC__MOCHI_ENGINE_PACKAGE_HH
