/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#include "helpers.hh"

#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/locale.hpp>

#include "except.hh"



using boost::locale::conv::utf_to_utf;
using Engine::Exception;
using Engine::Helpers::singleBit;
using std::endl;
using std::string;
using std::stringstream;
using std::uint32_t;
using std::uint8_t;
using std::vector;
using std::wcerr;
using std::wcout;
using std::wstring;
using std::wstringstream;

constexpr auto logPrefix{ u8"\033[1;37m[ÔÇô]\033[0m " };
constexpr auto logPrefix_L{ L"\033[1;37m[ÔÇô]\033[0m " };

constexpr auto logPrefixGood{ u8"\033[1;32m[ÔÇô]\033[0m " };
constexpr auto logPrefixGood_L{ L"\033[1;32m[ÔÇô]\033[0m " };
constexpr auto logPrefixNeutral{ u8"\033[1;33m[ÔÇô]\033[0m " };
constexpr auto logPrefixNeutral_L{ L"\033[1;33m[ÔÇô]\033[0m " };
constexpr auto logPrefixBad{ u8"\033[1;31m[ÔÇô]\033[0m " };
constexpr auto logPrefixBad_L{ L"\033[1;31m[ÔÇô]\033[0m " };

void Engine::Helpers::Log( string str, bool newline )
{
	wcout << logPrefix_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Log( const char* str, bool newline )
{
	wcout << logPrefix_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Log( wstring str, bool newline )
{
	wcout << logPrefix_L << str;

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Log( const wchar_t* str, bool newline )
{
	wcout << logPrefix_L << str;

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Log( vector<string> str, bool newline )
{
	for(auto& line : str)
	{
		wcout << logPrefix_L << utf_to_utf<wchar_t>( line );

		if(newline) { wcout << endl; }
	}
}

void Engine::Helpers::Log( vector<wstring> str, bool newline )
{
	for(auto& line : str)
	{
		wcout << logPrefix_L << line;

		if(newline) { wcout << endl; }
	}
}

void Engine::Helpers::Info( string str, bool newline )
{
	wcout << logPrefixGood_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Info( const char* str, bool newline )
{
	wcout << logPrefixGood_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Info( wstring str, bool newline )
{
	wcout << logPrefixGood_L << str;

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Info( const wchar_t* str, bool newline )
{
	wcout << logPrefixGood_L << str;

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Info( vector<string> str, bool newline )
{
	for(auto& line : str)
	{
		wcout << logPrefixGood_L << utf_to_utf<wchar_t>( line );

		if(newline) { wcout << endl; }
	}
}

void Engine::Helpers::Info( vector<wstring> str, bool newline )
{
	for(auto& line : str)
	{
		wcout << logPrefixGood_L << line;

		if(newline) { ::wcout << endl; }
	}
}

void Engine::Helpers::Warn( string str, bool newline )
{
	wcout << logPrefixNeutral_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Warn( const char* str, bool newline )
{
	wcout << logPrefixNeutral_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Warn( wstring str, bool newline )
{
	wcout << logPrefixNeutral_L << str;

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Warn( const wchar_t* str, bool newline )
{
	wcout << logPrefixNeutral_L << str;

	if(newline) { wcout << endl; }
}

void Engine::Helpers::Warn( vector<string> str, bool newline )
{
	for(auto& line : str)
	{
		wcout << logPrefixNeutral_L << utf_to_utf<wchar_t>( line );

		if(newline) { wcout << endl; }
	}
}

void Engine::Helpers::Warn( vector<wstring> str, bool newline )
{
	for(auto& line : str)
	{
		wcout << logPrefixNeutral_L << line;

		if(newline) { wcout << endl; }
	}
}

void Engine::Helpers::Error( string str, bool newline )
{
	wcerr << logPrefixBad_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcerr << endl; }
}

void Engine::Helpers::Error( const char* str, bool newline )
{
	wcerr << logPrefixBad_L << utf_to_utf<wchar_t>( str );

	if(newline) { wcerr << endl; }
}

void Engine::Helpers::Error( wstring str, bool newline )
{
	wcerr << logPrefixBad_L << str;

	if(newline) { wcerr << endl; }
}

void Engine::Helpers::Error( const wchar_t* str, bool newline )
{
	wcerr << logPrefixBad_L << str;

	if(newline) { wcerr << endl; }
}

void Engine::Helpers::Error( vector<string> str, bool newline )
{
	for(auto& line : str)
	{
		wcerr << logPrefixBad_L << utf_to_utf<wchar_t>( line );

		if(newline) { wcerr << endl; }
	}
}

void Engine::Helpers::Error( vector<wstring> str, bool newline )
{
	for(auto& line : str)
	{
		wcerr << logPrefixBad_L << line;

		if(newline) { wcerr << endl; }
	}
}

string Engine::Helpers::ansiFormat( string str, uint32_t opts )
{
	stringstream ret{ };

	if(opts == 0)
	{
		ret << L"\033[0m" << str;

		return ret.str( );
	}

	ret << "\033[";

	for(uint8_t i = 0; i < 32; ++i)
	{
		if(i > 0) { ret << ';'; }

		switch(opts & singleBit( i ))
		{
		case Engine::Helpers::ANSI::None:
			break;
		case Engine::Helpers::ANSI::Bold:
			ret << '1';

			break;
		case Engine::Helpers::ANSI::Underline:
			ret << '4';

			break;
		case Engine::Helpers::ANSI::Blink:
			ret << '5';

			break;
		case Engine::Helpers::ANSI::Reverse:
			ret << '7';

			break;
		case Engine::Helpers::ANSI::BlackFG:
			ret << "30";

			break;
		case Engine::Helpers::ANSI::WhiteFG:
			ret << "37";

			break;
		case Engine::Helpers::ANSI::RedFG:
			ret << "31";

			break;
		case Engine::Helpers::ANSI::GreenFG:
			ret << "32";

			break;
		case Engine::Helpers::ANSI::BlueFG:
			ret << "34";

			break;
		case Engine::Helpers::ANSI::CyanFG:
			ret << "36";

			break;
		case Engine::Helpers::ANSI::YellowFG:
			ret << "33";

			break;
		case Engine::Helpers::ANSI::MagentaFG:
			ret << "35";

			break;
		case Engine::Helpers::ANSI::BlackBG:
			ret << "40";

			break;
		case Engine::Helpers::ANSI::WhiteBG:
			ret << "47";

			break;
		case Engine::Helpers::ANSI::RedBG:
			ret << "41";

			break;
		case Engine::Helpers::ANSI::GreenBG:
			ret << "42";

			break;
		case Engine::Helpers::ANSI::BlueBG:
			ret << "44";

			break;
		case Engine::Helpers::ANSI::CyanBG:
			ret << "46";

			break;
		case Engine::Helpers::ANSI::YellowBG:
			ret << "43";

			break;
		case Engine::Helpers::ANSI::MagentaBG:
			ret << "45";

			break;
		default:
			throw Exception{ "Invalid ANSI escape code provided" };
		}
	}

	ret << 'm' << str;

	return ret.str( );
}

string Engine::Helpers::ansiFormat( const char* str, uint32_t opts )
{
	string tmp{ str };

	return ansiFormat( tmp, opts );
}

wstring Engine::Helpers::ansiFormat( wstring str, uint32_t opts )
{
	wstringstream ret{ };

	if(opts == 0)
	{
		ret << L"\033[0m" << str;

		return ret.str( );
	}

	ret << L"\033[";

	for(uint8_t i = 0; i < 32; ++i)
	{
		if(i == 0) { continue; }

		ret << L';';

		switch(opts & singleBit( i ))
		{
		case Engine::Helpers::ANSI::None:
			break;
		case Engine::Helpers::ANSI::Bold:
			ret << L'1';

			break;
		case Engine::Helpers::ANSI::Underline:
			ret << L'4';

			break;
		case Engine::Helpers::ANSI::Blink:
			ret << L'5';

			break;
		case Engine::Helpers::ANSI::Reverse:
			ret << L'7';

			break;
		case Engine::Helpers::ANSI::BlackFG:
			ret << L"30";

			break;
		case Engine::Helpers::ANSI::WhiteFG:
			ret << L"37";

			break;
		case Engine::Helpers::ANSI::RedFG:
			ret << L"31";

			break;
		case Engine::Helpers::ANSI::GreenFG:
			ret << L"32";

			break;
		case Engine::Helpers::ANSI::BlueFG:
			ret << L"34";

			break;
		case Engine::Helpers::ANSI::CyanFG:
			ret << L"36";

			break;
		case Engine::Helpers::ANSI::YellowFG:
			ret << L"33";

			break;
		case Engine::Helpers::ANSI::MagentaFG:
			ret << L"35";

			break;
		case Engine::Helpers::ANSI::BlackBG:
			ret << L"40";

			break;
		case Engine::Helpers::ANSI::WhiteBG:
			ret << L"47";

			break;
		case Engine::Helpers::ANSI::RedBG:
			ret << L"41";

			break;
		case Engine::Helpers::ANSI::GreenBG:
			ret << L"42";

			break;
		case Engine::Helpers::ANSI::BlueBG:
			ret << L"44";

			break;
		case Engine::Helpers::ANSI::CyanBG:
			ret << L"46";

			break;
		case Engine::Helpers::ANSI::YellowBG:
			ret << L"43";

			break;
		case Engine::Helpers::ANSI::MagentaBG:
			ret << L"45";

			break;
		default:
			throw Exception{ "Invalid ANSI escape code provided" };
		}
	}

	ret << L'm' << str;

	return ret.str( );
}

wstring Engine::Helpers::ansiFormat( const wchar_t* str, uint32_t opts )
{
	wstring tmp{ str };

	return ansiFormat( tmp, opts );
}
