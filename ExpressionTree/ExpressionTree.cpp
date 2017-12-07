// ExpressionTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringTokenizer.h"
#include "CTree.h"
#include <string>
#include <iostream>
#include "helperfunctions.h"
using namespace std;
int main() {
	CTree* drzewko = new CTree();
	drzewko->enterFormula("+ duzy kutas");
	drzewko->printTree();
	drzewko->printVars();
	
	delete drzewko;
	return 0;
}

