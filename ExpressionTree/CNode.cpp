#include "stdafx.h"
#include "CNode.h"
#include "helperfunctions.h"


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
