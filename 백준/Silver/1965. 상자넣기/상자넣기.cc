#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int box[1010];
    int dp[1010];
    int mx =1;
    for (int i = 0; i < N; i++)
    {
        cin >> box[i];
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int cur = box[i];
            if(cur > box[j])
            {
                dp[i] = max(dp[j]+1,dp[i]);
                mx = max(mx,dp[i]);
            }
        }
    }
    cout << mx;
}
