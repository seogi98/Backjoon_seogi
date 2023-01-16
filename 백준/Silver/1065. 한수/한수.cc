#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n;
int temp[3];
int count1 = 99;
int main(void)
{
	scanf("%d", &n);

	if (n < 100)
	{
		printf("%d", n);
		return 0;
	}
	for (int i =100; i <= n; i++) {
			temp[0] = i / 100;
			temp[1] = (i - temp[0] * 100) / 10;
			temp[2] = i - temp[0] * 100 - temp[1] * 10;
		if (temp[2] - temp[1] == temp[1] - temp[0])
		{
			count1++;
		}
	}
	printf("%d", count1);
}
