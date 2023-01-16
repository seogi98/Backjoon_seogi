#include<stdio.h>
using namespace std;

int map[100][100];
int main(void)
{
	int count=0;
	int N, X, Y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &X, &Y);
		for (int j = X; j < X + 10; j++)
		{
			for (int k = Y; k < Y + 10; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	for (int j = 0; j < 100; j++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (map[j][k] == 1)
			{
				count++;

			}
		}
	}
	printf("%d", count);
}