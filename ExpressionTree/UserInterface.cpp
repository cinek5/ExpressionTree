#include "stdafx.h"
#include "UserInterface.h"


UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}
void UserInterface::v_handleSingleInput()
{
	string inputLine;
	getline(cin, inputLine);
	if (!inputLine.empty())
	{
		map<string, int >  commandsMap;
		commandsMap["ENTER"] = 0;
		commandsMap["VARS"] = 1;
		commandsMap["PRINT"] = 2;
		commandsMap["JOIN"] = 3;
		commandsMap["COMP"] = 4;
	
		for (string::size_type i = 0; i < inputLine.length() && inputLine[i]!=' '; i++)
		{
			inputLine[i] = toupper(inputLine[i]);
		}
		vector<string> slicedCommands = s_sliceCommand(inputLine);
		string command = slicedCommands[0];

		if (checkCommand(slicedCommands)) {
			switch (commandsMap[command]) {
			case 0: // ENTER 
			{
				tree.enterFormula(slicedCommands[1]);
				
			}
			break;
			case 1: // VARS
			{  
				if (checkIfTreeHasFormula()) {
					tree.printVars();
				}
			}
			break;
			case 2: // PRINT
			{
				if (checkIfTreeHasFormula()) {
					tree.printTree();
				}
			}
			break;
			case 3: // JOIN
			{
				if (checkIfTreeHasFormula()) {
					joinTree(slicedCommands[1]);
				}
			}
			break;
			case 4: // COMP
			{
				int * vars = makeVarsArray(slicedCommands);
			
				cout<<"Computing result:  " << tree.compute(vars) << endl;
				delete vars;
				
			}
			break;
			
			}
			
		}
		else {
			cout << "WRONG COMMAND, TRY AGAIN" << endl;
		}
	}
	else {
		cout << "empty line" << endl;
	}

}
vector<string> UserInterface::s_sliceCommand(string str)
{
	vector<string> result;
	size_t pos = 0;
	string delimiter;
	delimiter = " ";
	while ((pos = str.find(delimiter)) != std::string::npos) {
		string token;
		token = str.substr(0, pos);
		str.erase(0, pos + delimiter.length());
		if (token.length()>0) result.push_back(token);
	}
	if (str != " " && str != "") result.push_back(str);
	return result;
}
bool UserInterface::checkCommand(vector<string>& slicedCommands)
{
	map<string, int>::iterator it;
	map<string, int>  numOfArgsMap;
	numOfArgsMap["ENTER"] = -1;
	numOfArgsMap["JOIN"] = -1;
	numOfArgsMap["VARS"] = 1;
 	numOfArgsMap["PRINT"] = 1;
	numOfArgsMap["COMP"] = -2;
	numOfArgsMap["PRINT"] = 1;
	string command = slicedCommands[0];
	it = numOfArgsMap.find(command);


	if (it != numOfArgsMap.end()) {
		int numberOfArgs = numOfArgsMap[command];
		switch (numberOfArgs) {
		case -1:

			return checkFormulaArgs(slicedCommands);
			break;
		case -2:
			return checkVarsArgs(slicedCommands);
			break;
		default:
			return checkArguments(numOfArgsMap[command], slicedCommands);
			break;

		}






	}

	return false;
}

bool UserInterface::checkFormulaArgs(vector<string>& slicedCommands)
{  
	string command = slicedCommands[0];
	if (command == "ENTER" || command == "JOIN") {
		string formula = "";
		for (unsigned i = 1; i < slicedCommands.size(); i++) {
			formula += slicedCommands[i];
			if (i != slicedCommands.size() - 1) formula += " ";
		}
		slicedCommands.clear();
		slicedCommands.push_back(command);
		slicedCommands.push_back(formula);
		return true;
	} else return false;
}

bool UserInterface::checkVarsArgs(vector<string>& slicedCommands)
{
	if (slicedCommands.size() != tree.getNumberOfVariables()+1) return false;
	for (unsigned i = 1; i < slicedCommands.size(); i++) {
		if (!isDigit(slicedCommands[i])) return false;
	}
	return true;
}
bool UserInterface::checkArguments(int numberOfArguments, vector<string>& slicedCommands)
{
	if (slicedCommands.size() != numberOfArguments) return false;
	for (unsigned i = 1; i < slicedCommands.size(); i++) {
		if (!isDigit(slicedCommands[i])) return false;
	}
	return true;
}
int * UserInterface::makeVarsArray(vector<string>& slicedCommands)
{
	int numOfVars = tree.getNumberOfVariables();
    int * vars = new int[numOfVars];
	for (unsigned i = 1; i < slicedCommands.size(); i++) {
		vars[i-1] = stoi(slicedCommands[i]);
	}

	return vars;
}

bool UserInterface::checkIfTreeHasFormula()
{
	if (!tree.isFormulaBeenEntered()) {
		cout << "You have to enter the formula first!" << endl;
		return false;
	}
	return true;
}

void UserInterface::joinTree(string & formula)
{
	CTree tree2; 
	tree2.enterFormula(formula);
	tree = tree + tree2;
}
