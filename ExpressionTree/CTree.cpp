#include "stdafx.h"
#include "CTree.h"
#include "CNode.h"
#include "helperfunctions.h"


CTree::CTree()
{
	isFormulaEntered = false;
	initMap();
}

CTree::CTree(CTree & other)
{
	copy(other);


}



CTree::~CTree()
{
	delete root;
}

void CTree::enterFormula(string formulaString)
{
	variablesMap.clear();
	stringTokenizer.setNewString(formulaString);
	root = new CNode();
	root->parseString(*this);
	isFormulaEntered = true;
}

void CTree::printTree()
{
	root->printNode();
	cout << endl;
	
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

int CTree::getNumberOfVariables()
{
	return variablesMap.size();
}

CTree CTree::operator+(CTree & other)
{
	CNode* leaf;
	CTree result(*this);
	if (result.root->hasNoChildren()) { // drzewo sklada sie tylko z jednego wezla, wiec wystarczy prosta podmiana
		result.root = other.root;
	}
	else {
		CNode* newLeaf = new CNode(*(other.root));
		leaf = result.root->swapLeaf(newLeaf);
	    
		if (!(leaf->isConstant())) {
			removeElementFromDict(result.variablesMap, leaf->getValue());
		}

		
		for (std::map<string, int>::iterator iter = other.variablesMap.begin(); iter != other.variablesMap.end(); ++iter)
		{
			string var = iter->first;
			result.addNewVariable(var);

		}
		delete leaf;
		
	}

	

	return result;
}

void CTree::operator=(CTree & other)
{
	if (isFormulaBeenEntered()) delete root;
	copy(other);
}

bool CTree::isFormulaBeenEntered()
{
	return isFormulaEntered;
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

void CTree::copy(CTree& other)
{
	this->root = new CNode(*other.root);
	this->variablesMap = copyDict(other.variablesMap);
	this->numOfArgsMap = copyDict(other.numOfArgsMap);
	this->isFormulaEntered = other.isFormulaEntered;
}
