#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
char mp[MAX][MAX];
bool vst[MAX][MAX][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	int ans = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> mp[i][j];
		}
	}
	priority_queue<pair<pair<int, int>, pair<int, int>>> pq; // (벽,(y,x))
	pq.push({{-1, 0}, {0, 0}});
	while (!pq.empty())
	{
		int curD = -pq.top().first.first;
		int curB = -pq.top().first.second;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if(curB >=2)
		{
			continue;
		}
		if (x == M - 1 && y == N - 1)
		{
			ans = curD;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (vst[ny][nx][curB])
				continue;
			if (mp[ny][nx] == '1' && curB >= 1)
				continue;
			vst[ny][nx][curB] = true;
			if (mp[ny][nx] == '1' && curB == 0)
			{
				pq.push({{-(curD + 1), -(curB + 1)}, {ny, nx}});
			}
			if (mp[ny][nx] == '0')
			{
				pq.push({{-(curD + 1), -(curB)}, {ny, nx}});
			}
		}
	}
	cout << ans;
}
