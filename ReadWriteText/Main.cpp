#include "FStream.h"
#include <Windows.h>
#include <iostream>
#include "Format1.h"
#include "Format2.h"

#define DIR L"E:\\Projects\\Freelancer\\ReadWriteText\\Input"
#define INPUT_PATH L"E:\\Projects\\Freelancer\\ReadWriteText\\ICDM .txt"
#define OUT_POSITION_PATH L"E:\\Projects\\Freelancer\\ReadWriteText\\Output2DPosition.txt"
#define OUT_SCORE_PATH L"E:\\Projects\\Freelancer\\ReadWriteText\\OutputScore.txt"


int main()
{
	FStream fstream;
	//input by direction
	//std::vector<wstring> lines =  fstream.ReadLineTextByDirection(DIR);

	//input by specific path
	std::vector<wstring> lines = fstream.ReadLineTextByFilePath(INPUT_PATH);

	/*Form1Controler con = Form1Controler();
	con.ParseData(lines);

	con.Output2DPosition(OUT_POSITION_PATH);
	con.OutputScore(OUT_SCORE_PATH);*/

	Format2 format2 = Format2();
	format2.ParserData(lines);
	format2.Output();

	system("pause");
}