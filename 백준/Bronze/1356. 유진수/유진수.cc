#include<stdio.h>
#include<string.h>
using namespace std;
int main(void)
{
	char N[100] = { 1, };
	int length;
	int sum1=1, sum2=1;

	scanf("%s", N);
	length = strlen(N);
	
	for (int i = 0; i < length; i++)
	{
		N[i] = N[i] - 48;
	}

	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum1 =sum1* N[j];
		}
		for (int j = i; j < length; j++)
		{
			sum2 = sum2* N[j];
		}
		if (sum1 == sum2)
		{
			printf("YES");
			return 0;
		}
		sum1 = 1;
		sum2 = 1;
	}
	printf("NO");


}