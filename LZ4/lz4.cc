/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
*                        PROJECT MOCHI - C++ ENGINE                         *
*                                                                           *
*         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "lz4.hh"

#include <cstdint>
#include <vector>

#include "lz4.h"



using std::uint8_t;
using std::uintmax_t;
using std::vector;

bool LZ4::Compress( vector<uint8_t> source, vector<uint8_t> dest )
{
	const uintmax_t sourceSize = source.size( );
	const uintmax_t destSize = LZ4_compressBound(
		static_cast<int>(sourceSize) );
	
	if(dest.size( ) < destSize)
	{
		dest.resize( destSize );
	}
	
	return !LZ4_compress_default( reinterpret_cast<char*>(source.data( )),
		reinterpret_cast<char*>(dest.data( )),
		static_cast<int>(source.size( )), static_cast<int>(destSize) );
}



bool LZ4::Decompress( vector<uint8_t> source, vector<uint8_t> dest )
{
	return LZ4_decompress_safe( reinterpret_cast<char*>(source.data( )),
		reinterpret_cast<char*>(dest.data( )),
		static_cast<int>(source.size( )), static_cast<int>(dest.size( )) )
		< 0;
}



bool LZ4::Decompress( vector<uint8_t> source, vector<uint8_t> dest,
	uintmax_t originalSize )
{
	if(dest.size( ) < originalSize)
	{
		return true;
	}

	return LZ4_decompress_fast( reinterpret_cast<char*>(source.data( )),
		reinterpret_cast<char*>(dest.data( )),
		static_cast<int>(originalSize) ) < 0;
}
