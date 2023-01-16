#include<bits/stdc++.h>
#define MAX 2001
using namespace std;

// 시간 , 움직인 횟수, 위치
int dp[MAX][40][2];
// 만약에 움직였을 경우
// dp[i][j][1] = dp[i-1][j-1][2] 같으면 +1

// 가만히 있을경우
// dp[i][j][1] = dp[i-1][j][1] 같으면 +1
bool arr[MAX][2];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T,W;
    cin >> T >> W;
    for(int i=1;i<=T;i++)
    {
        int t;
        cin >> t;
        t--;
        arr[i][t] = true;
    }

    dp[1][1][1] = arr[1][1];
    dp[1][0][0] = arr[1][0];
    for(int i=2;i<=T;i++)
    {
        for(int j=0;j<=W;j++)
        {
            for(int pos=0;pos<=1;pos++)
            {
                if(j==0)
                {
                    dp[i][j][pos] = dp[i-1][j][pos]+arr[i][pos];
                    continue;
                }
                // 움직일 경우
                dp[i][j][pos] = max(dp[i-1][j-1][!pos], dp[i-1][j][pos])+arr[i][pos];
            }
        }
    }
    int mx = 0;
    for(int i=0;i<=W;i++)
    {
        if(W == 0)
        {
            mx = dp[T][0][0];
            break;
        }
        mx = max(max(mx,dp[T][i][1]),dp[T][i][0]);
    }

    cout << mx;
}
