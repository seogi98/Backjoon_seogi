#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
char c;
int n;
int result1=0;
int result2 = 0;
int result3 = 0;
char a;
stack<int>sq;
stack<int>lq;
int main(void)
{
	string temp;
	getline(cin, temp);
	for(int i=0;i<temp.size();i++)
	{
		c = temp[i];
		if (c == 32)
		{
			continue;
		}
		result1 = 0;
		result2 = 0;
		if (c == '(')
		{
			sq.push(c);
		}
		else if (c == ')')
		{
			if (a == '[')
			{
				result3 = 0;
				printf("0");
				return 0;
			}

			if (sq.empty())
			{
				result3 = 0;
				printf("0");
				return 0;
			}
			if (a == '(')
			{
				result1 += 2;
			}
			sq.pop();
			if (!sq.empty())
			{
				for(int i=0;i<sq.size();i++)
				result1 = result1 *2;
			}

			if (!lq.empty())
			{
				for (int i = 0; i<lq.size(); i++)
				result1 = result1 *3;
			}
			result3 += result1;


		}
		else if (c == '[')
		{
			lq.push(c);
		}
		else if (c == ']')
		{
			if (a == '(')
			{
				result3 = 0;
				printf("0");
				return 0;
			}
			if (lq.empty())
			{
				result3 = 0;
				printf("0");
				return 0;
			}
			if (a == '[')
			{
				result2 += 3;
			}
			lq.pop();
			if (!lq.empty())
			{
				for (int i = 0; i<lq.size(); i++)
				result2 = result2 *3;	
			}
			if (!sq.empty())
			{
				for (int i = 0; i<sq.size(); i++)
				result2 = result2 * 2;
			}
			result3 += result2;
		}
		a = c;
	}
	if ((!lq.empty()) || (!sq.empty()))
	{
		result3 = 0;
	}
	printf("%d", result3);

}
