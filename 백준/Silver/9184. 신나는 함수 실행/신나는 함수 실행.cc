#include <bits/stdc++.h>
using namespace std;
#define MAX 51
typedef long long ll;
ll dp[51][51][51];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (ll i = 0; i <= 20; i++)
    {
        for (ll j = 0; j <= 20; j++)
        {
            for (ll k = 0; k <= 20; k++)
            {
                if (i <= 0 || j <= 0 || k <= 0)
                {
                    dp[i][j][k] = 1;
                    continue;
                }
                if (i < k && j < k)
                {
                    dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                    continue;
                }
                dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
            }
        }
    }
    while (1)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        ll ans = 0;
        if (a <= 0 || b <= 0 || c <= 0)
            ans = 1;
        else if (a > 20 || b > 20 || c > 20)
            ans = dp[20][20][20];
        else
            ans = dp[a][b][c];
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
    }
}