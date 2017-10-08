#pragma once

#include <iostream>
#include <sstream>

#ifdef _UNICODE
#ifndef xstring
#define xstring std::wstring
#endif // !xstring

#ifndef xstringstream
#define xstringstream std::wstringstream
#endif

#else
#ifndef xstring
#define xstring std::string
#endif

#ifndef xstringstream
#define xstringstream std::stringstream
#endif

#endif

static xstring int2wxstr(int i)
{
	std::wstringstream ss;
	ss << i;
	return ss.str();
}