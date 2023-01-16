#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <stack>

#define MAX 10001
using namespace std;
int dp[20][20][3]; //세로 가로 바라보는 방향
int N;
// 0 = 가로     1 = 세로       2 = 대각선

//가로는 i,j-1위치에서 온다. dp[i][j][0] = dp[i][j-1][0]+dp[i][j-1][2]
//i,j-1이 벽일경우 0
//세로는 i-1,j위치에서 온다. dp[i][j][1] = dp[i-1][j][1]+dp[i-1][j][2]
//i-1,j가 벽일경우 0
//대각선은 i-1,j-1위치에서 온다. dp[i][j][2] = dp[i-1][j-1][0]+dp[i-1][j-1][0]+dp[i-1][j-1][0]
//3방향중에 하나가 벽일경우 0
int map[19][19];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][2][0] = 1; //가로
    dp[1][2][1] = 0; //세로
    dp[1][2][2] = 0; //대각선
    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            if(map[i][j] ==1)
            {
                continue;
            }
            if (i == 1 &&  j == 2)
            {
                continue;
            }
            //가로 
            if (map[i][j - 1] == 1)
            {
                dp[i][j][0] = 0;
            }
            else
            {
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            }
            //세로
            if (map[i - 1][j] == 1)
            {
                dp[i][j][1] = 0;
            }
            else
            {
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            }
            //대각선
            if (map[i][j - 1] == 1 || map[i - 1][j] == 1 || map[i - 1][j - 1] == 1)
            {
                dp[i][j][2] = 0;
            }
            else
            {
                dp[i][j][2] = dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
            }
        }
    }
    //seemap();
    cout << dp[N][N][0]+dp[N][N][1]+dp[N][N][2];
}