#include "stdafx.h"
#include "CNode.h"
#include "helperfunctions.h"
#include <math.h> 



CNode::CNode()
{
	value = "";
	isConst = false;
}


CNode::~CNode()
{
	for (int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}

void CNode::parseString( CTree& ctree)
{
	if (ctree.stringTokenizer.nextToken() && ctree.stringTokenizer.getToken()!=" ") // no errors
	{
		string token = ctree.stringTokenizer.getToken();
		if (ctree.numOfArgsMap.find(token) != ctree.numOfArgsMap.end()) {
			this->value = token;
			int numOfChildren = (ctree.numOfArgsMap)[token];
			for (int i = 0; i < numOfChildren; i++) {
				CNode* newNode = new CNode();
				this->children.push_back(newNode);
			}
			for (int i = 0; i < numOfChildren; i++) {
				children[i]->parseString(ctree);
			}



		}
		else  // not operator, check for variable
		{
			if (isDigit(token)) {
				isConst = true;
				this->value = token;
				

			}
			else if (isValidVariable(token)) {
				this->value = token;
				ctree.addNewVariable(token);
			}
			else {
				isConst = true;
				this->value = DEFAULT_VALUE;
			}

		}
	}
	else { // error, set default value
		isConst = true;
		this->value = DEFAULT_VALUE;
	}

}

void CNode::printNode()
{
	cout << value << " ";
	for (int i = 0; i < children.size(); i++) {
		children[i]->printNode();
	}
}

double CNode::compute(CTree & ctree)
{
	if (isConst) return stoi(this->value);
	else if (getVariableValue(ctree)!=COMPUTE_ERROR){
		return getVariableValue(ctree);
	}
	else {
		return computeOperand(ctree);
		

	}
	
}

int CNode::getVariableValue(CTree & ctree) 
{
	if (ctree.variablesMap.find(this->value) != ctree.variablesMap.end()) {
		return ctree.variablesMap[this->value];
	}

	return COMPUTE_ERROR;
}

double CNode::computeOperand(CTree & ctree) // return -1 if error
{
	if (value == "+") {
		return children[0]->compute(ctree) + children[1]->compute(ctree);
	}
	else if (value == "-") {
		return children[0]->compute(ctree) - children[1]->compute(ctree);
	}
	else if (value == "*") {
		return children[0]->compute(ctree) * children[1]->compute(ctree);
	}
	else if (value == "/") {
		return children[0]->compute(ctree) / children[1]->compute(ctree);
	}
	else if (value == "sin") {
		return sin(children[0]->compute(ctree));
	}
	else if (value == "cos") {
		return cos(children[0]->compute(ctree));
	}
	return COMPUTE_ERROR;
}
