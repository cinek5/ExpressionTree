// ExpressionTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UserInterface.h"

using namespace std;
int main() {

	UserInterface userInterface;
	while (true) {
		userInterface.v_handleSingleInput();
	}
	return 0;
}

