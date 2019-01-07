#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Format1
{
public:

	float x;
	float y;
	float s;
	static int const UNIT = 3;
public:
	Format1();
	Format1(float _x, float _y, float _s);
	Format1(const Format1 & other);

public:
	static Format1 GetData(const std::vector<wstring> & values); //covert string to float
	


};


class Form1Controler
{
private:
	std::vector<Format1> datas = std::vector<Format1>();

public:
	Form1Controler();
	Form1Controler(const Form1Controler & other);

public:
	void ParseData(const std::vector<wstring> & lines);

	void Output2DPosition(const wstring & path);
	void OutputScore(const wstring & path);

};

