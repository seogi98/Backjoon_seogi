#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int dp[32][32]; // dp[N][M]; N->M으로 갈때 경우의 수
    int T;
    for(int i=1;i<=30;i++)
    {
        dp[i][i] = 1;
        dp[1][i] = i;
    }
    for(int i=2;i<=30;i++)
    {
        for(int j=i+1;j<=30;j++)
        {
            dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
        }
    }
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int A,B;
        cin >> A >> B;
        cout << dp[A][B] << "\n";
    }
}