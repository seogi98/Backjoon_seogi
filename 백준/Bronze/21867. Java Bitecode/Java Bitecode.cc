#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
set<char> S = {'J','V','A'};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string str;
	cin >> str;
	string ans = "";
	for(auto i : str){
		if(S.count(i)){
			continue;
		}
		ans.push_back(i);
	}
	if(ans.empty()){
		ans = "nojava";
	}
	cout << ans;
}
