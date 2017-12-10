#include "stdafx.h"
#include "helperfunctions.h"
bool isDigit(string & s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool isValidVariable(string & str)
{
	for (int i = 0; i < str.length(); i++) {
		if (!((isalpha(str[i]) || isdigit(str[i])))) {
			return false;
		}
	}
	return true;
}
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

map<string, int> copyDict(map<string, int>& other)
{
	map<string, int> newMap;
	for (std::map<string, int>::iterator iter = other.begin(); iter != other.end(); ++iter)
	{
		newMap[iter->first] = iter->second;
	}
	return newMap;
}

void removeElementFromDict(map<string, int>& map,string& keyStr)
{
	bool deleted = false;
	std::map<string, int>::iterator it;
	for (it = map.begin(); it != map.end() && !deleted;)
	{
		if ((it->first) == keyStr)
		{
			map.erase(it++);
			deleted = true;
		}
		else {
			++it;
		}
	}
}

