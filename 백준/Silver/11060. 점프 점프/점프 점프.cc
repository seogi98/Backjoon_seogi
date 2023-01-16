#include <bits/stdc++.h>
using namespace std;
#define MAX 3001
#define INF 99999999
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[MAX];
    int dp[MAX];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = INF;
    }
    dp[1] = 0;
    for(int i=1;i<=N;i++)
    {
        int cur = arr[i];
        for(int j=0;j<=cur;j++)
        {
            int nx = i+j;
            dp[nx] = min(dp[i]+1,dp[nx]);
        }
    }
    if(dp[N] == INF)
    {
        dp[N] = -1;
    }
    cout << dp[N];
}