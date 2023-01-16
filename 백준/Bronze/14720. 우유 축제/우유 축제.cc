#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
int main(void)
{
	int map[1000];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", map + i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if ((q.size() % 3) == j)
			{
				if (map[i] == j)
				{
					q.push(i);
				}
			}
		}
	}
	printf("%d", q.size());

}