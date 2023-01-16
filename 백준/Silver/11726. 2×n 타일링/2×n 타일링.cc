#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d",&N);
	int DP[1000];
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	for (int i = 3; i <= N; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}
	printf("%d", DP[N] % 10007);
	return 0;
}