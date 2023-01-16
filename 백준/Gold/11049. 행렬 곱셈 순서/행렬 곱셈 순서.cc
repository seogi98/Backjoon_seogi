#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[501][501];
int dlm[501][2];
int arr[501][501];
int sum[501];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dlm[i][0] >> dlm[i][1];
    }
    for (int d = 1; d <= n; d++) //처음
    {
        for (int start = 1; start <= n - d; start++)
        {
            int end = start + d;
            int min = INT32_MAX;
            for (int mid = start; mid < end; mid++)
            {
                int result = dp[start][mid] + dp[mid + 1][end] + dlm[start][0] * dlm[mid][1] * dlm[end][1];

                if (result < min)
                {
                        min = result;
                }
            }
            dp[start][end]=min;
        }
    }
    cout << dp[1][n];
}
