#include <bits/stdc++.h>
using namespace std;
#define MAX 2011
#define INF 1987654321
typedef long long ll;
vector<pair<ll,ll>> P;
priority_queue<pair<ll,pair<ll,ll>>> dst;
ll par[MAX];
ll cal(pair<ll,ll> p1,pair<ll,ll> p2)
{
    ll out = (p1.first - p2.first)*(p1.first - p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
    return out;
}
ll unionFind(ll cur)
{
    if(cur == par[cur])
    {
        return cur;
    }
    return par[cur] = unionFind(par[cur]);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,C;
    cin >> N >> C;
    for(ll i=0;i<N;i++)
    {
        ll x,y;
        cin >> x >> y;
        P.push_back({x,y});
        par[i] = i;
    }
    for(ll i=0;i<N;i++)
    {
        for(ll j=i+1;j<N;j++)
        {
            ll tmp = cal(P[i],P[j]);
            if(tmp <C) continue;
            dst.push({-tmp,{i,j}});
        }
    }
    ll ans=0;
    while(!dst.empty())
    {
        ll node1 = dst.top().second.first;
        ll node2 = dst.top().second.second;
        ll curW = -dst.top().first;
        dst.pop();
        ll node1P = unionFind(node1);
        ll node2P = unionFind(node2);
        if(node1P == node2P) continue;
        ans+=curW;
        par[node1P] = node2P;
        unionFind(node1);
    }
    ll tmp = par[0];
    for(ll i=0;i<N;i++)
    {
        if(tmp != par[i])
        {
            ans = -1;
            break;
        }
    }
    cout << ans;
}
