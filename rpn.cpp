#include "rpn.h"
#include<stack>
double calculateRPN(const std::string& s)
{
	std::stack<double> itog;
	double x;
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
		{
			x = s[i] - '0';
			itog.push(x);
		}
		else if (s[i] == '/' || s[i] == '*' || s[i] == '+' || s[i] == '-')
		{
			x = itog.top();
			itog.pop();
			if (s[i] == '/')
			{
				
				x = itog.top() / x;
				
				itog.pop();
				itog.push(x);
			}
			else if (s[i] == '*')
			{
				x = itog.top() * x;
				
				itog.pop();
				itog.push(x);
			}
			else if (s[i] == '+')
			{
				
				x = itog.top() + x;
				itog.pop();
				itog.push(x);
			}
			else if (s[i] == '-')
			{
				
				x = itog.top() - x;
				
				itog.pop();
				itog.push(x);
			}
		}
	}
	return itog.top();
}
