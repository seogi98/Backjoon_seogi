#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define div 1000000003;
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int K;
    cin >> N >> K;
    //DP[N][K]는 N개짜리중 K개를 인접하지 않게 칠하는 경우의수
    //N번째 색을 고르면 N - 2개 중에 K-1개를 고르는 경우와 같고
    //N번째 색을 고르지 않으면 N - 1개 중에 K개를 고르는 경우와 같다
    //따라서 DP[N][K] = Dp[N-2][K-1]+dp[N-1][j]; (선형일 경우)
    int result=0;
    int dp[1001][1001];
    for(int i=0;i<N;i++)
    {
        //하나도 고르지 않을 경우
        dp[i][0] = 1;
        //하나만 고를경우
        dp[i][1] =i;
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<=N;j++)
        {
            dp[i][j] = (dp[i-2][j-1]+dp[i-1][j])%div;
        }
    }
    //1. N번째 칸을 칠하는 경우 -> 2~N-2까지 칠할수 있으므로 N-3 에서 K-1
    //2. N번째 칸을 칠하지 않는 경우 -> 1 ~ N-1 까지 칸을 K개 칠합
    cout << (dp[N-3][K-1]+dp[N-1][K])%div

}