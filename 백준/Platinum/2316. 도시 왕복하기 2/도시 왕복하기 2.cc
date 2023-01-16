#include <bits/stdc++.h>
using namespace std;
#define MMAX 1000
#define MAX 400
#define INF 1999999999
// 같은 정점의 방문 표시를 하기 위해서 하나의 마을을 2개로 분리한다.
// 한번 들어온 정점인 경우 용량이 꽉차기 떄문에 다른 flow 가 들어 올 수 없다.
int c[MMAX][MMAX]; // c[i][j]: i에서 j로 가는 간선의 용량
int f[MMAX][MMAX]; // f[i][j]: i에서 j로 현재 흐르는 유량
vector<int> E[MMAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int P;
	cin >> N >> P;
	for(int i=1;i<=N;i++)
	{
		int in = i;
		int ot = i+MAX;
		c[in][ot] =1;
		E[in].push_back(ot);
		E[ot].push_back(in);
	}
	for (int i = 0; i < P; i++)
	{
		int node1I , node2I;
		int node1O , node2O;
		cin >> node1I >> node2I;
		node1O = node1I+MAX;
		node2O = node2I+MAX;
		c[node1O][node2I] = 1;
		c[node2O][node1I] = 1;

		E[node1O].push_back(node2I);
		E[node2I].push_back(node1O);

		E[node2O].push_back(node1I);
		E[node1I].push_back(node2O);
	}
	int total = 0;
	int s, e;
	s = 1+MAX;
	e = 2;
	while (1)
	{
		// 방문 여부
		int prev[MMAX];
		fill(prev, prev + MMAX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && prev[e] == -1)
		{
			int cur = q.front();
			q.pop();
			for (auto nx : E[cur])
			{
		  		// c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
				// prev[next] == -1: next 정점을 아직 방문하지 않았는가?
				if (c[cur][nx] - f[cur][nx] > 0 && prev[nx] == -1)
				{
					q.push(nx);
					prev[nx] = cur;
					// 마지막 노드
					if (nx == e)
						break;
				}
			}
		}
		if (prev[e] == -1)
			break;
		int flow = INF;
		// 경로상에서 가장 허용치가 낮은 곳을 찾음
		for (int i = e; i != s; i = prev[i])
		{
			int pre = prev[i];
			flow = min(flow, c[pre][i] - f[pre][i]);
		}
		// 찾은 flow만큼 해당 경로에 유량을 흘려줌
		for (int i = e; i != s; i = prev[i])
		{
			int pre = prev[i];
			f[pre][i] += flow;
			f[i][pre] -= flow;
		}
		total += flow;
	}
	cout << total;
}