#include<iostream>
#include<queue>
using namespace std;
queue<int>q;
int main(void)
{
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i < N+1; i++)
	{
		q.push(i);
	}
	N--;
	while (N--)
	{
		printf("%d ", q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d ", q.front());
}
