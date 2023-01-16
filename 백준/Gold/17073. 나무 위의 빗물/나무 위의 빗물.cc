#include<bits/stdc++.h>
using namespace std;
#define MAX 500010
#define INF 2147483646
// 백준 17073번
// answer = 물/리프노드의 수
// root = 1
vector<int> E[MAX];
vector<int> T[MAX];
void mktree(int cur,int parent)
{
	for(int i=0;i<E[cur].size();i++)
	{
		int nx = E[cur][i];
		if(nx == parent)continue;
		T[cur].push_back(nx);
		mktree(nx,cur);
	}
}
int find(int cur)
{
	if(T[cur].empty()) return 1;
	int ans=0;
	for(int i=0;i<T[cur].size();i++)
	{
		int nx = T[cur][i];
		ans+=find(nx);
	}
	return ans;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	double W;
	cin >> N >> W;
	for(int i=0;i<N-1;i++)
	{
		int node1 , node2;
		cin >> node1 >> node2;
		E[node1].push_back(node2);
		E[node2].push_back(node1);
	}
	mktree(1,-1);
	double ans = find(1);
	cout.precision(6); 
	cout << fixed << (double)W/ans << endl; 
}