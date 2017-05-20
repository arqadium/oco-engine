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
#include <map>
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
		std::map<std::string, std::uint32_t> fileNames;

		bool ChecksumsInvalid( );
		void IndexFiles( );
	};
}



#endif // INC__MOCHI_ENGINE_PACKAGE_HH
