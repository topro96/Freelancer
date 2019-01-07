#include "Format1.h"
#include "Funcs.h"
#include "FStream.h"
#include <filesystem>


namespace fs = std::experimental::filesystem;

Format1::Format1() :
	x(0.0),
	y(0.0),
	s(0.0)
{
}

Format1::Format1(float _x, float _y, float _s) :
	x(_x),
	y(_y),
	s(_s)
{
}

Format1::Format1(const Format1 & other) :
	x(other.x),
	y(other.y),
	s(other.s)
{
}



Format1 Format1::GetData(const std::vector<wstring>& values)
{
	Format1 data = Format1();

	if (values.size() != UNIT)
		return data;

	data.x = Funs::ConvertWstringToDouble(values.at(0).c_str());
	data.y = Funs::ConvertWstringToDouble(values.at(1).c_str());
	data.s = Funs::ConvertWstringToDouble(values.at(2).c_str());

	return data;
}



Form1Controler::Form1Controler()
{
}

Form1Controler::Form1Controler(const Form1Controler & other)
{
}

void Form1Controler::ParseData(const std::vector<wstring> & lines)
{
	for (int i = 0; i < lines.size(); ++i)
	{
		std::vector<wstring> values = FStream::ParseString(lines.at(i));
		if (Format1::UNIT == values.size())
		{
			Format1 data = Format1::GetData(values);
			datas.push_back(data);
		}
	}
}

void Form1Controler::Output2DPosition(const wstring & path)
{
	wofstream output;
	output.open(path, ios::out);

	for (int i = 0; i < datas.size(); ++i)
	{
		output << datas.at(i).x;
		output << " ";
		output << datas.at(i).y;
		if (i != datas.size() - 1)
			output << "\n";
	}

	output.close();
}

void Form1Controler::OutputScore(const wstring & path)
{
	ofstream output;
	output.open(path, ios::out);

	for (int i = 0; i < datas.size(); ++i)
	{
		output << datas.at(i).s;

		if (i != datas.size() - 1)
			output << "\n";
	}

	output.close();
}