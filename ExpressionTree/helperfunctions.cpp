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

