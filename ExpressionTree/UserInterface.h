#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "CTree.h"
#include <vector>
#include "helperfunctions.h"
using namespace std;
class UserInterface
{
public:
	void  v_handleSingleInput();
	UserInterface();
	~UserInterface();
private:
	CTree tree;
	vector<string> s_sliceCommand(string str);
	bool checkArguments(int numberOfArguments, vector<string>& slicedCommands);
	bool checkCommand(vector<string>& slicedCommands);
	bool checkFormulaArgs(vector<string>& slicedCommands);
	bool checkVarsArgs(vector<string>& slicedCommands);
	int* makeVarsArray(vector<string>& slicedCommands);
	bool checkIfTreeHasFormula();
	void joinTree(string& formula);
};

