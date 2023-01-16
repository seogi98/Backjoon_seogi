#include<stdio.h>
int main(void)
{
	int N, M;
	int map[30][30];
	int total=0;
	int tmp=0;
	int max = 0;

	scanf("%d %d",&N,&M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j < M; j++)
		{
			for (int k = 2; k < M; k++)
			{
				total = 0;
				for (int y = 0; y < N; y++)
				{
					tmp = map[y][i];
					if (tmp < map[y][j])
					{
						tmp = map[y][j];
					}
					if (tmp < map[y][k])
					{
						tmp = map[y][k];
					}
					total +=tmp;
				}
				if (total > max)
				{
					max = total;
				}
			}
		}
	}
	printf("%d", max);

}