#pragma once
#include <string>
#include <map>
using namespace std;
bool isDigit(string& str);
bool isValidVariable(string& str);
string trim(const string& str);
map<string, int> copyDict(map<string, int>& other);
void removeElementFromDict(map < string, int>& map,string& keyStr);
