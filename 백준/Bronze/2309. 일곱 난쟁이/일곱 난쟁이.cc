#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int height[9];
int sum=0;
int main(void)
{
	int temp;
	for (int i = 0; i < 9; i++) {
		scanf("%d", height + i);
		sum = sum + height[i];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100)
			{
				height[i] = 0; height[j] = 0;
				break;
			}
		}
		if (height[i] == 0)
		{
			break;
		}
	}
	sort(height, height + 9);
	for (int i = 2; i < 9; i++)
	{
		printf("%d\n", height[i]);
	}
}
