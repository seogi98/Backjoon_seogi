#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 999999999999999
vector<int> V;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int ans=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		V.push_back(t);
	}
	sort(V.begin(), V.end());
	int fr, bk;
	fr = 0;
	bk = N - 1;
	while(fr<=bk)
	{
		if(fr == bk)
		{
			ans += V[bk];
			break;
		}
		ans +=V[bk]*2;
		bk--;
		fr++;
	}
	cout << ans;
}
