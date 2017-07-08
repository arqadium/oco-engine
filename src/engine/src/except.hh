/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_EXCEPT_HH
#define INC__MOCHI_ENGINE_EXCEPT_HH ( 1 )

#include <cstdint>
#include <stdexcept>
#include <string>

namespace Engine
{

struct Exception
{
    Exception( const char* _msg, std::int32_t _code, bool _fatal = false )
        : msg( _msg ), code( _code ), fatal( _fatal )
    {
    }
    Exception( const char* _msg, bool _fatal = false )
        : msg( _msg ), code( 0 ), fatal( _fatal )
    {
    }
    Exception( const std::string _msg, std::int32_t _code, bool _fatal = false )
        : msg( _msg ), code( _code ), fatal( _fatal )
    {
    }
    Exception( const std::string _msg, bool _fatal = false )
        : msg( _msg ), code( 0 ), fatal( _fatal )
    {
    }
    ~Exception( ) {}

    const std::string msg;
    const std::int32_t code;
    const bool fatal;
};
}

#endif // INC__MOCHI_ENGINE_EXCEPT_HH
