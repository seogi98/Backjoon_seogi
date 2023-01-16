#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int change[10];
int temp[10];
int main(void)
{
	int n,money,sum=0;
	scanf("%d", &n);
	scanf("%d", &money);
	for (int i = 0; i < n; i++)
		scanf("%d", temp + i);
	for (int i = 1; i <= n; i++)
	{
		change[n-i] = money / temp[n-i];
		money = money - change[n-i] * temp[n-i];
		sum += change[n-i];
	}
	printf("%d", sum);
}
