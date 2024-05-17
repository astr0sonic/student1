#include "max_value.h"

double calculateMaxValue(double* nums, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] < 0)
			k++;
	}
	if (k == 0 || k == 1)
	{
		a = chislo[0];
		for (int i = 1; i < chislo.size(); i++)
		{
			b = chislo[i];
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
		
		a = chislo[0];
		for (int i = 1; i < chislo.size(); i++)
		{
			b = chislo[i];
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
	else if (k % 2 != 0)
	{
		int otr = 0;
		a = chislo[0];
		if (a < 0) otr++;
		for (int i = 1; i < chislo.size(); i++)
		{
			b = chislo[i];
			int c = b;
			if (b < 0)otr++;
			if (a > 1 && b > 1)
			{
				a = a * b;
			}
			else if (otr % 2 == 0 && a < 0 && b < 0)
			{
				a = a + b;
			}
			else if (otr % 2 != 0 && otr != 1 && a < 0 && b < 0 && c != b)
			{
				a = a * b;
			}
			else if (otr % 2 != 0 && otr != 1 && a < 0 && b < 0 && c == b)
			{
				a = a / b;
			}
			else if (a > 1 && b < 0)
				a = a * b;
			else if (a > 0 && a < 1 && b>0 && b < 1)
			{
				
				a = a * b;
			}
			else if (a < 0 && a > -1 && b < 0 || a > 0 && b == 1 || a > 1 && a < 2 && b>1 || a == 1)
			{
			
				a = a + b;
			}
		}
	}
	
	return a;
}

