#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 99999999
char mp[MAX][MAX];
int vst[MAX][MAX][11][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct CUR
{
	int dst;
	int block;
	bool day;
	int y;
	int x;
};

//main 함수
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	int ans = -1;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> mp[i][j];
			for(int k=0;k<11;k++)
			{
				for(int q=0;q<2;q++)
				{
						vst[i][j][k][q] = INF;
				}
			}
		}
	}
	// 거리 , 벽 , Y , X , true : 낮 , false : 밤
	queue<CUR> q;
	vst[0][0][0][true] = 1;
	q.push({1, 0, true, 0, 0});
	while (!q.empty())
	{
		int curD = q.front().dst;
		int curB = q.front().block;
		bool day = q.front().day;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		if (curB > K)
		{
			continue;
		}
		if (x == M - 1 && y == N - 1)
		{
			ans = curD;
			break;
		}
		//한나절 기다렸다 갈 경우
		if (vst[y][x][curB][!day] > curD)
		{
			vst[y][x][curB][!day] = curD;
			q.push({curD + 1, curB, !day, y, x});
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nxD = curD+1;
			bool nxday = !day;
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (vst[ny][nx][curB][nxday]<=nxD)
				continue;
			vst[ny][nx][curB][nxday] = nxD;
			if (mp[ny][nx] == '1')
			{
				if (day)
				{
					q.push({curD + 1, curB + 1, nxday, ny, nx});
				}
			}
			if (mp[ny][nx] == '0')
			{
				q.push({curD + 1, curB, nxday, ny, nx});
			}
		}
	}
	cout << ans;
}
