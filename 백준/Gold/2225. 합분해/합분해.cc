#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 40000
using namespace std;
int N;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    long long dp[201][201]; // N,K;
    cin >> N >> K;
    //dp[i][j] = dp[i-1][j]+dp[i][j-1];
    for(int i=1;i<=K;i++)
    {
        dp[1][i] = i;
    }
    for(int i=1;i<=N;i++)
    {
        dp[i][1] = 1;
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<=K;j++)
        {
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%1000000000;
        }
    }
    cout << dp[N][K]%1000000000;
}
 