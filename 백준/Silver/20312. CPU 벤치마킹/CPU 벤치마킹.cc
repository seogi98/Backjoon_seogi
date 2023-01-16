#include <bits/stdc++.h>
using namespace std;
//dp[i] = dp[i-1]*arr[i]+arr[i]
#define MAX 500001
#define DIV 1000000007
typedef long long ll;
ll arr[MAX];
ll dp[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    ll answer=0;
    cin >> N;
    for (ll i = 1; i < N; i++)
    {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    answer+=dp[1];
    for (ll i = 2; i < N; i++)
    {
        dp[i] = ((dp[i - 1] * arr[i]) + arr[i]) % DIV;
        answer +=dp[i]%DIV;
    }
    cout << answer%DIV;
}
