#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 99999999
//세로 , 가로 , 턴
int N,M,R;
map<char,int> dirM = {{'E',0},{'S',1},{'W',2},{'N',3}};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
// 높이 , 안 넘어짐
pair<int,bool> mp[MAX][MAX];
int ans =0;
//Y,X,D
void attackDomino()
{
	pair<int,int> P={0,0};
	char D;
	cin >> P.first >> P.second;
	cin >> D;
	queue<pair<int,int>> q;
	q.push({P});
	int dir = dirM[D];
	while(!q.empty())
	{
		int Y = q.front().first;
		int X = q.front().second;
		int len = mp[Y][X].first;
		q.pop();
		if(!mp[Y][X].second) continue;
		mp[Y][X].second = false;
		ans++;
		for(int i=len-1;i>=1;i--)
		{
			int nx = X + dx[dir]*i;
			int ny = Y + dy[dir]*i;
			if(ny <=0 || ny > N || nx <=0 || nx>N) continue;
			if(!mp[ny][nx].second) continue;
			q.push({ny,nx});
		}
	}
}
void defendDomino()
{
	pair<int,int> P;
	cin >> P.first >> P.second;
	mp[P.first][P.second].second = true;
}
void seeM()
{
	cout << ans <<"\n";
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			mp[i][j].second?cout << "S ":cout << "F ";
		}
		cout << "\n";
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> R;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin >> mp[i][j].first;
			mp[i][j].second = true;
		}
	}
	while(R--)
	{
		attackDomino();
		//seeM();
		defendDomino();
		//seeM();
	}
	seeM();
}
