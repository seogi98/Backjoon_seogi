#include <bits/stdc++.h>
using namespace std;
#define MAX 101
int mp[MAX][MAX];
int mpF[MAX][MAX];

bool isP(int n)
{
	return n > 0;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	pair<int, int> P[4];
	vector<int> input;
	string ans = "Lucky";
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 4; i++)
	{
		int t;
		cin >> t;
		input.push_back(t);
	}
	P[0] = {input[0],input[2]};
	P[1] = {input[1],input[3]};
	P[2] = {input[0],input[3]};
	P[3] = {input[1],input[2]};
	vector<bool> V;
	for (int i = 0; i < 4; i++)
	{
		int curR = a * P[i].first + b * P[i].second + c;
		if (curR == 0)
			continue;
		V.push_back(isP(curR));
	}
	bool pre = V.front();
	for(int i=0;i<V.size();i++)
	{
		if(pre^V[i])
		{
			ans = "Poor";	
		}
	}
	cout << ans;
}