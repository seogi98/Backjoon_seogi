// 2623번 음악프로그램
#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 1999999999
vector<int> E[MAX];
int P[MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> answer;
	int N , M;
	cin >> N >> M;
	for(int i=1;i<=M;i++)
	{
		int T,pre;
		cin >> T >> pre;
		for(int j=1;j<T;j++)
		{
			int cur;
			cin >> cur;
			E[pre].push_back(cur);
			pre = cur;
			P[cur]++;
		}
	}
	queue<int> q;
	int start=-1;
	for(int i=1;i<=N;i++)
	{
		if(P[i] == 0)
		{
			q.push(i);
			start = i;
		}
	}
	// 진입 차수가 0인경우가 없는경우
	if(start == -1)
	{
		cout << 0;
		return 0;
	}
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		answer.push_back(cur);
		for(int i=E[cur].size()-1;i>=0;i--)
		{
			//다음 노드 인접 차수 줄여주고 노드 pop
			int nx = E[cur][i];
			P[nx]--;
			E[cur].pop_back();
			if(P[nx]==0)
			{
				q.push(nx);
			}
		}
	}
	if(answer.size() !=N)
	{
		cout << 0;
		return 0;
	}
	for(int i=0;i<answer.size();i++)
	{
		cout << answer[i] << "\n";
	}
}