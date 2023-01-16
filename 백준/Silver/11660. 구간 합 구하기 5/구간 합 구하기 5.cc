#include <bits/stdc++.h>
using namespace std;
#define MAX 1025
#define INF 200000000000
// result = dp[y1-1][x2]+dp[y2][x1-1]-dp[y1-1][x1-1];
// dp[y][x] = dp[y-1][x] + dp[y][x-1]-dp[y-1][x-1];
int dp[MAX][MAX];
int mp[MAX][MAX];
int N, M;
void seeM()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << dp[i][j] << " ";

        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mp[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1] << "\n";
    }
}