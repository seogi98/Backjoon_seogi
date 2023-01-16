#include<stdio.h>
#include<iostream>
using namespace std;
int n,k,u,w,t,result_count;
int arr[3];
int num;
int str1, ball1;
int str2, ball2;
int temp1[3];
int result[1000];
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{

		scanf("%d", &num);
		arr[0] = (num / 100);
		arr[1] = (num - (arr[0] * 100)) / 10;
		arr[2] = num - (arr[0] * 100) - arr[1] * 10;
		

		scanf("%d", &str1);
		scanf("%d", &ball1);
		for (k = 101; k < 1000; k++)
		{
			str2 = 0; ball2 = 0;
			t = k;
			temp1[0] = (t / 100);
			temp1[1] = (t - temp1[0] * 100)/10;
			temp1[2] = (t - temp1[0] * 100) - temp1[1] * 10;
			if (temp1[0] == temp1[1] || temp1[0] == temp1[2] || temp1[1] == temp1[2])
			{
				continue;
			}
			if (temp1[0] == 0 || temp1[1] == 0 || temp1[2] == 0)
			{
				continue;
			}
			for (int u = 0; u < 3; u++)
			{
				if (arr[u] == temp1[u])
				{
					str2++;
				}
				for (w = 0; w < 3; w++)
				{
					if (arr[u] == temp1[w])
						ball2++;
				}
			}
			ball2 = ball2 - str2;
			if ((str1 == str2) && (ball1 == ball2))
			{
				result[k]++;
			}
		}
	}
	for (int i = 100; i < 1000; i++) {
		if (result[i] == n) {
			result_count++;
		}
	}
	printf("%d", result_count++);
}