#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;


int alpa[36];
int arr;

#define length 'z'-'a'+1
int main()
{
	int max;
	for (int i = 0; i<5000; i++)
	{
		arr = getchar();
		if (('a' <= arr) && (arr <= 'z'))
			alpa[arr - 'a']++;


	}
	max = 0;
	for (int i = 0; i < length; i++)
	{
		if (alpa[max] < alpa[i])
		{
			max = i;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (alpa[i] == alpa[max])
		{
			
			printf("%c", i + 'a');
		}
	}
	return 0;
}