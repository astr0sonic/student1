#include "bracket.h"
#include<vector>
#include<iostream>
bool checkBrackets(const std::string& s)
{
	bool uslovie = true;
	vector<char> scobki;
	vector<char> alpha;
	int q = 0;
	int i = 0;
	while (s[i] != s.length() && uslovie == true)
	{
		switch (q)
		{
		case 0:
			if (s[i] == '[') q = 2;
			else if (s[i] == '(')q = 3;
			else if (s[i] == '{')q = 4;
			else if (s[i] == '<')q = 5;
			else if (s[i] == ']' || s[i] == ')' || s[i] == '}' || s[i] == '>')
			{
				q = 1;
			}
			else {
				q = 0; i++;
			}
			break;
		case 1:
			if (alpha[alpha.size() - 1] != s[i])
			{
				uslovie = false;
			}
			if (alpha[alpha.size() - 1] == s[i])
			{
				scobki.pop_back();
				alpha.pop_back();
				q = 0;
			}
			i++;
			break;
		case 2:
			scobki.push_back(s[i]);
			alpha.push_back(']');
			q = 0;
			i++;
			break;
		case 3:
			scobki.push_back(s[i]);
			alpha.push_back(')');
			q = 0;
			i++;
			break;
		case 4:
			scobki.push_back(s[i]);
			alpha.push_back('}');
			q = 0;
			i++;
			break;
		case 5:
			scobki.push_back(s[i]);
			alpha.push_back('>');
			q = 0;
			i++;
			break;
		}
	}
	if (!alpha.empty())
	{
		if (alpha[alpha.size() - 1] == s[i])
		{
			scobki.pop_back();
			alpha.pop_back();
		}
		else uslovie = false;
	}
	if (uslovie == true) return true;
	else return false;
}