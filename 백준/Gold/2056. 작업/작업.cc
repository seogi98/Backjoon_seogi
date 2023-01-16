#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 10010
// 위상정렬 문제
// input이 없을경우 queue삽입
// queue에서 빠져나오면서 최대값 저장
int P[MAX];
int L[MAX];
vector<int> E[MAX];
queue<pair<int,int>> q; // cur , len
int dst[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(P,0,sizeof(P));
	memset(dst,0,sizeof(dst));
	int N;
	int ans=0;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		int T;
		cin >> T;
		L[i] = T;
		int k;
		cin >> k;
		P[i] = k;
		for(int j=0;j<k;j++)
		{
			int pre;
			cin >> pre;
			E[pre].push_back(i);
		}
	}
	for(int i=1;i<=N;i++)
	{
		//진입노드가 없을경우
		dst[i] = L[i]; 
		if(!P[i])
		{
			q.push({i,L[i]});
		}
	}
	while(!q.empty())
	{
		int cur = q.front().first;
		int len = q.front().second;
		q.pop();
		for(int i=0;i<E[cur].size();i++)
		{
			int nx = E[cur][i];
			dst[nx] = max(dst[nx],len+L[nx]);
			P[nx]--;
			if(!P[nx])
			{
				q.push({nx,dst[nx]});
			}
		}
	} 
	for(int i=1;i<=N;i++)
	{
		ans = max(ans,dst[i]);
	}
	cout << ans;
}
