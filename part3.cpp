//-----------------------------------------------------------------------------------
//	Programmers: Chase Moynihan, Andy Nguyen, Erik Lienhard
//	Course: CPSC 323 T/Th 4:00 - 5:15PM
//	Project: Parser Project
//	File Name: part3.cpp
//	Description: A program that translates a language to C++
//-----------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("formatedText.txt");

	//To read file line by line
	string currentLine;

	//Variables to check file against
	string prog = "PROGRAM";
	string integer = "INTEGER";
	string begin = "BEGIN";
	string print = "PRINT";
	string end = "END.";

	string intLater;	//used to print out integer delcerations after int main()

	//execute loop while not at the end of the file
	while (getline(inFile, currentLine))
	{
		//!inFile.eof()
		//cin.ignore(256, '\n');

		//temp variables to check for reserve words
		//could be done better
		string progtmp = currentLine.substr(0, 7);
		string integertmp = currentLine.substr(0,7);
		string begintmp = currentLine.substr(0,5);
		string printtmp = currentLine.substr(0,5);
		string endtmp = currentLine.substr(0,4);

		//Checking for PROGRAM
		if (prog.compare(progtmp) == 0)
		{
			cout << "#include <iostream>\nusing namespace std;\n";
		}

		//Checking for INTEGER
		else if (integer.compare(integertmp) == 0)
		{
			intLater = currentLine.substr(10,currentLine.length());
		}

		//Checking for BEGIN
		else if (begin.compare(begintmp) == 0)
		{
			cout << "int main()\n{\n";
			cout << "\tint " << intLater << endl;
		}

		//Initializing variables and declaring them.
		else if (currentLine.find("=") != string::npos)
		{
			cout << "\t" << currentLine << endl;
		}

		//Checking for PRINT
		else if (print.compare(printtmp) == 0)
		{
			//print what is inside the print function. at index print + 2, end - 1
			int tmp = currentLine.find_first_of(")");
			cout << "\tcout << " << currentLine.substr(8, tmp - 8) << "<< endl ;" << endl;
		}

		//Checking for END.
		else if (end.compare(endtmp) == 0)
		{
			cout << "\treturn 0;\n}\n";
		}
		else {
			;
		}

	}
	return 0;
}