#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define MAXX 201
typedef long long ll;
ll ans = 0;
struct pnt
{
    ll y;
    ll x;
};
vector<pnt> P;
ll ccw(pnt p1, pnt p2, pnt p3)
{
    ll a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    ll b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return a - b;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        pnt tmp;
        cin >> tmp.x >> tmp.y;
        P.push_back(tmp);
    }
    double ans = 0;
    pnt start = P[0];
    for (ll i = 1; i < P.size() - 1; i++)
    {
        ans += ccw(start, P[i], P[i + 1]);
    }
    ans = fabs(ans)/2;
    cout << fixed;
    cout.precision(1);
    cout << ans;
}