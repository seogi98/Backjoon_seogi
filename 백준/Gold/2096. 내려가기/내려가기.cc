#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <stack>
#define MAX 100001
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int dp[MAX][3]; // 왼쪽 중간 오른족;
    short map[MAX][3];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }
    dp[0][0] = map[0][0];
    dp[0][1] = map[0][1];
    dp[0][2] = map[0][2];
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + map[i][0];
        dp[i][1] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + map[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + map[i][2];
    }
    cout << max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]) << " ";
    dp[0][0] = map[0][0];
    dp[0][1] = map[0][1];
    dp[0][2] = map[0][2];
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + map[i][0];
        dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + map[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][2];
    }
    cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
}