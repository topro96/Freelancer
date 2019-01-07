#include "Format2.h"
#include "FStream.h"
#include "Funcs.h"


Format2::Format2()
{
}


Format2::~Format2()
{
}


void Format2::ParserData(std::vector<std::wstring>& lines)
{
	for (int i = 0; i < lines.size(); ++i)
	{
		std::vector<std::wstring> line_parser = FStream::ParseString(lines.at(i));
	
		std::vector<double> numbers = Funs::ConvertWstringToDouble(line_parser);
		datas.push_back(numbers);
	}
}

void Format2::Output()
{
	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<double> numbers = datas.at(i);

		for (int j = 0; j < numbers.size(); ++j)
		{
			cout << numbers.at(j) << " ";
		}
		cout << "\n";
	}

}

