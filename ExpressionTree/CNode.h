#pragma once
#include <vector>
#include "CTree.h"
#include <iostream>
#define COMPUTE_ERROR -1337
using namespace std;
class CNode
{
public:
	CNode();
	~CNode();
	void parseString(CTree& ctree);
	void printNode();
	double compute(CTree& ctree);
private:
	int getVariableValue(CTree& ctree);
	bool isConst;
	string value;
	vector<CNode*> children;
	double computeOperand(CTree & ctree);
	

};

