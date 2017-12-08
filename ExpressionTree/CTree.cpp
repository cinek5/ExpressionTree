#include "stdafx.h"
#include "CTree.h"
#include "CNode.h"


CTree::CTree()
{
	initMap();
}



CTree::~CTree()
{
	delete root;
}

void CTree::enterFormula(string formulaString)
{
	stringTokenizer.setNewString(formulaString);
	root = new CNode();
	root->parseString(*this);
}

void CTree::printTree()
{
	root->printNode();
	
}

void CTree::printVars()
{
	cout << "Variables: " << endl;
	map<string, int>::iterator it;

	for (it = variablesMap.begin(); it != variablesMap.end(); it++)
	{
		cout << it->first << endl;
	}
}

double CTree::compute(int * vars)
{
	setVariables(vars);
	return root->compute(*this);
}

void CTree::addNewVariable(string& variable)
{
	if (variablesMap.find(variable) == variablesMap.end()) {
		variablesMap[variable] = NON_DEFINED;
	}
}

void CTree::initMap()
{
	numOfArgsMap["+"] = 2;
	numOfArgsMap["-"] = 2;
	numOfArgsMap["/"] = 2;
	numOfArgsMap["sin"] = 1;
	numOfArgsMap["cos"] = 1;
	numOfArgsMap["*"] = 2;
}

bool CTree::setVariables(int* vars)
{
	int index = 0;
	for (std::map<string, int>::iterator iter = variablesMap.begin(); iter != variablesMap.end(); ++iter)
	{
		iter->second = vars[index++];
	}

	return true;
}
