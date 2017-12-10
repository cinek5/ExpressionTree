#pragma once
#include "StringTokenizer.h"
#include <map>
#define DEFAULT_VALUE "1";
#define NON_DEFINED -1;
using namespace std;
class CTree
{
	friend class CNode;
public:
	CTree();
	CTree(CTree& other);
	~CTree();
	void enterFormula(string formulaString);
	void printTree();
	void printVars();
	double compute(int* vars);
	int getNumberOfVariables();
	CTree operator+ (CTree& other);
	void operator= (CTree& other);
	bool isFormulaBeenEntered();
	
private:
	CNode* root;
	bool isFormulaEntered;
	StringTokenizer stringTokenizer;
	map<string, int> numOfArgsMap;
	map<string, int> variablesMap;
	void addNewVariable(string& var);
	void initMap();
	bool setVariables(int* vars);
	void copy(CTree& other);


};

