#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    long long dp[10][1001]={0,};
    for(int i=0;i<10;i++)
    {
        dp[i][0] = 1;
    }
    cin >> N;

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<=j;k++)
            {
                dp[j][i] += dp[k][i-1]%10007;
            }
        }
    }
    int result=0;
    for(int i=0;i<10;i++)
    {
        result+=dp[i][N-1]%10007;
    }
    cout << result%10007;

}