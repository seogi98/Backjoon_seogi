#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<stdlib.h>

using namespace std;


int main(void)
{
	char form[100];
	
	vector<char> op;
	vector<int> num;
	int DP[100];
	int flag=0;
	int form_len=0;
	int result=0;
	
	scanf("%s",form);
	form_len = strlen(form);
	
	
	for(int i=0;i<form_len;i++)
	{
		if((form[i]=='-')||(form[i]=='+'))
		{
			op.push_back(form[i]);
		}
	}
	char *token = strtok(form,"+-");
	while(token !=NULL)
	{
		num.push_back(atoi(token));
	   // cout << token<<endl;
		token = strtok(NULL,"+-");
	}
	result = num[0];
	for(int i=0;i<op.size();i++)
	{
		//cout << "op : " << op[i] <<endl;
		if(op[i] == '-')
		{
			flag =1;
		}
		if(flag == 1)
		{
			result -= num[i+1];
		}
		else
		{
			result += num[i+1];
		}
	}
	
	for(int i=0;i<num.size();i++)
	{
		//cout << "num : " << num[i] <<endl;
	}
	cout << result;
	

	
	
}
