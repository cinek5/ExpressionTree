#pragma once
#include <string>
using namespace std;
class StringTokenizer
{
public:
	StringTokenizer(string stringToParse);
	StringTokenizer();
	~StringTokenizer();
	bool nextToken();
	void setNewString(string str);
	string getToken();
	int getCurrentOffset();
	void setOffset(int offset);
private: 
	int currentOffset;
	string currentToken;
	string stringToParse;

	
};

