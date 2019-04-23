//-----------------------------------------------------------------------------------
//	Programmers: Chase Moynihan, Andy Nguyen, Erik Lienhard
//	Course: CPSC 323 T/Th 4:00 - 5:15PM
//	Project: Parser Project
//	File Name: part2.cpp
//	Description: This program uses various logics to find syntactical errors 
//		and a parser to determine the validity of a grammar as it relates to
//		the input file to be converted into C++ executable language
//-----------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stack>
#include <array>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Checks input token to make sure it is valid
int switchTerrminal(char myChar);
//Checks state against predictiveParsingTable
int switchNonTerminal(char myChar);
bool is_number(const string& checkNumbers);

int main()
{
	//while loop variables
	bool done = false;
	char choice = '9';
	do
	{
		stack<char> inputStack; //Where the input equation is stored
		stack<char> storageStack; //Where the elements are stored during the parsing process
		array<array<string, 31>, 22> predicitveParsingTable;

		//Initializing predicitveParsingTable with # which will signal incorrect input
		for (int i = 0; i < predicitveParsingTable.size(); ++i)
		{
			for (int j = 0; j < predicitveParsingTable[i].size(); ++j)
			{
				predicitveParsingTable[i][j] = "#";
			}
		}

		//predictiveParsingTable reversed
		// "" is used for lambda
		//Row 0
		predicitveParsingTable[0][0] = "%G@D;B!";

		//Row 1
		predicitveParsingTable[1][15] = "CV";
		predicitveParsingTable[1][16] = "CV";
		predicitveParsingTable[1][17] = "CV";
		predicitveParsingTable[1][18] = "CV";

		//Row 2
		predicitveParsingTable[2][5] = "";
		predicitveParsingTable[2][6] = "";
		predicitveParsingTable[2][7] = "";
		predicitveParsingTable[2][8] = "";
		predicitveParsingTable[2][9] = "";
		predicitveParsingTable[2][12] = "";
		predicitveParsingTable[2][13] = "";
		predicitveParsingTable[2][14] = "";
		predicitveParsingTable[2][15] = "CV";
		predicitveParsingTable[2][16] = "CV";
		predicitveParsingTable[2][17] = "CV";
		predicitveParsingTable[2][18] = "CV";
		predicitveParsingTable[2][19] = "CU";
		predicitveParsingTable[2][20] = "CU";
		predicitveParsingTable[2][21] = "CU";
		predicitveParsingTable[2][22] = "CU";
		predicitveParsingTable[2][23] = "CU";
		predicitveParsingTable[2][24] = "CU";
		predicitveParsingTable[2][25] = "CU";
		predicitveParsingTable[2][26] = "CU";
		predicitveParsingTable[2][27] = "CU";
		predicitveParsingTable[2][28] = "CU";

		//Row 3
		predicitveParsingTable[3][3] = ";E:F";

		//Row 4
		predicitveParsingTable[4][15] = "WB";
		predicitveParsingTable[4][16] = "WB";
		predicitveParsingTable[4][17] = "WB";
		predicitveParsingTable[4][18] = "WB";

		//Row 5
		predicitveParsingTable[5][3] = "^";

		//Row 6
		predicitveParsingTable[6][4] = "ZH";
		predicitveParsingTable[6][15] = "ZH";
		predicitveParsingTable[6][16] = "ZH";
		predicitveParsingTable[6][17] = "ZH";
		predicitveParsingTable[6][18] = "ZH";

		//Row 7
		predicitveParsingTable[7][4] = "I";
		predicitveParsingTable[7][15] = "J";
		predicitveParsingTable[7][16] = "J";
		predicitveParsingTable[7][17] = "J";
		predicitveParsingTable[7][18] = "J";

		//Row 8
		predicitveParsingTable[8][4] = ";)B(&";

		//Row 9
		predicitveParsingTable[9][15] = ";K=B";
		predicitveParsingTable[9][16] = ";K=B";
		predicitveParsingTable[9][17] = ";K=B";
		predicitveParsingTable[9][18] = ";K=B";

		//Row 10
		predicitveParsingTable[10][5] = "XL";
		predicitveParsingTable[10][6] = "XL";
		predicitveParsingTable[10][10] = "XL";
		predicitveParsingTable[10][15] = "XL";
		predicitveParsingTable[10][15] = "XL";
		predicitveParsingTable[10][16] = "XL";
		predicitveParsingTable[10][17] = "XL";
		predicitveParsingTable[10][18] = "XL";
		predicitveParsingTable[10][19] = "XL";
		predicitveParsingTable[10][20] = "XL";
		predicitveParsingTable[10][21] = "XL";
		predicitveParsingTable[10][22] = "XL";
		predicitveParsingTable[10][23] = "XL";
		predicitveParsingTable[10][24] = "XL";
		predicitveParsingTable[10][25] = "XL";
		predicitveParsingTable[10][26] = "XL";
		predicitveParsingTable[10][27] = "XL";
		predicitveParsingTable[10][28] = "XL";

		//Row 11
		predicitveParsingTable[11][5] = "YM";
		predicitveParsingTable[11][6] = "YM";
		predicitveParsingTable[11][10] = "YM";
		predicitveParsingTable[11][15] = "YM";
		predicitveParsingTable[11][16] = "YM";
		predicitveParsingTable[11][17] = "YM";
		predicitveParsingTable[11][18] = "YM";
		predicitveParsingTable[11][19] = "YM";
		predicitveParsingTable[11][20] = "YM";
		predicitveParsingTable[11][21] = "YM";
		predicitveParsingTable[11][22] = "YM";
		predicitveParsingTable[11][23] = "YM";
		predicitveParsingTable[11][24] = "YM";
		predicitveParsingTable[11][25] = "YM";
		predicitveParsingTable[11][26] = "YM";
		predicitveParsingTable[11][27] = "YM";
		predicitveParsingTable[11][28] = "YM";

		//Row 12
		predicitveParsingTable[12][5] = "N";
		predicitveParsingTable[12][6] = "N";
		predicitveParsingTable[12][10] = ")K(";
		predicitveParsingTable[12][15] = "B";
		predicitveParsingTable[12][16] = "B";
		predicitveParsingTable[12][17] = "B";
		predicitveParsingTable[12][18] = "B";
		predicitveParsingTable[12][19] = "N";
		predicitveParsingTable[12][20] = "N";
		predicitveParsingTable[12][21] = "N";
		predicitveParsingTable[12][22] = "N";
		predicitveParsingTable[12][23] = "N";
		predicitveParsingTable[12][24] = "N";
		predicitveParsingTable[12][25] = "N";
		predicitveParsingTable[12][26] = "N";
		predicitveParsingTable[12][27] = "N";
		predicitveParsingTable[12][28] = "N";

		//Row 13
		predicitveParsingTable[13][5] = "TUO";
		predicitveParsingTable[13][6] = "TUO";
		predicitveParsingTable[13][19] = "TUO";
		predicitveParsingTable[13][20] = "TUO";
		predicitveParsingTable[13][21] = "TUO";
		predicitveParsingTable[13][22] = "TUO";
		predicitveParsingTable[13][23] = "TUO";
		predicitveParsingTable[13][24] = "TUO";
		predicitveParsingTable[13][25] = "TUO";
		predicitveParsingTable[13][26] = "TUO";
		predicitveParsingTable[13][27] = "TUO";
		predicitveParsingTable[13][28] = "TUO";

		//Row 14
		predicitveParsingTable[14][5] = "+";
		predicitveParsingTable[14][6] = "-";
		predicitveParsingTable[14][19] = "";
		predicitveParsingTable[14][20] = "";
		predicitveParsingTable[14][21] = "";
		predicitveParsingTable[14][22] = "";
		predicitveParsingTable[14][23] = "";
		predicitveParsingTable[14][24] = "";
		predicitveParsingTable[14][25] = "";
		predicitveParsingTable[14][26] = "";
		predicitveParsingTable[14][27] = "";
		predicitveParsingTable[14][28] = "";

		//Row 15
		predicitveParsingTable[15][5] = "";
		predicitveParsingTable[15][6] = "";
		predicitveParsingTable[15][7] = "";
		predicitveParsingTable[15][8] = "";
		predicitveParsingTable[15][13] = "";
		predicitveParsingTable[15][14] = "";
		predicitveParsingTable[15][19] = "TU";
		predicitveParsingTable[15][20] = "TU";
		predicitveParsingTable[15][21] = "TU";
		predicitveParsingTable[15][22] = "TU";
		predicitveParsingTable[15][23] = "TU";
		predicitveParsingTable[15][24] = "TU";
		predicitveParsingTable[15][25] = "TU";
		predicitveParsingTable[15][26] = "TU";
		predicitveParsingTable[15][27] = "TU";
		predicitveParsingTable[15][28] = "TU";

		//Row 16
		predicitveParsingTable[16][19] = "0";
		predicitveParsingTable[16][20] = "1";
		predicitveParsingTable[16][21] = "2";
		predicitveParsingTable[16][22] = "3";
		predicitveParsingTable[16][23] = "4";
		predicitveParsingTable[16][24] = "5";
		predicitveParsingTable[16][25] = "6";
		predicitveParsingTable[16][26] = "7";
		predicitveParsingTable[16][27] = "8";
		predicitveParsingTable[16][28] = "9";

		//Row 17
		predicitveParsingTable[17][15] = "P";
		predicitveParsingTable[17][16] = "Q";
		predicitveParsingTable[17][17] = "R";
		predicitveParsingTable[17][18] = "S";

		//Row 18
		predicitveParsingTable[18][5] = "XL+";
		predicitveParsingTable[18][6] = "XL-";
		predicitveParsingTable[18][13] = "";
		predicitveParsingTable[18][14] = "";

		//Row 19
		predicitveParsingTable[19][5] = "";
		predicitveParsingTable[19][6] = "";
		predicitveParsingTable[19][7] = "YM*";
		predicitveParsingTable[19][8] = "YM/";
		predicitveParsingTable[19][13] = "";
		predicitveParsingTable[19][14] = "";

		//Row 20
		predicitveParsingTable[20][12] = "E,";
		predicitveParsingTable[20][13] = "";

		//Row 21
		predicitveParsingTable[21][2] = "";
		predicitveParsingTable[21][4] = "G";
		predicitveParsingTable[21][15] = "G";
		predicitveParsingTable[21][16] = "G";
		predicitveParsingTable[21][17] = "G";
		predicitveParsingTable[21][18] = "G";

		//variables
		string userString;
		string currentStack = "";
		char currentRead = '9'; //Value currently being read from the input
		int currentReadInt = 999; //Int value of currentRead
		char currentPop = '9'; //Value currently being popped from the stack
		int currentPopInt = 9999; //Int value of currentPop
		int temp = 9999;
		int countIntegers = 0;
		int countCommas = 0;

		cout << "Reading file..." << endl;

		ifstream dataFile;
		dataFile.open("formatedText.txt");
		vector<string> stringVector;
		vector<string> testVector;
		vector<string> variableVector;
		vector<string> identifierVector;
		bool hasProgram, hasBegin, hasEnd, hasInteger, doneCountingCommas, validVariable;
		hasProgram = hasBegin = hasEnd = hasInteger = doneCountingCommas = validVariable = false;

		int countProgram, countBegin, countEnd;
		countProgram = countBegin = countEnd = 0;

		cout << "Processing..." << endl;
		while (!dataFile.eof())
		{	// in this area we find and replace reserved words and check for syntactical mistakes
			getline(dataFile, userString, '\n');

			if (userString.find("PROGRAM") != string::npos) 
			{
				userString.replace(0, 7, "!");
				countProgram++; //check if more PROGRAM appears
				hasProgram = true;
			}
			if (userString.find("BEGIN") != string::npos) 
			{
				userString.replace(0, 5, "@");
				countBegin++; //check if more BEGIN appears
				hasBegin = true;
			}
			if (userString.find("END.") != string::npos)
			{
				userString.replace(0, 4, "%");
				countEnd++; //check if more END. appears
				hasEnd = true;
			}
			if (userString.find("INTEGER") != string::npos) 
			{
				userString.replace(0, 7, "^");
				hasInteger = true;
				if (userString.find(":") == string::npos)
				{
					cout << "Error: expecting :" << endl;
					dataFile.close();
					system("pause");
					return 0;
				}
			}
			if (userString.find("PRINT") != string::npos) 
			{
				userString.replace(0, 5, "&");
			}
			else if (userString.find("RINT") != string::npos || userString.find("PRIN")
				!= string::npos || userString.find("PRI") != string::npos ||
				userString.find("INT") != string::npos || userString.find("RIN")
				!= string::npos)
			{
				cout << "Error: expecting PRINT" << endl;
				dataFile.close();
				system("pause");
				return 0;
			}
			if (userString == "@" || userString == "%")
			{
				// do nothing
			}
			else if (userString.find("BEGI") != string::npos || userString.find("EGIN") 
				!= string::npos || userString.find("EGI") != string::npos ||
				userString.find("BEIN") != string::npos || userString.find("BGIN")
				!= string::npos)
			{
				cout << "Error: expecting BEGIN" << endl;
				dataFile.close();
				system("pause");
				return 0;
			}
			else if (userString.find("ED") != string::npos || userString.find("ND") 
				!= string::npos || userString.find("EN") != string::npos)
			{
				if (userString.find(".") == string::npos)
				{
					cout << "Error: expecting ." << endl;
					dataFile.close();
					system("pause");
					return 0;
				}
				else
				{
					cout << "Error: expecting END." << endl;
					dataFile.close();
					system("pause");
					return 0;
				}	
			}
			else if (userString[userString.length() - 1] != ';')
			{
				cout << "Error: expecting ;" << endl;
				dataFile.close();
				system("pause");
				return 0;
			}
			if (userString.find("(") != string::npos && userString.find(")")
				== string::npos)
			{
				cout << "Error: expecting )" << endl;
				dataFile.close();
				system("pause");
				return 0;
			}
			if (userString.find(")") != string::npos && userString.find("(")
				== string::npos)
			{
				cout << "Error: expecting (" << endl;
				dataFile.close();
				system("pause");
				return 0;
			}
			userString.erase(remove(userString.begin(), userString.end(), ' '),
				userString.end());
			stringVector.push_back(userString);		// push pieces of the userString
			userString.clear();						// into the vector for parsing
		}
		dataFile.close();

		string testString = "";
		dataFile.open("formatedText.txt");
		while (dataFile >> testString) 
		{
			testVector.push_back(testString);
		}
		dataFile.close();

		variableVector.push_back("+");
		variableVector.push_back("-");
		variableVector.push_back("*");
		variableVector.push_back("/");
		variableVector.push_back("(");
		variableVector.push_back(")");
		variableVector.push_back(";");
		variableVector.push_back(":");
		variableVector.push_back("=");
		variableVector.push_back(",");
		variableVector.push_back("PRINT");
		variableVector.push_back("END.");

		userString = "";
		// conditions to be met, if they aren't issue and error and stop execution
		if (countProgram > 1) {
			cout << "Error: multiple PROGRAM declarations" << endl;
			system("pause");
			return 0;
		}
		if (countBegin > 1) {
			cout << "Error: multiple BEGIN declarations" << endl;
			system("pause");
			return 0;
		}
		if (countEnd > 1) {
			cout << "Error: multiple END. declarations" << endl;
			system("pause");
			return 0;
		}

		for (int i = 0; i < stringVector.size(); i++)
		{
			if (hasProgram == false) {
				cout << "Error: expecting PROGRAM" << endl;
				system("pause");
				return 0;
			}
			else if (hasBegin == false) {
				cout << "Error: expecting BEGIN" << endl;
				system("pause");
				return 0;
			}
			else if (hasEnd == false) {
				cout << "Error: expecting END." << endl;
				system("pause");
				return 0;
			}
			else if (hasInteger == false) {
				cout << "Error: expecting INTEGER" << endl;
				system("pause");
				return 0;
			}
			userString = userString + stringVector[i];
		}

		for (int i = 0; i < testVector.size(); i++)
		{
			if (testVector[i] == ":" && doneCountingCommas == false) { //checking for commas
				int q = i;
				while (testVector[q] != ";") {
					if (testVector[q] == ",") {
						countCommas++;
					}
					if (testVector[q] != "," && testVector[q] != ":") {
						variableVector.push_back(testVector[q]);
						identifierVector.push_back(testVector[q]);
						countIntegers++;
					}
					q++;
				}
				doneCountingCommas = true;
			}

			if (testVector[i] == "(") { //checking if print is missing or mispelled
				int q = i - 1;
				if (testVector[q] != "PRINT" && testVector[q] != "+" && testVector[q] != "-" &&
					testVector[q] != "*" && testVector[q] != "/") 
				{
					if (userString.find("-") != string::npos) { // negative implies a number, goes to next string
						q++;
					}
					if (is_number(testVector[q]) == true) {   //skips numbers because not variable
						q++;
					}
					for (int i = 0; i < variableVector.size(); i++) { // checks everything in vector with one token
						if (testVector[q] == variableVector[i] && variableVector[i] != "PRINT") {
							cout << "Error: illegal expression" << endl;
							system("pause");
							return 0;
						}
					}
					cout << "Error: expecting PRINT" << endl;
					system("pause");
					return 0;
				}
			}


			if (testVector[i] == "=") { //checking for unknown identifiers before = 
				int q = i - 1;
				for (int i = 0; i < variableVector.size(); i++) {
					if (testVector[q] == variableVector[i]) {
						validVariable = true;
					}
				}

				if (validVariable == false)
				{
					cout << "Error: unknown identifier" << endl;
					system("pause");
					return 0;
				}

				validVariable = false;
			}


			if (testVector[i] == "=") { //checking for unknown identifiers after =
				int q = i + 1;
				vector<string> temp;
				while (testVector[q] != ";") {
					if (userString.find("-") != string::npos) { // negative implies a number, goes to next string
						q++;
					}
					if (is_number(testVector[q]) == true) {   //skips numbers because not variable
						q++;
					}
					for (int i = 0; i < variableVector.size(); i++) { // checks everything in vector with one token
						if (testVector[q] == variableVector[i]) {
							validVariable = true;
						}
					}

					if (validVariable == false)
					{
						cout << "Error: unknown identifier" << endl;
						system("pause");
						return 0;
					}
					validVariable = false;
					q++;
				}
			}


			if (testVector[i] == "PRINT") { //checking for unknown identifiers after print(
				int q = i + 2;
				for (int i = 0; i < identifierVector.size(); i++) { // checks everything in vector with one token
					if (testVector[q] == identifierVector[i]) {
						validVariable = true;
					}
				}
				if (validVariable == false)
				{
					cout << "Error: unknown identifier" << endl;
					system("pause");
					return 0;
				}
				validVariable = false;
				q++;

				q = i + 3; //checks for )
				if (testVector[q] != ")")
				{
					cout << "Error: illegal expression" << endl;
					system("pause");
					return 0;
				}
			}

			if (testVector[i] == "(") { //checking for missing signs
				int q = i + 1;

				for (int i = 0; i < identifierVector.size(); i++) { // checks everything in vector with one token
					if (testVector[q] == identifierVector[i]) {
						validVariable = true;
					}
					if (validVariable == true) {
						q++;
						if (is_number(testVector[q]) == true) {
							cout << "Error: illegal expression" << endl;
							system("pause");
							return 0;
						}
					}
					validVariable = false;
				}
			}

		}

		if (countCommas >= countIntegers) { //Checks for additional commas
			cout << "Error: illegal expression" << endl;
			system("pause");
			return 0;
		}

		if (countCommas != countIntegers - 1) { //Checks for missing commas
			cout << "Error: expecting ," << endl;
			system("pause");
			return 0;
		}

		//Pushing first two elements into the stack
		inputStack.push('$');
		inputStack.push('A');

		//This outer loop makes sure we loop through the entire statement
		for (int i = 0; i < userString.length(); i++)
		{
			currentRead = userString[i];

			//Checking input using switchTerrminal
			currentReadInt = switchTerrminal(currentRead);

			//The loop will keep going until an unrecognized input token is reached signaling an invalid expression
			currentPop = inputStack.top();
			while (currentPop != currentRead)
			{
				currentPop = inputStack.top();

				inputStack.pop();

				//Checking state using switchNonTerminal
				currentPopInt = switchNonTerminal(currentPop);

				if (currentPopInt != 777)
				{
					//Invalid expression
					if (predicitveParsingTable[currentPopInt][currentReadInt] == "#")
					{
						cout << "Error: illegal expression" << endl;
						system("pause");
						return 0;
					}
					if (predicitveParsingTable[currentPopInt][currentReadInt] != "")
					{
						for (int j = 0; j < predicitveParsingTable[currentPopInt][currentReadInt].size(); ++j)
						{
							inputStack.push(predicitveParsingTable[currentPopInt][currentReadInt][j]);
						}
					}
				}
			}
			//temp is used because the size of inputStack is being modified
			temp = inputStack.size();

			for (int i = 0; i < temp; ++i)
			{
				storageStack.push(inputStack.top());
				currentStack.push_back(inputStack.top());
				inputStack.pop();
			}
			reverse(currentStack.begin(), currentStack.end());
			currentStack.clear();
			temp = storageStack.size();
			for (int i = 0; i < temp; ++i)
			{
				inputStack.push(storageStack.top());
				storageStack.pop();
			}

		}
		cout << "The grammar is accepted." << endl;
		done = true;
	} while (!done);

	system("pause");
	return 0;
}

//--------------------------------------------------------------------------------
// Name: switchTerrminal
// Input: a terminal character to test
// Output: the numerical representation of the terminal character
// Description: checks input token to make sure it is valid
//--------------------------------------------------------------------------------
int switchTerrminal(char myChar)
{
	int temp = 29;
	switch (myChar)
	{
	case '!':
		temp = 0;
		break;
	case '@':
		temp = 1;
		break;
	case '%':
		temp = 2;
		break;
	case '^':
		temp = 3;
		break;
	case '&':
		temp = 4;
		break;
	case '+':
		temp = 5;
		break;
	case '-':
		temp = 6;
		break;
	case '*':
		temp = 7;
		break;
	case '/':
		temp = 8;
		break;
	case '=':
		temp = 9;
		break;
	case '(':
		temp = 10;
		break;
	case ':':
		temp = 11;
		break;
	case ',':
		temp = 12;
		break;
	case ';':
		temp = 13;
		break;
	case ')':
		temp = 14;
		break;
	case 'P':
		temp = 15;
		break;
	case 'Q':
		temp = 16;
		break;
	case 'R':
		temp = 17;
		break;
	case 'S':
		temp = 18;
		break;
	case '0':
		temp = 19;
		break;
	case '1':
		temp = 20;
		break;
	case '2':
		temp = 21;
		break;
	case '3':
		temp = 22;
		break;
	case '4':
		temp = 23;
		break;
	case '5':
		temp = 24;
		break;
	case '6':
		temp = 25;
		break;
	case '7':
		temp = 26;
		break;
	case '8':
		temp = 27;
		break;
	case '9':
		temp = 28;
		break;
	case '$':
		temp = 29;
		break;
	default:
		cout << "Error: illegal expression" << endl;
		break;
	}
	return temp;
}

//--------------------------------------------------------------------------------
// Name: switchNonTerrminal
// Input: a nonterminal character to test
// Output: the numerical representation of the nonterminal character
// Description: checks input token to make sure it is valid
//--------------------------------------------------------------------------------
int switchNonTerminal(char myChar)
{
	int temp = 9999;
	switch (myChar)
	{
	case 'A':
		temp = 0;
		break;
	case 'B':
		temp = 1;
		break;
	case 'C':
		temp = 2;
		break;
	case 'D':
		temp = 3;
		break;
	case 'E':
		temp = 4;
		break;
	case 'F':
		temp = 5;
		break;
	case 'G':
		temp = 6;
		break;
	case 'H':
		temp = 7;
		break;
	case 'I':
		temp = 8;
		break;
	case 'J':
		temp = 9;
		break;
	case 'K':
		temp = 10;
		break;
	case 'L':
		temp = 11;
		break;
	case 'M':
		temp = 12;
		break;
	case 'N':
		temp = 13;
		break;
	case 'O':
		temp = 14;
		break;
	case 'T':
		temp = 15;
		break;
	case 'U':
		temp = 16;
		break;
	case 'V':
		temp = 17;
		break;
	case 'X':
		temp = 18;
		break;
	case 'Y':
		temp = 19;
		break;
	case 'W':
		temp = 20;
		break;
	case 'Z':
		temp = 21;
		break;
	default:
		temp = 777;
		break;
	}
	return temp;
}


//--------------------------------------------------------------------------------
// Name: is_number
// Input: a reference to a string
// Output: a boolean value 
// Description: checks to see whether the string input is a number or not
//--------------------------------------------------------------------------------
bool is_number(const string& checkNumbers)
{
	string::const_iterator it = checkNumbers.begin();
	while (it != checkNumbers.end() && isdigit(*it)) ++it;
	return !checkNumbers.empty() && it == checkNumbers.end();
}