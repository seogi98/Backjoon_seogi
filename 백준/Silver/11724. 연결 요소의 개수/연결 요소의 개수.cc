#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 1999999999
bool vst[MAX];
vector<int> E[MAX];
void dfs(int cur)
{
	if(vst[cur]) return;
	vst[cur] = true;
	for(int i=0;i<E[cur].size();i++)
	{
		dfs(E[cur][i]);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N,M;
	int ans=0;
	memset(vst,false,sizeof(vst));
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		int node1 , node2;
		cin >> node1 >> node2;
		E[node1].push_back(node2);
		E[node2].push_back(node1);
	}
	for(int i=1;i<=N;i++)
	{
		if(vst[i]) continue;
		ans++;
		dfs(i);
	}
	cout << ans;
	
}