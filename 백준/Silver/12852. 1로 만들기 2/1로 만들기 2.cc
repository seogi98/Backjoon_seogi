#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int dp[MAX];
int trace[MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    dp[0] = 999999999;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    cin >> N;
    trace[1] = 0;
    trace[2] = 1;
    trace[3] = 1;
    for (int i = 4; i <= N; i++)
    {
        int mn = dp[i - 1];
        trace[i] = i-1;
        if (i % 2 == 0 && mn > dp[i/2])
        {
            trace[i] = i/2;
            mn = dp[i/2];
        }
        if (i % 3 == 0 && mn > dp[i/3])
        {
            trace[i] = i/3;
            mn = dp[i/3];
        }
        dp[i] = mn + 1;
    }
    cout << dp[N] << "\n";
    int cur = N;
    while(cur>=1)
    {
        cout << cur << " ";
        cur = trace[cur];
    }
}
