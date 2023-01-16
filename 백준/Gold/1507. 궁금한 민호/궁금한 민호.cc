#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 40000
#define INF 10000001
using namespace std;
//dp[i][j]가 다른 거처가는 간선의 합과 같으면 간선을 false로 해둔다.
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int dp[21][21];
    int dpT[21][21];
    cin >> N;
    bool map[21][21];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int data;
            cin >> data;
            dp[i][j] = data;
            dpT[i][j] = data;

        }
    }
    for(int i=1;i<=N;i++) // 거처가는 간선 i
    {
        for(int j=1;j<=N;j++) // node1
        {
            for(int k=1;k<=N;k++) // node2
            {
                if(j==k || j ==i || k == i)
                {
                    continue;
                }
                if(dp[j][k] == dp[j][i] + dp[i][k])
                {
                    dpT[j][k] = 0;
                }
                else if(dp[j][k] > dp[j][i] + dp[i][k])
                {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    int result=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            result+=dpT[i][j];
        }
    }
    cout << result/2;
}
