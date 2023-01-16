#include<bits/stdc++.h>
using namespace std;
#define MAX 500100
vector<int> E[MAX];
int arrw[MAX];
map<int,int> tmp;
int root = -1;
int ans = 0;
void dfs(int cur,int w){
	arrw[cur]+=w;
	if(E[cur].empty()){
		return;
	}
	for(auto nx : E[cur]){
		dfs(nx,w);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int node;
		cin >> node;
		if(node == -1){
			root = node;
		}
		E[node].push_back(i);
	}
	for(int i=0;i<m;i++)
	{
		int node,w;
		cin >> node >> w;
		tmp[node] += w;
	}
	for(auto i : tmp){
		dfs(i.first,i.second);
	}
	for(int i=1;i<=n;i++){
		cout << arrw[i] << " ";
	}

}