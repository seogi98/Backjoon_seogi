#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 999999999999999
int T[MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pair<int,int> mx = {0,0}; // index,max
	int N;
	cin >> N;
	bool isS = false;
	for(int i=1;i<=N;i++)
	{
		int t;
		cin >> t;
		T[t]++;
	}
	for(int i=1;i<=N;i++)
	{
		if(mx.second == T[i])
		{
			isS = true;
		}
		if(mx.second < T[i])
		{
			mx.first = i;
			mx.second = T[i];
			isS = false;
		}
	}
	if(isS)
	{
		cout << "skipped";
		return 0;
	}
	cout << mx.first;
}
