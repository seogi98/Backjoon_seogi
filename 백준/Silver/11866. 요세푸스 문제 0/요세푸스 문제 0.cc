#include<iostream>
#include<queue>
using namespace std;
queue<int>q;
int main(void)
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i < N+1; i++)
	{
		q.push(i);
	}
	printf("<");
	N--;
	while (N--)
	{
		for (int i = 0; i < M - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d, ",q.front());
		q.pop();
	}
	printf("%d>", q.front());
}
