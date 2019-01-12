#include "FStream.h"
#include <Windows.h>
#include <iostream>
#include "Format1.h"
#include "Format2.h"

#define DIR L"E:\\Projects\\Freelancer\\ReadWriteText\\Input"
#define INPUT_PATH L"E:\\Projects\\Freelancer\\ReadWriteText\\ICDM.txt"
#define OUT_POSITION_PATH L"E:\\Projects\\Freelancer\\ReadWriteText\\Output2DPosition.txt"
#define OUT_SCORE_PATH L"E:\\Projects\\Freelancer\\ReadWriteText\\OutputScore.txt"


//int main()
//{
//	FStream fstream;
//	//input by direction
//	//std::vector<wstring> lines =  fstream.ReadLineTextByDirection(DIR);
//
//	//input by specific path
//	std::vector<wstring> lines = fstream.ReadLineTextByFilePath(INPUT_PATH);
//
//	/*Form1Controler con = Form1Controler();
//	con.ParseData(lines);
//
//	con.Output2DPosition(OUT_POSITION_PATH);
//	con.OutputScore(OUT_SCORE_PATH);*/
//
//	Format2 format2 = Format2();
//	format2.ParserData(lines);
//	format2.Output();
//
//	system("pause");
//}

int main()
{
	std::string path = "E:\\Projects\\Freelancer\\ReadWriteText\\ICDM.txt";
	std::vector<std::vector<double>> datas = std::vector<std::vector<double>>();

	//read file
	std::vector<string> lines = std::vector<string>();
	ifstream input;
	input.open(path, ios::in);

	string content;
	while (!input.eof())
	{
		std::getline(input, content);
		lines.push_back(content);
	}
	input.close();
	//end read file

	//parse data
	for (int i = 0; i < lines.size(); ++i)
	{
		//parse line by line
		string line = lines.at(i);
		std::vector<std::string> line_parser = std::vector<std::string>();
		for (int j = 0; j < line.length(); ++j)
		{
			
			string newStr = "";
			while (((int)line[j] >= 48 && (int)line[j] <= 57 || line[j] == '.'))
			{
				newStr.push_back(line[j]);
				j++;
			}
			if ("" != newStr)
			{
				line_parser.push_back(newStr);
			}
		}

		//covert these strings to  numbers
		std::vector<double> numbers = std::vector<double>();
		for (int j = 0; j < line_parser.size(); ++j)
		{
			numbers.push_back(std::stof(line_parser.at(j)));
		}
			//Funs::ConvertWstringToDouble(line_parser);
		datas.push_back(numbers);
	}
	//end parse

	//output result
	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<double> numbers = datas.at(i);

		for (int j = 0; j < numbers.size(); ++j)
		{
			cout << numbers.at(j) << " ";
		}
		cout << "\n";
	}
	system("pause");
}