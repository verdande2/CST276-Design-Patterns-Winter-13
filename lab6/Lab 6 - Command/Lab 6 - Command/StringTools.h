#pragma once
#include <sstream>
using std::stringstream;

namespace StringTools
{
	// from http://www.cplusplus.com/forum/articles/9645/#msg44710
	template <typename T>
	string NumberToString ( T Number )
	{
		stringstream ss;
		ss << Number;
		return ss.str();
	}

	// from http://www.cplusplus.com/forum/articles/9645/#msg44710
	template <typename T>
	T StringToNumber ( string Text )
	{
		stringstream ss(Text);
		T result;
		return (ss >> result) ? result : 0;
	}
};