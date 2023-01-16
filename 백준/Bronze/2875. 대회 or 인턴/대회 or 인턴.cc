#include<stdio.h>

int main(void)
{
	int N, M, K;
	int TN, TM;
	int max=0;
	int tmp=0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i <= K; i++)
	{
		tmp = 0;
		TN = N - i;
		TM = M - (K - i);
		if (TM <= 0 || TN <= 0)
		{
			tmp = 0;
		}
		else {
			if (TN / TM >= 2)
			{
				tmp = TM;
			}
			else
			{
				tmp = TN / 2;
			}
		}
		if (tmp > max)
		{
			max = tmp;
		}
	}
	printf("%d", max);
}