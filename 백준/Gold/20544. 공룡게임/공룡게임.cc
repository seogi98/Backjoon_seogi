#include <bits/stdc++.h>
#define MAX 2000
#define DIV 1000000007
typedef long long ll;
using namespace std;
ll dp[MAX][3][3][2];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // [맵][연속된 장애물][장애물 크기][장애물 2 유무]
    ll N;
    cin >> N;
    dp[2][0][0][0] = 1;
    dp[2][1][1][0] = 1;
    dp[2][1][2][1] = 1;
    for (ll i = 3; i <= N; i++)
    {
        // 현재 장애물이 없는경우 모든 경우에서 올 수 있다.
        for (ll j = 0; j <= 2; j++)
        {
            for (ll k = 0; k < 3; k++)
            {
                for (ll q = 0; q < 2; q++)
                {

                    dp[i][0][0][q] += dp[i - 1][j][k][q];
                    dp[i][0][0][q] %= DIV;
                }
            }
        }
        // 장애물이 1인경우
        // -> 전에 장애물이 2개 있는 경우 올 수 없다.
        for (ll j = 1; j <= 2; j++)
        {
            for (ll k = 0; k < 3; k++)
            {
                for (ll q = 0; q < 2; q++)
                {
                    dp[i][j][1][q] += dp[i - 1][j - 1][k][q];
                    dp[i][j][1][q] %= DIV;
                }
            }
        }

        // 장애물이 2인경우
        // -> 전에 장애물이 2개 또는 높이가 2인 장애물이 있을경우 올 수 없다.
        for (ll j = 1; j <= 2; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                for (ll q = 0; q < 2; q++)
                {
                    dp[i][j][2][1] += dp[i - 1][j - 1][k][q];
                    dp[i][j][2][1] %= DIV;
                }
            }
        }
    }
    ll ans = 0;
    // 현재 장애물이 없는경우 모든 경우에서 올 수 있다.
    for (ll j = 0; j <= 2; j++)
    {
        for (ll k = 0; k < 3; k++)
        {
            ans += dp[N][j][k][1];
            ans %= DIV;
        }
    }
    cout << ans % DIV;
}
