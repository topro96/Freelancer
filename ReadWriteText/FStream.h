#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class FStream
{
private:

public:
	static std::vector<wstring> ReadLineTextByFilePath(const std::wstring &path);
	static std::vector<wstring> ReadLineTextByDirection(const std::wstring &direction);

public:
	static std::vector<wstring> GetTextFilesInDirectory(const wstring & dir);
	static std::vector<wstring> ParseString(const wstring & str);
public:
	FStream();
	~FStream();

};

