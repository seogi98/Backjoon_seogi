#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int N, M,V;
int a, b;
int map[1001][1001];
int visit1[1001];
int visit2[1001];
stack<int>st;
queue<int>q;
void dfs(int cur) {
	visit1[cur] = true;
	printf("%d ", cur);
	for (int next = 1; next < N+1; next++)
	{
		if (!visit1[next] && map[cur][next])
			dfs(next);
	}
}
void bfs(int node)
{
	visit2[node] = true;
	q.push(node);
	while (!q.empty())
	{
		int cur = q.front();
		printf("%d ", cur);
		q.pop();
		for (int next = 1; next < N + 1; next++)
		{
			if (!visit2[next] && map[cur][next])
			{
				visit2[next] = true;
				q.push(next);
			}
		}

	}
}
int main(void)
{
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &V);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}	
		dfs(V);
		printf("\n");
		bfs(V);

}