#include "max_value.h"

double calculateMaxValue(double* nums, int n)
{
	double a, b, c;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] < 0)
			k++;
	}
	if (k == 0 || k == 1)
	{
		a = nums[0];
		for (int i = 1; i < n; i++)
		{
			b =nums[i];
			if (a > 1 && b < 1 && b>0)
				a = a / b;
			else if (a < 1 && b > 1)
				a = a * b;
			else if (a == 1 || b == 1) a = a + b;
			else if (a > 1 && b > 1) a = a * b;
			else if (a < 1 && b < 1 && b>0 && a>0)a = a * b;
			else if (a < 0 && b>0) a = b - a;
			else if (b < 0 && a>0) a = a - b;
			else if (a == 0 || b == 0)a = a + b;
		}
	}
	else if (k % 2 == 0)
	{
		
		a =nums[0];
		for (int i = 1; i < n; i++)
		{
			b = nums[i];
			c = b;
			if (a > 1 && b < 0)
				a = a * b;
			else if (a > 0 && a < 1 && b>0 && b < 1)
			{
			
				a = a * b;
			}
			else if (a > 0 && a < 1 && b < 0 || a < 0 && b == 1)
			{
				
				a = b - a;
			}
			else if (a < 0 && a > -1 && b < 0 || a > 0 && b == 1 || a > 1 && a < 2 && b>1 || a == 1)
			{
			
				a = a + b;
			}
			else if (a > 1 && b > 0 && b < 1 && c != b || a < 0 && b < 1 && b > 0 && c != b)
			{
				
				a = a / b;
			}
			else if (a < 0 && b < 0 || a < 0 && b>1)
			{
				
				a = a * b;
			}
			else if (a > 1 && b > 1)
			{
				
				a = a * b;
			}
			else if (a == 0 || b == 0)a = a + b;
		}
	}
	
	return a;
}

