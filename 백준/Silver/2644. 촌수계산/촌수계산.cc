#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int> E[MAX];
int vst[MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int s,e;
	cin >> n >> s >> e;
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int node1 , node2;
		cin >> node1 >> node2;
		E[node1].push_back(node2);
		E[node2].push_back(node1);
	}
	queue<pair<int,int>> q;
	int ans=-1;
	q.push({s,0});
	while(!q.empty())
	{
		int cur = q.front().first;
		int curn = q.front().second;
		q.pop();
		if(cur == e) {
			ans = curn;
			break;
		}
		for(int i=0;i<E[cur].size();i++){
			int nx = E[cur][i];
			if(vst[nx]) continue;
			vst[nx] = true;
			q.push({nx,curn+1});
		}
	}
	cout << ans;

}