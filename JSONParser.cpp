// JSONParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*classes for JSON*/
struct Value
{
	virtual ~Value() = default;
	//virtual int weight() const;
};

struct Null : Value
{
	int weight() const { return 1; }

};

struct Bool : Value
{
	Bool(bool B) : Val(B) {}
	bool Val;
};

struct String : Value, string
{
	using string::string;

};

struct Array : Value, vector<Value*>
{
	using vector<Value*>::vector;
	~Array() {
		for (Value* v : *this)
			delete v;
	}
};

int parse();

int main()
{
	
	cout << "The weight of the JSON document is:" << parse();
	
	system("Pause");
	return 0;
}

/*Functions for parsing*/

int parse()
{
	char * F;
	char * L;
	ifstream jsonFile;
	string file;
	int weight = 0;
	jsonFile.open("jsonData.txt");

	while (jsonFile)
	{
		getline(jsonFile, file);
	}
	F = &file[0];
	L = &file[file.size() - 1];

	while (F != L)
	{
		if (*F == ' ')
		{
			F++;
		}

		else if (*F == 't')
		{
			F = F + 4;
			weight++;

		}

		else if (*F == 'f')
		{
			F = F + 5;
			weight++;
		}

		else if (*F == 'n')
		{
			F = F + 4;
			weight++;
		}

		else if (*F == '"')
		{
			F++;
			while (*F != '"')
			{

				if (*F == '\' ')
				{
					F = F + 2;
				}
				F++;

			}
			F++;
			weight++;

		}

		else if (*F == '[')
		{
			weight++;
			F++;
		}
		else if (*F == '{')
		{

			weight++;
			F++;
		}
		else if (isdigit(*F))
		{
			while (isdigit(*F))
			{
				F++;
			}
			weight++;
		}
		else
			F++;
	}
	

	return weight;

}
