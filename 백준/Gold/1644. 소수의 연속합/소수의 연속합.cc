#include <bits/stdc++.h>
using namespace std;
#define MAX 4010000
#define DIV 10007
#define INF 19876543211
typedef long long ll;
int prime[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> V;

    for (int i = 2; i <= N; i++)
    {
        if (prime[i] == false)
        {
            for (int j = i * 2; j <= N; j += i)
            {
                prime[j] = true;
            }
        }
    }
    for (ll i = 2; i <= N; i++)
    {
        if (!prime[i])
            V.push_back(i);
    }
    ll begin = 0;
    ll end = 0;
    ll ans = 0;
    ll sum = 2;
    ll len = V.size()-1;
    while (end <= len) 
    {
        if (sum == N)
        {
            ans++;
        }
        if (sum >= N)
        {
            sum -= V[begin];
            begin++;
            continue;
        }
        if (sum < N && end<=len)
        {
            end++;
            sum += V[end];
            continue;
        }
    }
    cout << ans;
}
