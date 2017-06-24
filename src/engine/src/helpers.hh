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
#include <string>
#include <vector>



namespace Engine
{
namespace Helpers
{

namespace ANSI
{

enum Codes : std::uint32_t
{
	None = 0x0,
	Bold = 0x1,
	Underline = 0x2,
	Blink = 0x4,
	Reverse = 0x8,
	Invisible = 0x10,
	BlackFG = 0x20,
	WhiteFG = 0x40,
	RedFG = 0x80,
	GreenFG = 0x100,
	BlueFG = 0x200,
	CyanFG = 0x400,
	YellowFG = 0x800,
	MagentaFG = 0x1000,
	BlackBG = 0x2000,
	WhiteBG = 0x4000,
	RedBG = 0x8000,
	GreenBG = 0x10000,
	BlueBG = 0x20000,
	CyanBG = 0x40000,
	YellowBG = 0x80000,
	MagentaBG = 0x100000,
};

}

constexpr std::uint32_t singleBit( std::uint8_t which )
{
	if(which > 31)
	{
		return 0;
	}

	return 1 << which;
}

void Log( std::string str, bool newline = true );
void Log( const char* str, bool newline = true );
void Log( std::wstring str, bool newline = true );
void Log( const wchar_t* str, bool newline = true );
void Log( std::vector<std::string> str, bool newline = true );
void Log( std::vector<std::wstring> str, bool newline = true );

void Info( std::string str, bool newline = true );
void Info( const char* str, bool newline = true );
void Info( std::wstring str, bool newline = true );
void Info( const wchar_t* str, bool newline = true );
void Info( std::vector<std::string> str, bool newline = true );
void Info( std::vector<std::wstring> str, bool newline = true );

void Warn( std::string str, bool newline = true );
void Warn( const char* str, bool newline = true );
void Warn( std::wstring str, bool newline = true );
void Warn( const wchar_t* str, bool newline = true );
void Warn( std::vector<std::string> str, bool newline = true );
void Warn( std::vector<std::wstring> str, bool newline = true );

void Error( std::string str, bool newline = true );
void Error( const char* str, bool newline = true );
void Error( std::wstring str, bool newline = true );
void Error( const wchar_t* str, bool newline = true );
void Error( std::vector<std::string> str, bool newline = true );
void Error( std::vector<std::wstring> str, bool newline = true );

std::string ANSIFormat( std::string str, std::uint32_t opts );
std::string ANSIFormat( const char* str, std::uint32_t opts );
std::wstring ANSIFormat( std::wstring str, std::uint32_t opts );
std::wstring ANSIFormat( const wchar_t* str, std::uint32_t opts );

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
