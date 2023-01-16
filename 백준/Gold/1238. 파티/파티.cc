#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321
vector<pair<int, int>> E[MAX];
int dst[MAX][MAX]; //(출발지 , 도착지)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dst[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		E[node1].push_back({node2, weight});
	}
	for (int i = 1; i <= N; i++)
	{
		dst[i][i] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push({0, i}); // (weight,node)
		//거리찾기
		while (!pq.empty())
		{
			int cur = pq.top().second;
			int curWeight = -pq.top().first;
			pq.pop();
			for (int j = 0; j < E[cur].size(); j++)
			{
				int nx = E[cur][j].first;
				int nxWeight = curWeight + E[cur][j].second;
				if (nxWeight < dst[i][nx])
				{
					dst[i][nx] = nxWeight;
					pq.push({-nxWeight, nx});
				}
			}
		}
	}
	int mx  = 0;
	for(int i=1;i<=N;i++)
	{
		if(dst[i][X] == INF || dst[X][i] == INF) continue;
		mx = max(dst[i][X] + dst[X][i],mx);
	}
	cout << mx;
}