//-----------------------------------------------------------------------------------
//	Programmers: Chase Moynihan, Andy Nguyen, Erik Lienhard
//	Course: CPSC 323 T/Th 4:00 - 5:15PM
//	Project: Parser Project
//	File Name: part1.cpp
//	Description: A program to take a text file and format it 
//	to prepare text for the parser.
//-----------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

string removeLeadEndSpace(const string & aString, 
	const string & whitespace);
string removeWhitespace(const string & aString, 
	const string & fillInWith, const string & whitespace);
string addSpace(string & aString, const string & fillInWith,
	string findThis);
void formatString(string inputData, string whitespace, 
	string numbers,	string letters, vector<string>, int & j,
	string * storeData);

int main()
{
	string inputData;					// string to hold input
	string storeData[30];				// array of strings to hold
	string whitespace = " \t";			//    output
	string numbers = "0123456789";		
	string letter = "PQRS";				// items we want to look for 
	vector <string> lookFor = { "=", "*", "-", ";", "(", ")",
		":", "+", ","};
	fstream f, g;						// variables for file streams
	int k, j;							// variables for counting
	k = j = 0;
	cout << "Processing file.... ";
	cout << "\n\n";
	f.open("unformatedText.txt", ios::in);
	while (!f.eof())
	{									// open the file, get a line, process it
		if (f.fail())					//    and put it in buffer
		{
			break;
		}
		getline(f, inputData, '\n');
		formatString(inputData, whitespace, numbers, letter, 
			lookFor, j, storeData);
		k++;
	}
	f.close();
	g.open("formatedText.txt", ios::out);
	for (int i = 0; i < k; i++)
	{
		g << storeData[i];
		g << endl;						// open a file and write
		if (g.fail())					//    to it from buffer
		{
			break;
		}
	}
	g.close();
	cout << "\n";
	cout << "Goodbye!\n\n";
	system("pause");
	return 0;
}

//------------------------------------------------------------
// Name:   removeLeadEndSpace
// Input:  aString to process, an string of whitespace
// Output: aString with leading spaces removed
//------------------------------------------------------------
string removeLeadEndSpace(const string & aString, 
	const string & whitespace)
{
	const int beg = aString.find_first_not_of(whitespace);
	if (beg == string::npos)
	{
		return "";
	}
	const int end = aString.find_last_not_of(whitespace);
	const int size = end - beg + 1;

	return aString.substr(beg, size);
}

//-------------------------------------------------------------
// Name:   removeWhiteSpace
// Input:  aString to process, an string of whitespace, 
//		   and one space to be used to replace large gaps
// Output: aString with leading, trailing, and large gaps 
//		   removed
//-------------------------------------------------------------
string removeWhitespace(const string & aString, 
	const string & fillInWith, const string & whitespace)
{
	string trimmed = removeLeadEndSpace(aString, whitespace);
	int beg = trimmed.find_first_of(whitespace);
	while (beg != string::npos)
	{
		const int end = trimmed.find_first_not_of(whitespace,
			beg);
		const int size = (end - beg);
		trimmed.replace(beg, size, fillInWith);
		const int newBeg = beg + fillInWith.length();
		beg = trimmed.find_first_of(whitespace, newBeg);
	}

	return trimmed;
}

//-------------------------------------------------------------
// Name:   addSpace
// Input:  aString to process, an string to look for, 
//		   and one space to be used to insert between symbols
// Output: aString with a space added between symbols 
//-------------------------------------------------------------
string addSpace(string & aString, const string & fillInWith,
	string findThis)
{
	int posFound = 0;
	int i = 0;
	for (i; i < aString.length(); i++)
	{
		posFound = aString.find(findThis, posFound + 
			(i % aString.length()));
		if (posFound != -1)
		{
			aString.insert(posFound, fillInWith);
			aString.insert(posFound + 2, fillInWith);
		}
	}

	return aString;
}

//-------------------------------------------------------------
// Name:   formatString
// Input:  input from user, a string of whitespace, a string
//		   of numbers, a string of letters, the symbols to find,
//		   a counting variable, and a buffer.
// Output: a formatted string that is stored in the buffer 
//-------------------------------------------------------------
void formatString(string inputData, string whitespace, 
	string numbers,	string letters, vector<string> lookFor, 
	int & j, string * storeData)
{
	if (inputData != "")
	{
		inputData = removeWhitespace(inputData, " ", whitespace);
		if (inputData.find("//") != string::npos)
		{
			if (inputData.find("//") == inputData.length() - 2)
			{
				inputData.erase(inputData.begin(), inputData.end());
			}
			else
			{
				auto beg = inputData.find("//");
				inputData.erase(beg, string::npos);
			}	
		}
		if (inputData == "")
		{
			return;
		}
		for (int i = 0; i < lookFor.size(); i++)
		{
			if (inputData.find(lookFor[i]) != string::npos)
			{
				if (lookFor[i] == "-" && inputData.find(numbers))
				{
					inputData.insert(inputData.find(lookFor[i]), " ");
					inputData.insert(inputData.find(lookFor[i]) + 3, " ");
				}
				else
				{
					inputData = addSpace(inputData, " ", lookFor[i]);
				}
			}
		}
		inputData = removeWhitespace(inputData, " ", whitespace);
		cout << inputData;
		storeData[j] = inputData;
		j++;
	}
}