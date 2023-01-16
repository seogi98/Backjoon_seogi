#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
#define INF 10000001
// 치삼 = 현재 위치, 현재 날짜
// 갈수있는 노드 확인 => 1000개 거리 확인 10억? ㄴ
// 수원지에서 고양이까지 거리는 (xy의 합)의 차로 구할 수 잇다.
// upperbound , +1 두 노드 확인 사이 차 의 최소값 구함
// 갈 수 있는 노드인지 판단 가능
// 고양이가 건너 갈 수 있을 시간은
// 차이만큼 time을 더하여 이동 가능하다.

char mp[MAX][MAX];
vector<int> V;
int N, W;
struct Node
{
	int y;
	int x;
	// 시간
	int t;
	bool operator()(Node n1, Node n2)
	{
		return n1.t > n2.t;
	}
};
bool isOut(int y, int x)
{
	if (y <= 0 || y > N || x <= 0 || x > N)
	{
		return true;
	}
	if (mp[y][x] == '0')
	{
		return true;
	}
	return false;
}
// 우쪽 부터 시계방향
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ddx[4] = {1,0,-1,0};
int ddy[4] = {0,1,0,-1};
int dst[MAX][MAX];
bool vst[MAX][MAX];
int diffFromW[MAX][MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> W;
	queue<Node> q;
	vector<pair<int,int>> V;
	for (int i = 0; i < W; i++)
	{
		int y, x;
		cin >> y >> x;
		q.push({y,x,0});
		V.push_back({y,x});
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> mp[i][j];
			dst[i][j] = INF;
			diffFromW[i][j] = INF;
		}
	}
	for(auto i : V){
		diffFromW[i.first][i.second] = 0;
	}
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx = cur.x+ddx[i];
			int ny = cur.y+ddy[i];
			int nxT = cur.t+1;
			if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
			if(diffFromW[ny][nx] > nxT){
				diffFromW[ny][nx] = nxT;
				q.push({ny,nx,nxT});
			}
		}
	}
	dst[1][1] = 0;
	priority_queue<Node, vector<Node>, Node> pq;
	pq.push({1, 1, 0});
	int ans = -1;
	while (!pq.empty())
	{
		Node cur = pq.top();
		if ((cur.y == N - 1 && cur.x == N - 1) ||(cur.y == N - 1 && cur.x == N) ||(cur.y == N && cur.x == N - 1))
		{
			ans = cur.t;
			break;
		}
		if (dst[cur.y][cur.x] < cur.t)
		{
			continue;
		}
		pq.pop();
		for (int i = 0; i < 8; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (isOut(ny, nx))
				continue;
			int diff = diffFromW[ny][nx];
			int nxTime = cur.t;
			if (cur.t < diff)
			{
				nxTime += diff - cur.t;
			}
			if (dst[ny][nx] > nxTime)
			{
				dst[ny][nx] = nxTime;
				pq.push({ny, nx, nxTime});
			}
		}
	}
	cout << ans << "\n";
}