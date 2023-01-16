#include <bits/stdc++.h>
using namespace std;
#define MAX 11
// BFS 방문 표시
map<vector<int>,bool> vst;
vector<int> E[MAX];
int N, K;
bool checkSame(vector<int> V)
{
	int pre = V[1];
	for (int i = 1; i <= N; i++)
	{
		if (pre != V[i])
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> V(11, 0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> V[i];
	}
	for (int i = 1; i <= K; i++)
	{
		int node1;
		cin >> node1;
		for (int j = 0; j < node1; j++)
		{
			int node2;
			cin >> node2;
			E[i].push_back(node2);
		}
	}
	int ans = -1;
	queue<pair<vector<int>, int>> q;
	q.push({V, 0});
	while (!q.empty())
	{
		vector<int> cur = q.front().first;
		int curN = q.front().second;
		q.pop();
		if (checkSame(cur))
		{
			ans = curN;
			break;
		}
		for (int i = 1; i <= K; i++)
		{
			//다음 배열
			vector<int> nx = cur;
			for(int j=0;j<E[i].size();j++)
			{
				nx[E[i][j]] = (nx[E[i][j]]+i)%5;
			}
			if(vst[nx]) continue;
			vst[nx] = true;
			q.push({nx,curN+1});
		}
	}
	cout << ans;
}