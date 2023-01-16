#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 999999999999999
char mp[MAX][MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string ans = "YES";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> mp[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(mp[i][j] != mp[j][i])
			{
				ans = "NO";
			}
		}
	}
	cout << ans;
}
