/// -*- coding: utf-8; mode: C++; indent-tabs-mode: nil; c-basic-offset: 4 -*-
/*****************************************************************************\
 *                        PROJECT MOCHI - C++ ENGINE                         *
 *                                                                           *
 *         COPYRIGHT (C) 2017 TRINITY SOFTWARE. ALL RIGHTS RESERVED          *
\*****************************************************************************/

#ifndef INC__MOCHI_ENGINE_CONSOLE_HH
#define INC__MOCHI_ENGINE_CONSOLE_HH (1)

#include <string>



namespace Engine
{

class Console
{
public:
	template<typename T>
	static void Log( T in )
	{
		if(!initted) { return; }

	}

private:
	static bool initted;
};

}



#endif // INC__MOCHI_ENGINE_CONSOLE_HH
