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
	drzewko->enterFormula("/ 9 + 4 3");
	drzewko->printTree();
	//drzewko->printVars();
	int* vars = new int[2];
	vars[0] = 3;
	vars[1] = 4;
	cout << drzewko->compute(vars) << endl;
	
	


	delete vars;
	
	delete drzewko;
	return 0;
}

