#include "FStream.h"
#include <list>
#include <sstream>
#include <filesystem>

namespace fs = std::experimental::filesystem;

#define ExtendTextFile L".txt"


std::vector<wstring> FStream::ReadLineTextByFilePath(const std::wstring & path)
{
	std::vector<wstring> values = std::vector<wstring>();
	wifstream input;
	input.open(path, ios::in);

	wstring content;
	while (!input.eof())
	{
		std::getline(input, content);
		values.push_back(content);
	}
	input.close();

	return values;
}

std::vector<wstring> FStream::ReadLineTextByDirection(const std::wstring & direction)
{

	std::vector<wstring> result = std::vector<wstring>();
	{
		std::vector<wstring> file_paths = GetTextFilesInDirectory(direction);

		for (int i = 0; i < file_paths.size(); ++i)
		{
			std::vector<wstring> lines = ReadLineTextByFilePath(file_paths.at(i));
			result.insert(result.begin(), lines.begin(), lines.end());
		}
	}

	return result;
}



static bool IsTextFile(const wstring &path)
{
	wstring extend = path.substr(path.length() - 4, 4);
	if (0 == extend.compare(ExtendTextFile))
		return true;

	return false;
}

std::vector<wstring> FStream::GetTextFilesInDirectory(const wstring & dir)
{
	std::vector<wstring> result = std::vector<wstring>();

	for (const auto & entry : fs::directory_iterator(dir))
		result.push_back(wstring(entry.path().c_str()));

	for (int i = 0; i < result.size(); ++i)
	{
		if (!IsTextFile(result.at(i)))
		{
			result.erase(result.begin() + i);
		}
	}

	return result;
}

std::vector<wstring> FStream::ParseString(const wstring & str)
{
	std::vector<wstring> result;
	for (int i = 0; i < str.length(); ++i)
	{
		wstring newStr = L"";
		while (((int)str[i] >= 48 && (int)str[i] <= 57 || str[i] == '.'))
		{
			newStr.push_back(str[i]);
			i++;
		}
		if (L"" != newStr)
		{
			result.push_back(newStr);
		}
	}
	return result;
}

FStream::FStream()
{
}


FStream::~FStream()
{
}






