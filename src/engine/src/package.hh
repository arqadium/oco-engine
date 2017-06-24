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



#endif // INC__MOCHI_ENGINE_PACKAGE_HH
