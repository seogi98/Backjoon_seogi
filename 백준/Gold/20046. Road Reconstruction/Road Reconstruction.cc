// 백준 20046번 Road Reconstruction
// bfs 탐색문제
// 0,0 -> N,N탐색
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321
int mp[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// pq로 접근하기때문에 먼저 방문하면 그뒤에 방문할 필요가 없다.
bool vst[MAX][MAX];
int N, M;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(vst,false,sizeof(vst));
	int ans=-1;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> mp[i][j];
		}
	}
	if(mp[0][0]==-1)
	{
		cout << -1;
		return 0;
	}
	priority_queue<pair<int, pair<int, int>>> pq; // (건설 비용,(Y,X))
	pq.push({-mp[0][0], {0, 0}});
	vst[0][0] = true;
	while (!pq.empty())
	{
		int Y = pq.top().second.first;
		int X = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		if(Y == M-1 && X == N-1)
		{
			ans = cost;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || mp[ny][nx] == -1)
			{
				continue;
			}
			if(vst[ny][nx]) continue;
			vst[ny][nx] = true;
			pq.push({-(cost+mp[ny][nx]),{ny,nx}});
		}
	}
	cout << ans;
}