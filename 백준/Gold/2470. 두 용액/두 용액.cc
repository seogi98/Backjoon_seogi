#include <bits/stdc++.h>
using namespace std;
#define MAX 101000
#define DIV 10007
#define INF 19876543211
typedef long long ll;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> V;
    for(ll i=0;i<N;i++)
    {
        ll t;
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(),V.end());
    ll begin = 0;
    ll end = V.size()-1;
    pair<ll,ll> ans;
    ll mn = INF;
    while(begin < end)
    {
        ll sumA = abs(V[begin] + V[end]);
        ll sum = V[begin] + V[end];
        if(sumA < mn)
        {
            ans = {V[begin],V[end]};
            mn = sumA;
        }
        if(sum <= 0)
        {
            begin++;
        }
        if(sum>0)
        {
            end--;
        }
    }
    cout << ans.first << " " << ans.second;
}
