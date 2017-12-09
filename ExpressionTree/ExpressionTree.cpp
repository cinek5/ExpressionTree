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
	drzewko->enterFormula("/ 10 + dsd b");
	drzewko->printTree();
	drzewko->printVars();
	int* vars = new int[2];
	vars[0] = 1;
	vars[1] = 4;
	CTree* drzewko2 = new CTree();
	drzewko2->enterFormula("+ chujCi wDupe"); 
	(*drzewko + *drzewko2).printTree();
	


	delete vars;
	
	delete drzewko;
	delete drzewko2;
	return 0;
}

