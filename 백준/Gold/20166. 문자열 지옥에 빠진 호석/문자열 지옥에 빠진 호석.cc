#include <bits/stdc++.h>
using namespace std;
#define MAX 11
#define INF 99999999
//문자열 수
map<string, int> strN;
char mp[MAX][MAX];
int N, M, K;
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
pair<int, int> fixP(pair<int, int> P)
{
	int x = P.second;
	int y = P.first;
	if (x < 0)
		x = M - 1;
	if (y < 0)
		y = N - 1;
	if (x >= M)
		x = 0;
	if (y >= N)
		y = 0;
	return {y,x};
}
string sum;
void dfs(pair<int, int> P)
{
	strN[sum]++;
	if (sum.size() >= 5)
	{
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		pair<int,int> nP = {P.first + dy[i],P.second + dx[i]};
		int ny = nP.first;
		int nx = nP.second;
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
		{
			nP = fixP(nP);
		}
		sum.push_back(mp[nP.first][nP.second]);
		dfs(nP);
		sum.pop_back();
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> mp[i][j];
		}
	}
	string tmp="";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			sum.push_back(mp[i][j]);
			dfs({i,j});
			sum.pop_back();
		}
	}
	for(int i=0;i<K;i++)
	{
		string tmp;
		cin >> tmp;
		cout << strN[tmp] << "\n";
	}
}
