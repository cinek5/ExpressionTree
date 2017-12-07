#include "stdafx.h"
#include "StringTokenizer.h"
#include <iostream>

StringTokenizer::StringTokenizer(string stringToParse)
{
	this->stringToParse = stringToParse;
	this->currentOffset = 0;
	this->currentToken = "";
}

StringTokenizer::StringTokenizer()
{
	this->stringToParse = "";
	this->currentOffset = 0;
	this->currentToken = "";
}


StringTokenizer::~StringTokenizer()
{
	
}

bool StringTokenizer::nextToken()
{  
	string newToken = "";
	if (currentOffset >= stringToParse.length()) return false;
	int i = currentOffset;
	for (; i < stringToParse.length() && stringToParse[i]!=' '; i++) {
		newToken += stringToParse[i];
		
	}
	while ((i < stringToParse.length()) && stringToParse[i] == ' ' ) {
		i++;
	}
	
	currentOffset = i;
	currentToken = newToken;
	return true;
}

void StringTokenizer::setNewString(string str)
{
	this->stringToParse = str;
	this->currentOffset = 0;
	this->currentToken = "";
}

string StringTokenizer::getToken()
{
	return currentToken;
}

int StringTokenizer::getCurrentOffset()
{
	return currentOffset;
}

void StringTokenizer::setOffset(int offset)
{
	this->currentOffset = offset;
}
