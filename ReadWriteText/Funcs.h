#pragma once

#include <sstream>


class Funs
{
public:
	static double ConvertWstringToDouble(const wchar_t* val)
	{
#ifdef CPP11
		return std::stof(val);
#else
		double ret = 0.0;
		std::wstringstream(std::wstring(val)) >> ret;
		return ret;
#endif
	}

	static std::vector<double> ConvertWstringToDouble(const std::vector<wstring> & wstr)
	{
		std::vector<double> result = std::vector<double>();
		for (int i = 0; i < wstr.size(); ++i)
		{
			result.push_back(ConvertWstringToDouble(wstr.at(i).c_str()));
		}
		return result;
	}


};