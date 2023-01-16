#include <bits/stdc++.h>
using namespace std;
#define INF (2 << 32) - 1
#define MAX 100010
int dp[MAX];
bool cmp(pair<int,int> p1, pair<int,int>  p2)
{
    if(p1.first == p2.first)
    {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    vector<pair<int, int>> sub;
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int I,T;
        cin >> I >> T;
        sub.push_back({I, T});
    }
    for (int i = 0; i < K; i++)
    {
        for (int j = N; j >= 1; j--)
        {
            if (sub[i].second <= j)
            {
                dp[j] = max(dp[j], dp[j - sub[i].second] + sub[i].first);
            }
        }
    }
    cout << dp[N];
}