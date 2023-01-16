#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
set<string> S;
map<string,int> id;
set<string> ans1;
map<string,set<string>> ans2;
map<string,vector<string>> E;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string str;
		cin >> str;
		S.insert(str);
	}
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		string node1 , node2;
		cin >> node1 >> node2;
		E[node2].push_back(node1);
		id[node1]++;
	}
	queue<string> q;
	
	for(auto i : S){
		if(id[i] == 0){
			q.push(i);
			ans1.insert(i);
		}
	}
	for(auto i  : S){
		ans2.insert({i,{}});
	}
	while(!q.empty()){
		string cur = q.front();
		q.pop();
		for(int i=0;i<E[cur].size();i++){
			string nx = E[cur][i];
			id[nx]--;
			if(id[nx] == 0){
				ans2[cur].insert(nx);
				q.push(nx);
				continue;
			}
		}
	}
	cout << ans1.size() << "\n";
	for(auto i : ans1){
		cout << i << " ";
	}
	cout << "\n";
	for(auto i : ans2){
		cout << i.first << " " << i.second.size() << " ";
		for(auto j : i.second){
			cout << j << ' ';
		}
		cout << "\n";
	}
}