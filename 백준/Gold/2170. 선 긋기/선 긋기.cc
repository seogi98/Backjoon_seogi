#include <bits/stdc++.h>
using namespace std;
#define MAX 1025
#define INF 1000000001
typedef long long ll;
priority_queue<pair<ll, ll>> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        ll L, R;
        cin >> L >> R;
        pq.push({-L, -R});
    }
    pair<ll, ll> P = {-INF, -INF};
    ll result = 0;
    while (!pq.empty())
    {
        ll L = -pq.top().first;
        ll R = -pq.top().second;
        pq.pop();
        if (P.second < L)
        {
            result += P.second - P.first;
            P.first = L;
            P.second = R;
            continue;
        }
        if (P.second < R)
        {
            P.second = R;
        }
    }
    result += P.second - P.first;
    cout << result;
}