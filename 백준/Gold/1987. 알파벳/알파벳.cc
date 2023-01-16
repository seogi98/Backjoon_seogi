#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 299999
bool S[100];
char M[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
int mx = 0;
void dfs(pair<int, int> P, int len)
{
	int y = P.first;
	int x = P.second;
	mx = max(len,mx);
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || nx >= c || ny < 0 || ny >= r)
			continue;
		int nC = M[ny][nx];
		// 이미 지나왔을경우
		if(S[nC]) continue;
		S[nC] = true;
		dfs({ny,nx},len+1);
		S[nC] = false;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> M[i][j];
		}
	}
	S[M[0][0]] = true;
	dfs({0,0},1);
	cout << mx;
}