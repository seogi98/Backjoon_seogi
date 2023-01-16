#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 100000
#define DIV 1000000
long long dp[MAX];
long long N;
//점화식 : dp[i] = 2*dp[i-1]+dp[i-2]
/*
[2,1][1]
[1,0][0]
*/
vector<vector<long long>> mx = {{1,1},{1,0}};
vector<vector<long long>> mulM(vector<vector<long long>> m1, vector<vector<long long>> m2)
{
    vector<vector<long long>> otm(2, vector<long long>(2, 0));
    for (long long i = 0; i < 2; i++) // 가로
    {
        for (long long j = 0; j < 2; j++) // 세로
        {
            for (long long k = 0; k < 2; k++)
            {
                otm[i][j] += (m1[i][k] * m2[k][j])%DIV;
            }
        }
    }
    return otm;
}  
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    cin >> N;
    if(N==0)
    {
        cout << 0;
        return 0;
    }
    long long curN = N-2;
    vector<vector<long long>> recA ={{1,0},{0,1}};
    while(curN>0)
    { 
        if(curN%2==1)
        {
            recA = mulM(mx,recA);
            curN--;
            continue;
        }
        mx = mulM(mx,mx);
        curN /=2;
    }
    long long result = (recA[0][0]+recA[1][0])%DIV;
    cout << result%DIV;
}