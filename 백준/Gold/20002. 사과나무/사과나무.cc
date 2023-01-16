#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 300
#define INF 2099999999
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dp[MAX][MAX][MAX];// (Y,X,size)
//dp[i][j][k] = dp[i-1][j][k-1]+dp[i][j-1][k-1]-dp[i-1][j-1][k-2]+arr[i][j] +arr[i-k][j-k]
int arr[MAX][MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	memset(arr,0,sizeof(arr));
	int mx =-INF;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin >> arr[i][j];
			dp[i][j][1] = arr[i][j];
			mx = max(mx,arr[i][j]); 
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			int mn = min(i,j);
			for(int k=2;k<=mn;k++)
			{
				int sum=0;
				sum = dp[i-1][j][k-1]+dp[i][j-1][k-1]+arr[i][j] +arr[i-k+1][j-k+1];
				if(k >= 3)
				{
					sum-=dp[i-1][j-1][k-2];
				}
				dp[i][j][k] = sum;
				mx = max(mx,sum);
			}
		}
	}
	cout << mx;
}	
