#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500
int mp[MAX][MAX];
bool vst[MAX][MAX];
struct pos
{
	int x;
	int y;
	int f;
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		bool insung = false;
		int H, W, O, F, sx, sy, ex, ey;
		cin >> H >> W >> O >> F >> sx >> sy >> ex >> ey;
		memset(mp, 0, sizeof(mp));
		memset(vst, false, sizeof(vst));
		for (int i = 0; i < O; i++)
		{
			int x, y, l;
			cin >> x >> y >> l;
			mp[y][x] = l;
		}
		queue<pos> q;
		q.push({sx, sy, F});
		vst[sy][sx] =true;
		while (!q.empty())
		{
			pos cur = q.front();
			q.pop();
			int curP = mp[cur.y][cur.x];
			if (cur.x == ex && cur.y == ey)
			{
				cout << "잘했어!!\n";
				insung = true;
				break;
			}
			if (cur.f <= 0)
				continue;
			for (int i = 0; i < 4; i++)
			{
				pos nt;
				nt.x = cur.x + dx[i];
				nt.y = cur.y + dy[i];
				nt.f = cur.f - 1;
				int ntP = mp[nt.y][nt.x];
				int diff = ntP - curP;
				if (nt.x <= 0 || nt.x > H || nt.y <= 0 || nt.y > W)
					continue;
				if (diff > 0 && cur.f < diff)
					continue;
				if (vst[nt.y][nt.x])
					continue;
				if (nt.f < 0)
					continue;
				vst[nt.y][nt.x] = true;
				q.push(nt);
			}
		}
		if(insung) continue;
		cout << "인성 문제있어??\n";
	}
}
