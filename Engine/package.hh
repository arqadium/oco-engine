/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_PACKAGE_HH
#define INC__MOCHI_ENGINE_PACKAGE_HH (1)

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>



namespace Engine
{
	class Package
	{
	public:
		Package( std::string filePath, bool check = false );
		~Package( );

		std::vector<std::uint8_t> ReadFile( std::string name );
		std::uint8_t ReadPFlags( std::string name );

	private:
		std::ifstream stream;
		bool checked;

		bool Check( );
	};
}



#endif // INC__MOCHI_ENGINE_PACKAGE_HH
