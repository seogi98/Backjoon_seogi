#include<bits/stdc++.h>
using namespace std;
#define MAX 500100
vector<int> E[MAX];
int ans = 0;
void dfs(int cur,int pre,int lev){
	if(E[cur].size()==1 && cur != 1){
		ans+=lev;
		return;
	}
	for(int i=0;i<E[cur].size();i++){
		int nx = E[cur][i];
		if(nx == pre) continue;
		dfs(nx,cur,lev+1);
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N-1;i++){

		int node1 , node2;
		cin >> node1 >> node2;
		E[node1].push_back(node2);
		E[node2].push_back(node1);
	}
	dfs(1,-1,0);
	string answer="No";
	if(ans%2 == 1){
		answer = "Yes";
	}
	cout << answer;
}