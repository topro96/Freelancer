#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Format2
{

private:
	std::vector<std::vector<double>> datas = std::vector<std::vector<double>>();

public:

	Format2();
	~Format2();

public:
	void ParserData(std::vector<std::wstring> & lines);

	void Output();

};

