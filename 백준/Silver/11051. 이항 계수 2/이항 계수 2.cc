#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define DIV 10007
typedef long long ll;
int dp[MAX][MAX];
// dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        dp[i][1] = i;
        dp[i][i] = 1;
        dp[i][0] = 1;
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<N;j++)
        {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            dp[i][j] %= DIV;
        }
    }
    cout << dp[N][K]%DIV;
    
}
