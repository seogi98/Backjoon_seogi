#include<bits/stdc++.h>
using namespace std;
#define MAX 200000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	string S;
	cin >> N >> S;
	vector<pair<string,string>> V;
	string answer = "";
	for(int i=0;i<N;i++)
	{
		string node1 , node2;
		cin >> node1 >> node2;
		if(node1 == S) {
			answer = node2;
			break;
		}
		V.push_back({node1,node2});
	}
	int sz = V.size();
	int ans=0;
	for(int i=0;i<sz;i++)
	{
		if(answer == V[i].second)
		{
			ans ++;
		}
	}
	cout << ans;
}