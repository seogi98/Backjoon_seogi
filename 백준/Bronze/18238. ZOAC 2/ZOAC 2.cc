#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

int findMinTime(char bf, char nx) 
{
	int tmp;
	if(nx>bf)
	{
		tmp = nx-bf;
	}
	else
	{
		tmp = bf - nx;
	}
	if(tmp > 13)
	{
		return 26-tmp;
	}
	else
	{
		return tmp;
	}
}

int main(void)
{
	string str;
	char bftmp;
	int total=0;
	 
	cin  >> str;
	bftmp = str[0];
	total+=findMinTime('A',bftmp);
	for(int i=1;i<str.length();i++)
	{
		total += findMinTime(bftmp,str[i]);
		bftmp = str[i];
	}
	cout << total;
}        