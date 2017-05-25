/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_HELPERS_HH
#define INC__MOCHI_ENGINE_HELPERS_HH (1)

#include <array>
#include <cstdint>



namespace Engine
{
namespace Helpers
{

inline std::uint16_t charArrToU16( std::array<char, 2> bytes )
{
	uint16_t ret{ 0 };

	ret |= static_cast<uint16_t>(bytes[0]) << 8;
	ret |= static_cast<uint16_t>(bytes[1]);

	return ret;
}

inline std::uint32_t charArrToU32( std::array<char, 4> bytes )
{
	std::uint32_t ret{ 0 };

	ret |= static_cast<std::uint32_t>(bytes[0]) << 24;
	ret |= static_cast<std::uint32_t>(bytes[1]) << 16;
	ret |= static_cast<std::uint32_t>(bytes[2]) << 8;
	ret |= static_cast<std::uint32_t>(bytes[3]);

	return ret;
}

inline std::uint64_t charArrToU64( std::array<char, 8> bytes )
{
	std::uint64_t ret{ 0 };

	ret |= static_cast<std::uint64_t>(bytes[0]) << 56;
	ret |= static_cast<std::uint64_t>(bytes[1]) << 48;
	ret |= static_cast<std::uint64_t>(bytes[2]) << 40;
	ret |= static_cast<std::uint64_t>(bytes[3]) << 32;
	ret |= static_cast<std::uint64_t>(bytes[4]) << 24;
	ret |= static_cast<std::uint64_t>(bytes[5]) << 16;
	ret |= static_cast<std::uint64_t>(bytes[6]) << 8;
	ret |= static_cast<std::uint64_t>(bytes[7]);

	return ret;
}

}
}



#endif // INC__MOCHI_ENGINE_HELPERS_HH
