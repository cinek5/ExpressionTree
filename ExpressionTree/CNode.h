#pragma once
#include <vector>
#include "CTree.h"
#include <iostream>
using namespace std;
class CNode
{
public:
	CNode();
	~CNode();
	void parseString(CTree& ctree);
	void printNode();
private:
	bool isConst;
	string value;
	vector<CNode*> children;
	

};

