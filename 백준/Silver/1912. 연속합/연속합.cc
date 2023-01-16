#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int arr[100002];
    int dp[100002];
    int ans;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    ans = arr[1];
    for(int i=2;i<=N;i++)
    {
        dp[i] = max(dp[i-1]+arr[i],arr[i]);
        if(ans < dp[i])
        {
            ans = dp[i];
        }
    } 
    cout << ans;
}