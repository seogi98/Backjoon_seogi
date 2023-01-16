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

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[200][200]; // from to
    int N;
    int E;
    cin >> N >> E;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        if(dp[node1][node2] > weight)
        {
            dp[node1][node2] = weight;
        }
    }
    for (int i = 1; i <= N; i++) //  vertex i를 거치는 경우
    {
        for (int j = 1; j <= N; j++)  // j부터 시작해서
        {
            for (int k = 1; k <= N; k++) // k로 간다.
            {
                if(dp[j][i]!=INF || dp[i][k] !=INF)
                {
                    dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j||dp[i][j]==INF)
            {
                cout << 0 << " ";
                continue;
            }
            cout  << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
