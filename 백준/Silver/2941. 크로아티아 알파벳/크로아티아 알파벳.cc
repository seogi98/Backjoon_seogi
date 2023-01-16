#include<stdio.h>

#include<string.h>

using namespace std;

int main(void)
{
	char str[200];
	scanf("%s", str);
	int total= strlen(str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'c')
		{
			if(str[i + 1]=='-')
				total--;


			if (str[i + 1] == '=')
				total--;
		}
		if (str[i] == 'd')
		{
			if (str[i + 1] == 'z') {
				if (str[i + 2] == '=')
				{
					total --;
				}
			}
			if (str[i + 1] == '-')
			{
				total--;
			}
		}
		if (str[i] == 'j')
		{
			if (str[i - 1] == 'l')
			{
				total--;
			}
			if (str[i - 1] == 'n')
			{
				total--;
			}
		}
		if (str[i] == 's')
		{
			if (str[i+1] == '=')
			{
				total --;
			}
		}
		if (str[i] == 'z')
		{
			if (str[i+1] == '=')
			{
				total--;
			}
		}
	}
	printf("%d", total);
}
